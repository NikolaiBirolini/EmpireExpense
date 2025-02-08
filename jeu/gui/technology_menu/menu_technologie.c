#include "menu_technologie.h"

int find_node_index(char *id)
{
    for (int i = 0; i < main_menu->menuTech->cnt; i++)
        if (strncmp(id,main_menu->menuTech->techTree[i].txtid, 3) == 0)
            return i;
    return -1;
} 


void unlock_tallent_of_civ_member(struct personnages *p)
{
	int this_leader = id_of_maximal_leader(p);
	for (struct linked_list *pa = list; pa != NULL; pa = pa->next)
	{
		if (id_of_maximal_leader(pa->p) == this_leader && p1_or_rec_leader_of_p1_is_enemi_of_p2(p, pa->p) == 0)
		{
			int i = 0;
			while (i < 62*3 && pa->p->skill[i] != 0)
			{
				main_menu->menuTech->techTree[find_node_index(pa->p->skill + i)].unlocked = 1;
                i += 3;
			}
		}
	}
}

void append_node(char *txt, int x, int y, int req1, int req2, int req3)
{
    hard_initTextInfo(&main_menu->menuTech->techTree[main_menu->menuTech->cnt].text, txt+4, littleFont,x,y,0,(SDL_Color){0, 0, 0, 255},0,0,0);
    main_menu->menuTech->techTree[main_menu->menuTech->cnt].txtid[0] = txt[0];
    main_menu->menuTech->techTree[main_menu->menuTech->cnt].txtid[1] = txt[1];
    main_menu->menuTech->techTree[main_menu->menuTech->cnt].txtid[2] = txt[2];
    main_menu->menuTech->techTree[main_menu->menuTech->cnt].unlocked = 0;
    main_menu->menuTech->techTree[main_menu->menuTech->cnt].requierement1_index = req1;
    main_menu->menuTech->techTree[main_menu->menuTech->cnt].requierement2_index = req2;
    main_menu->menuTech->techTree[main_menu->menuTech->cnt].requierement3_index = req3;
    
    main_menu->menuTech->cnt += 1;
}

void display_tree(void)
{
    for (int i = 0; i < main_menu->menuTech->cnt; i++)
    {
        SDL_Rect dstRect = main_menu->menuTech->techTree[i].text.dstRect;
        dstRect.x += main_menu->menuTech->x_offset;
        dstRect.y += main_menu->menuTech->y_offset;
        if (lettres->Mouse_pos_x >= dstRect.x && lettres->Mouse_pos_x <= dstRect.x + dstRect.w && lettres->Mouse_pos_y >= dstRect.y && lettres->Mouse_pos_y <= dstRect.y + dstRect.h)
        {
            SDL_SetRenderDrawColor(renderer, 255,0,0,0);
            SDL_RenderFillRect(renderer, &dstRect);
            SDL_RenderCopy(renderer, main_menu->menuTech->techTree[i].text.texture, NULL, &dstRect);
            if (main_menu->menuTech->techTree[i].requierement1_index >= 0)
            {
                SDL_Rect dstRect2 = main_menu->menuTech->techTree[main_menu->menuTech->techTree[i].requierement1_index].text.dstRect;
                SDL_RenderDrawLine(renderer, dstRect.x, dstRect.y + dstRect.h/2, dstRect2.x + dstRect2.w + main_menu->menuTech->x_offset ,dstRect2.y + dstRect2.h/2  + main_menu->menuTech->y_offset);
            }
            if (main_menu->menuTech->techTree[i].requierement2_index >= 0)
            {
                SDL_Rect dstRect2 = main_menu->menuTech->techTree[main_menu->menuTech->techTree[i].requierement2_index].text.dstRect;
                SDL_RenderDrawLine(renderer, dstRect.x, dstRect.y + dstRect.h/2, dstRect2.x + dstRect2.w + main_menu->menuTech->x_offset ,dstRect2.y + dstRect2.h/2  + main_menu->menuTech->y_offset);
            }
            if (main_menu->menuTech->techTree[i].requierement3_index >= 0)
            {
                SDL_Rect dstRect2 = main_menu->menuTech->techTree[main_menu->menuTech->techTree[i].requierement3_index].text.dstRect;
                SDL_RenderDrawLine(renderer, dstRect.x, dstRect.y + dstRect.h/2, dstRect2.x + dstRect2.w + main_menu->menuTech->x_offset ,dstRect2.y + dstRect2.h/2  + main_menu->menuTech->y_offset);
            }
        }
        else 
        {
            if (main_menu->menuTech->techTree[i].unlocked == 1)
                SDL_SetRenderDrawColor(renderer, 0, 255,0,0);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0,255,0);
            SDL_RenderFillRect(renderer, &dstRect);
            SDL_RenderCopy(renderer, main_menu->menuTech->techTree[i].text.texture, NULL, &dstRect);
            SDL_SetRenderDrawColor(renderer, 255, 255,255,0);
            if (main_menu->menuTech->techTree[i].requierement1_index >= 0)
            {
                SDL_Rect dstRect2 = main_menu->menuTech->techTree[main_menu->menuTech->techTree[i].requierement1_index].text.dstRect;
                SDL_RenderDrawLine(renderer, dstRect.x, dstRect.y + dstRect.h/2, dstRect2.x + dstRect2.w + main_menu->menuTech->x_offset ,dstRect2.y + dstRect2.h/2  + main_menu->menuTech->y_offset);
            }
            if (main_menu->menuTech->techTree[i].requierement2_index >= 0)
            {
                SDL_Rect dstRect2 = main_menu->menuTech->techTree[main_menu->menuTech->techTree[i].requierement2_index].text.dstRect;
                SDL_RenderDrawLine(renderer, dstRect.x, dstRect.y + dstRect.h/2, dstRect2.x + dstRect2.w + main_menu->menuTech->x_offset ,dstRect2.y + dstRect2.h/2  + main_menu->menuTech->y_offset);
            }
            if (main_menu->menuTech->techTree[i].requierement3_index >= 0)
            {
                SDL_Rect dstRect2 = main_menu->menuTech->techTree[main_menu->menuTech->techTree[i].requierement3_index].text.dstRect;
                SDL_RenderDrawLine(renderer, dstRect.x, dstRect.y + dstRect.h/2, dstRect2.x + dstRect2.w + main_menu->menuTech->x_offset ,dstRect2.y + dstRect2.h/2  + main_menu->menuTech->y_offset);
            }
        }

    }
}


