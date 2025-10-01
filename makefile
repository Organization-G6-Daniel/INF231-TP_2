compile: main.c tp2.c tp2.h
           gcc -o launche *.c
run: ./launche
clean: 
        rm -rf launche
