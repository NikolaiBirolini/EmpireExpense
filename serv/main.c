#include "main.h"
#include "shared_var.h"

struct personnages *flag = NULL;

static int create_and_bind (char *port)
{
    struct addrinfo hints;
    struct addrinfo *result, *rp;
    int s, sfd;
    memset (&hints, 0, sizeof (struct addrinfo));
    hints.ai_family = AF_UNSPEC;     /* Return IPv4 and IPv6 choices */
    hints.ai_socktype = SOCK_STREAM; /* We want a TCP socket */
    hints.ai_flags = AI_PASSIVE;     /* All interfaces */

    s = getaddrinfo (NULL, port, &hints, &result);
    if (s != 0)
    {   
        fprintf (stderr, "getaddrinfo: %s\n", gai_strerror (s));
        return -1;
    }
    for (rp = result; rp != NULL; rp = rp->ai_next)
    {
        sfd = socket (rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sfd == -1)
            continue;
        s = bind (sfd, rp->ai_addr, rp->ai_addrlen);
        if (s == 0)
            break;
        close (sfd);
    }
    if (rp == NULL)
    {
        fprintf (stderr, "Could not bind\n");
        return -1;
    }
    freeaddrinfo (result);
    return sfd;
}

static int make_socket_non_blocking (int sfd)
{
    int flags, s;
    flags = fcntl (sfd, F_GETFL, 0);
    if (flags == -1)
    {
        perror ("fcntl");
        return -1;
    }
    flags |= O_NONBLOCK;
    s = fcntl (sfd, F_SETFL, flags);
    if (s == -1)
    {
        perror ("fcntl");
        return -1;
    }
    return 0;
}

#define MAXEVENTS 64

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf ("error 1 : serv need a port\n");
		return 1;
	}
	clock_t time = clock();
    float t = (float)(time / CLOCKS_PER_SEC);
    float t2;
	char *ground;
	size_t size_ground = load_file_as_string("ground.txt", &ground);
	create_array(ground);
	list = init_map();
	flag = list;
	while (strcmp(flag->skin, "flag_zone") != 0)
		flag = flag->next;
	list = croissance_pop(list);

	char statut[MAXEVENTS + 5] = {0};
	char c_names[MAXEVENTS + 5][50];
	int afktiming[MAXEVENTS + 5] = {0};

    int sfd, s;
    int efd;
    struct epoll_event event;
    struct epoll_event *events;
	sfd = create_and_bind (argv[1]);
    if (sfd == -1)
        abort ();
    s = make_socket_non_blocking (sfd);
    if (s == -1)
        abort ();
    s = listen (sfd, SOMAXCONN);
    if (s == -1)
    {
        perror ("listen");
        abort ();
    }
    efd = epoll_create1 (0);
    if (efd == -1)
    {
        perror ("epoll_create");
        abort ();
    }
    event.data.fd = sfd;
    event.events = EPOLLIN | EPOLLET;
    s = epoll_ctl (efd, EPOLL_CTL_ADD, sfd, &event);
    if (s == -1)
    {
        perror ("epoll_ctl");
        abort ();
    }

    /* Buffer where events are returned */
    events = calloc (MAXEVENTS, sizeof event);

	char boolrep;
	char buffer[103];
	int save = 0;
	char *order = calloc(10000, 1);
	
	//debout boucle, on suppose que la carte est initialisée.
	while (1)
    {
        int n, i;
        n = epoll_wait (efd, events, MAXEVENTS, 0);
        for (i = 0; i < n; i++)
        {
            if ((events[i].events & EPOLLERR) ||
                    (events[i].events & EPOLLHUP) ||
                    (!(events[i].events & EPOLLIN)))
            {
                /* An error has occured on this fd, or the socket is not
                 * ready for reading (why were we notified then?) */
                fprintf (stderr, "epoll error. events=%u\n", events[i].events);
                close (events[i].data.fd);
				statut[events[i].data.fd] = 0;
				
                continue;
            }

            else if (sfd == events[i].data.fd)
            {
                /* We have a notification on the listening socket, which
                 * means one or more incoming connections. */
                while (1)
                {
                    struct sockaddr in_addr;
                    socklen_t in_len;
                    int infd;
#if 0
                    char hbuf[NI_MAXHOST], sbuf[NI_MAXSERV];
#endif

                    in_len = sizeof in_addr;
                    infd = accept (sfd, &in_addr, &in_len);
                    if (infd == -1)
                    {
                        printf("errno=%d, EAGAIN=%d, EWOULDBLOCK=%d\n", errno, EAGAIN, EWOULDBLOCK);
                        if ((errno == EAGAIN) ||
                                (errno == EWOULDBLOCK))
                        {
                            /* We have processed all incoming
                             * connections. */
                            printf ("processed all incoming connections.\n");
							break;
                        }
                        else
                        {
                            perror ("accept");
                            break;
                        }
                    }


                    /* Make the incoming socket non-blocking and add it to the
                     * list of fds to monitor. */
                    s = make_socket_non_blocking (infd);
                    if (s == -1)
                        abort ();

                    event.data.fd = infd;
                    event.events = EPOLLIN | EPOLLET;
                    printf("set events %u, infd=%d\n", event.events, infd);
                    s = epoll_ctl (efd, EPOLL_CTL_ADD, infd, &event);
                    if (s == -1)
                    {
                        perror ("epoll_ctl");
                        abort ();
                    }
                }
                /*              continue; */
            }
            else
			{
				/* We have data on the fd waiting to be read. Read and
                 * display it. We must read whatever data is available
                 * completely, as we are running in edge-triggered mode
                 * and won't get a notification again for the same
                 * data. */
                int done = 0;

                while (1)
                {
                    ssize_t count;
                    char buf[10000];
                    count = read (events[i].data.fd, buf, sizeof buf);
                    if (count == -1)
                    {
                        /* If errno == EAGAIN, that means we have read all
                         * data. So go back to the main loop. */
                        if (errno != EAGAIN)
                        {
                            perror ("read");
                            done = 1;
                        }
                        break;
                    }
                    else if (count == 0)
                    {
                        /* End of file. The remote has closed the
                         * connection. */
                        done = 1;
                        break;
                    }
                    else
                    {
                        buf[count] = 0;
                        if (statut[events[i].data.fd] == 0)
                        {
							if (open_acount(buf) == 1 && have_char(buf) == 1) // good acount and password
							{
								statut[events[i].data.fd] = 1;
								s = write (events[i].data.fd, "o", 1);
								sprintf(c_names[events[i].data.fd], buf);
                                send_background(events[i].data.fd, ground, size_ground);
                                send_map(events[i].data.fd);
							}
							else
								s = write (events[i].data.fd, "n", 1);
                        }
                        else
						{
							parse_order(buf); 
						}
                    }
				}
                if (done)
                {
                    printf ("Closed connection on descriptor %d\n",
                            events[i].data.fd);

                    /* Closing the descriptor will make epoll remove it
                     * from the set of descriptors which are monitored. */
					statut[events[i].data.fd] = 0;
                    close (events[i].data.fd);
                }
            }
        }
		time = clock();
        t2 = (float)(time / (CLOCKS_PER_SEC / 60));
        if (t2 - t >= 2)
        {
        	t = t2;
            collision();
            int size = generate_order(order);
            for (int i = 4; i < MAXEVENTS + 5;i++)
            	if (statut[i] == 1)
				{
					//printf("%d : [%s %s]\n", i, order, order + 20);
                	send(i, order, size + 20, MSG_NOSIGNAL);
				}
           remove_perso();
		}
    }

    free (events);

    close (sfd);

    return EXIT_SUCCESS;
}