void menu_technologie()
{

    unlock_tallent_of_civ_member(moi);
    display_tree();
    if (lettres->keystates[SDL_SCANCODE_ESCAPE])
        main_menu->menuTech->on = 0;
    if(lettres->keystates[SDL_SCANCODE_S])
        main_menu->menuTech->y_offset -= 10;
    if(lettres->keystates[SDL_SCANCODE_D])
        main_menu->menuTech->x_offset -= 10;
    if(lettres->keystates[SDL_SCANCODE_W])
        main_menu->menuTech->y_offset += 10;
    if(lettres->keystates[SDL_SCANCODE_A])
        main_menu->menuTech->x_offset += 10;
}

void init_tech_menu()
{
    main_menu->menuTech->on = 0;
    main_menu->menuTech->cnt = 0;
    main_menu->menuTech->x_offset = 0;
    main_menu->menuTech->y_offset = 0;
    append_node("001 wood sculpture", 0, 400, -1,-1,-1);

    append_node("002 bronze forging",400,400, 0,-1,-1);
    append_node("003 iron forging",  800, 400, 1,-1,-1);
    append_node("004 steel forging", 1200, 400, 2,-1,-1);


    append_node("005 wood bow", 400, 0,0,35,-1);
    append_node("006 composite bow", 800, 0,-1,4,-1);
    append_node("007 long bow", 1200, 0,-1,5,-1);
    append_node("008 crossbow", 1200, 50,-1,5,-1);
    
    append_node("009 iron arrow head", 1200, 100,2,-1,-1);
    append_node("010 steel arrow head", 1600, 100,3,-1,-1);

    append_node("011 sling",  400, 150,0,-1,-1);
    append_node("012 wood javelin",  400, 200,0,-1,-1);
    append_node("013 bronze javelin",  800, 200,1,11,-1);


    append_node("014 wood spear",  400, 450,0,-1,-1);
    append_node("015 bronze spear", 800, 450,1,13,-1);
    append_node("016 iron spear", 1200, 450,2,14,-1);
    append_node("017 steel spear", 1600, 450,3,15,-1);

    append_node("018 bronze sword", 800, 600,1,13,-1);
    append_node("019 iron sword", 1200, 600,2,17,-1);
    append_node("020 steel sword", 1600,600,3,18,-1);

    append_node("021 wood club", 400, 550,0,-1,-1);
    append_node("022 bronze club", 800, 550,1,20,-1);
    append_node("023 iron mace", 1200, 550,2,21,-1);
    append_node("024 steel warhammer", 1600, 550,3,22,-1);
 
    append_node("025 iron halebarde", 1600, 500,15,-1,-1);
    append_node("026 steel halebarde", 2000, 500,24,-1,-1);

    append_node("027 bronze sickles",  800, 700,1,-1,-1);
    append_node("028 iron war axe",  1200, 700,2,26,-1);
    append_node("029 steel long war axe",  1600, 700,3,27,-1);


    append_node("030 iron long sword",  1600, 650,2,18,-1);
    append_node("031 steel long sowrd",  2000, 650,29,-1,-1);

    append_node("032 greek fire",  0, 350,-1,-1,-1);
    append_node("033 gun powder",  400, 350,31,-1,-1);
    append_node("034 nitrocellulose powder",  1200, 350,105,-1,-1);

    append_node("035 hand canon ",  800, 300,32,0,-1);

    append_node("036 rope braiding",  0, -0,-1,-1,-1);
    append_node("037 large rope",  400, -50,35,-1,-1);
    append_node("038 whip",  800, -50,36,-1,-1);
    append_node("039 whip chain",  1200, -50,37,2,-1);
    append_node("040 urumi sword",  1600, -50,38,3,-1);

    append_node("041 balist",  1200, 150,36,4,-1);
    append_node("042 arquebuse",  1200, 250,34,2,-1);
    
    append_node("043 wool sewing",  0, 1150,-1,-1,-1);
    append_node("044 linen sewing",  400, 1200,42,-1,-1);
    append_node("045 cotton sewing",  400, 1150,42,-1,-1);
    append_node("046 silk sewing",  800, 1200,43,-1,-1);
    append_node("047 tanning leather",  800, 1150,44,-1,-1); 

    append_node("048 primitive clothes",  400, 1250,42,-1,-1);
    append_node("049 usefull clothes",  800, 1250,44,47,-1);
    append_node("050 ceremonial clothes",  800, 1300,43,47,-1);
    append_node("051 imperial clothes",  1200, 1300,45,49,-1);
    append_node("052 robust clothes",  1200, 1250,46,48,-1);

    append_node("053 wood shield",  400, 1000,0,-1,-1);
    append_node("054 bronze shield",  800, 1000,1,52,-1);
    append_node("055 iron shield",  1200, 1000,2,53,-1);
    append_node("056 steel shield",  1600, 1000,3,54,-1);

    append_node("057 wood helmet",  400, 950,0,-1,-1);
    append_node("058 bronze helmet",  800, 950,1,56,-1);
    append_node("059 iron helmet",  1200, 950,2,57,-1);
    append_node("060 steel helmet",  1600, 950,3,58,-1);
    
    append_node("061 bronze armor",  800, 1050,1,47,-1);
    append_node("062 iron armor",  1200, 1050,2,60,-1);
    append_node("063 steel armor",  1600, 1050,3,58,-1);

    append_node("064 bronze chainmail armor",  1200, 1100,-1,60,-1);
    append_node("065 iron chainmail armor",  1600, 1100,2,63,-1);
    append_node("066 steel chainmail armor",  2000, 1100,3,64,-1);

    append_node("067 steel chainmail armor",  2000, 1100,3,64,-1);

    append_node("068 clogs shoes",  800, 750,47,0,-1); 
    append_node("069 inner sole",  1200, 750,67,46,-1);
    append_node("070 fixing rope",  1600, 750,35,68,-1);

    append_node("071 moccassin shoes",  1200, 800,49,-1,-1);
    append_node("072 inner sole",  1600, 800,46,70,-1);
    append_node("073 laces",  2000, 800,35,71,-1);

    append_node("074 sandals",  1200, 850,46,-1,-1); 
    append_node("075 sole with studs",  1600, 850,73,-1,-1);
    append_node("076 fixing rope",  2000, 850,35,74,-1);

    append_node("077 boots",  1200, 900,46,-1,-1);
    append_node("078 sole with studs",  1600, 900,76,-1,-1);
    append_node("079 laces",  2000, 900,35,77,-1);

    append_node("080 polybolos", 1600, 150, 40, 2, -1);
    append_node("081 catapulte", 2000, 150, 79, -1, -1);
    append_node("082 onagre", 2400, 150, 80, -1, -1);
    append_node("083 mangonneau", 2800, 150, 81, -1, -1);
    append_node("084 trebuchet", 3200, 150, 82, -1, -1);

    append_node("085 silex arquebuse",  1600, 250,41,-1,-1);
    append_node("086 silex revolver",  2000, 200,84,-1,-1);
    append_node("087 silex rifle",  2000, 250,84,-1,-1);
    append_node("088 percusion rifle",  2400, 250,86,-1,-1);
    append_node("089 percusion revolver",  2400, 200,85,-1,-1);
    append_node("090 lock rifle",  2800, 250,87,-1,-1);
    append_node("091 lock revolver",  2800, 200,88,-1,-1);
    append_node("092 repetition rifle",  3200, 250,89,33,3);
    append_node("093 repetition revolver",  3200, 200,90,33,3);

    append_node("094 bombarde",  1200, 300,34,2,-1);
    append_node("095 mortar",  1600, 400,93,-1,-1);
    append_node("096 howitzer",  2000, 400,94,3,-1);    
    append_node("097 culevrin",  1600, 350,93,-1,-1);
    append_node("098 ribauldquin",  2000, 350,96,-1,-1);
    append_node("099 mitrailleuse",  3600, 350,97,92,91);
    append_node("100 saker",  1600, 300,93,-1,-1);
    append_node("101 field artillery",  2000, 300,99,-1,-1);
    append_node("102 12 pounder long gun",  2400, 300,100,-1,-1);
    append_node("103 24 pounder long gun",  3000, 300,101,-1,-1);

    append_node("104 wood architecture",  400, -350,0,-1,-1);
    append_node("105 stone architecture",  800, -350,103,-1,-1);
    append_node("106 steam engine",  800, 350,32,-1,-1);

    append_node("107 canoe",  800, -150,103,35,-1);
    append_node("108 row boat",  1200, -150,106,36,-1);
    append_node("109 galley",  1600, -150,107,-1,-1);
    append_node("110 galley with sails",  2000, -150,108,43,-1);
    append_node("111 galley with keel",  2400, -150,109,-1,-1);
    append_node("112 longboat",  2400, -200,109,-1,-1);

    append_node("113 sailboat",  1600, -250,107,43,-1);
    append_node("114 2 mast",  2000, -250,112,-1,-1);
    append_node("115 sailboat with keel",  2400, -250,113,-1,-1);
    append_node("116 caravel",  2800, -250,114,-1,-1);
    append_node("117 fluyt",  3200, -300,115,-1,-1);
    append_node("118 galion",  3200, -250,115,-1,-1);
    append_node("119 fregate",  3600, -250,117,-1,-1);
    append_node("120 paddle streamer",  2000, -100,108,105,-1);
    append_node("121 battleship",  2400, -100,119,003,-1);

    append_node("122 5-10m height",  800, -400,103,-1,-1);
    append_node("123 5-10m height",  1200, -350,104,-1,-1);
    append_node("124 10-15m height",  1200, -400,121,-1,-1);
    append_node("125 10-15m height",  1600, -350,122,-1,-1);
    append_node("126 15-20m height",  1600, -400,123,-1,-1);
    append_node("127 15-20m height",  2000, -350,124,-1,-1);
    append_node("128 20-25m height",  2000, -400,125,-1,-1);
    append_node("129 20-25m height",  2400, -350,126,-1,-1);

    append_node("130 stone pickaxe",  400, -450,0,-1,-1);
    append_node("131 bronze pickaxe",  800, -450,1,129,-1);
    append_node("132 iron pickaxe",  1200, -450,2,130,-1);
    append_node("133 steel pickaxe",  1600, -450,3,131,-1);


}

uint8_t strcmp_space (const char *p1, const char *p2)
{
    int i = 0;
    while (p1[i] != 0 && p1[i] !=  ' ')
    {
        if (p1[i] != p2[i])
            return 1;
        i += 1;
    }
    return 0;
} 