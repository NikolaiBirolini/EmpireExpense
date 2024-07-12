cflags=-Wall -Wextra -std=c99 -pedantic -g -pg -no-pie
jfiles=jeu/initWorld.c jeu/graphic_widget/dropDown.c jeu/graphic_widget/gauge.c jeu/graphic_widget/menuSelector.c jeu/graphic_widget/pictureButton.c jeu/graphic_widget/textInfo.c jeu/graphic_widget/textBox.c jeu/graphic_widget/button.c jeu/display.c jeu/arg_parse.c jeu/net.c jeu/gui/gui.c jeu/perso.c jeu/init_sprite.c jeu/gui/init_gui.c jeu/select_sprite.c jeu/clavier.c jeu/control.c jeu/parseur.c jeu/ordre.c jeu/ia.c jeu/map.c jeu/linked_char.c jeu/inventory/parse_equipement.c jeu/chiffrement.c jeu/inventory/linked_item.c jeu/diplo.c jeu/pathfinding.c jeu/init_sound.c jeu/btree.c jeu/shared_var.c jeu/linked_display.c 
sfiles=serv/perso.c serv/map_op.c serv/req.c serv/utile.c serv/deschiffrement.c serv/net.c serv/diplo.c serv/inventaire.c serv/demographie.c serv/acount.c serv/file.c serv/shared_var.c serv/collision.c
efiles=editmap/init_img.c editmap/select_sprite.c
Efiles=editmap2/ground.c editmap2/shared_var.c editmap2/init_sprite.c editmap2/clavier.c editmap2/control.c
EfilesinJfiles=jeu/init_sprite.c jeu/clavier.c jeu/clavier.h jeu/init_sprite.h

all: j s E

j:
	gcc ${cflags} jeu/main.c $(jfiles) -o empireExpense -lSDL2 -lm -lSDL2_mixer -lSDL2_ttf -lSDL2_image

s:
	gcc serv/main.c -g $(sfiles) -lpthread -o serveur

static:
	gcc ${cflags} jeu/main.c $(jfiles) -o empireExpense `sdl2-config --cflags --static-libs` `sdl2_mixer-config --cflags --static-libs` 

e:
	gcc $(cflags) editmap/main.c $(efiles) -o mapEditor -lSDL2 -lm

E:	
	cp $(EfilesinJfiles) editmap2/ 

	gcc $(cflags) editmap2/main.c $(Efiles) -o mapEditor -lSDL2 -lm

clean:
	rm -f empireExpense serveur mapEditor
