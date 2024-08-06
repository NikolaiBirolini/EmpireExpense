CFLAGS = -Wall -Wextra -std=c99 -g -pg -no-pie -Werror

jfiles = $(filter-out jeu/main.c, $(shell find jeu -name "*.c"))
sfiles = $(filter-out serv/main.c, $(shell find serv -name "*.c"))

jobjects = $(filter-out jeu/main.c, $(jfiles:.c=.o))
sobjects = $(filter-out serv/main.c, $(sfiles:.c=.o))

#efiles = \
#    editmap/init_img.c \
#    editmap/select_sprite.c
#
#Efiles = \
#    editmap2/ground.c \
#    editmap2/shared_var.c \
#    editmap2/init_sprite.c \
#    editmap2/clavier.c \
#    editmap2/control.c
#
#EfilesinJfiles = \
#    jeu/init_sprite.c \
#    jeu/clavier.c \
#    jeu/clavier.h \
#    jeu/init_sprite.h
# Add E for mapEditor

all: j s 

serv/%.o: serv/%.c
	gcc $(CFLAGS) -c $< -o $@

jeu/%.o: jeu/%.c
	gcc $(CFLAGS) -c $< -o $@

j: $(jobjects)
	gcc $(CFLAGS) jeu/main.c $(jobjects) -o empireExpense -lSDL2 -lm -lSDL2_mixer -lSDL2_ttf -lSDL2_image

s: $(sobjects) serv/main.o
	gcc $(CFLAGS) $(sobjects) serv/main.o -lpthread -o serveur

#static:
#	gcc $(CFLAGS) jeu/main.c $(jfiles) -o empireExpense `sdl2-config --cflags --static-libs` `sdl2_mixer-config --cflags --static-libs`
#
#e:
#	gcc $(CFLAGS) editmap/main.c $(efiles) -o mapEditor -lSDL2 -lm
#
#E: copy_files
#	gcc $(CFLAGS) editmap2/main.c $(Efiles) -o mapEditor -lSDL2 -lm
#
#copy_files:
#	cp $(EfilesinJfiles) editmap2/
#
# Add editor map clean

clean:
	rm -f $(jobjects) $(sobjects) empireExpense serveur 

# Add editormap command and copy files one.
.PHONY: all j s clean 
