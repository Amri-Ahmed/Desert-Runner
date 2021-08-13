prog:main.o perso.o utilitaire.o 
	gcc main.o perso.o utilitaire.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c 
	gcc -c main.c -g
perso.o:perso.c
	gcc -c perso.c -g 
utilitaire.o:utilitaire.c
	gcc -c utilitaire.c -g
