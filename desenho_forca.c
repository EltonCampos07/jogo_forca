#include <stdio.h>
#include <stdlib.h>

void desenho (int cont){
    int i;

    switch (cont){
    case 0:
        printf(" ---------\n");
        printf(" | \t |\n");
        for(i=0; i<4; i++){
            printf (" |\n");
        }
        break;
    case 1:
        printf(" ---------\n");
        printf(" | \t |\n");
        printf (" |");
        printf (" \t O\n");
        for(i=0; i<3; i++){
            printf (" |\n");
        }
        break;
    case 2:
        printf(" ---------\n");
        printf(" | \t |\n");
        printf (" |");
        printf (" \t O\n");
        printf (" |");
        printf ("      /\n");
        for(i=0; i<2; i++){
            printf (" |\n");
        }
        break;
    case 3:
        printf(" ---------\n");
        printf(" | \t |\n");
        printf (" |");
        printf (" \t O\n");
        printf (" |");
        printf ("      /|\n");
        for(i=0; i<2; i++){
            printf (" |\n");
        }
        break;
    case 4:
        printf(" ---------\n");
        printf(" | \t |\n");
        printf (" |");
        printf (" \t O\n");
        printf (" |");
        printf ("      /|\\\n");
        for(i=0; i<2; i++){
            printf (" |\n");
        }
        break;
    case 5:
        printf(" ---------\n");
        printf(" | \t |\n");
        printf (" |");
        printf (" \t O\n");
        printf (" |");
        printf ("      /|\\\n");
        printf (" |");
        printf ("      /\n");
        printf (" |");
        break;
    case 6:
        printf(" ---------\n");
        printf(" | \t |\n");
        printf (" |");
        printf (" \t O\n");
        printf (" |");
        printf ("      /|\\\n");
        printf (" |");
        printf ("      / \\\n");
        printf (" |");
        break;
    }
}