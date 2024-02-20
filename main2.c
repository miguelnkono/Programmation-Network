#include <stdio.h>

#define MAXCARAT        80

int pos(char *, int);
int main(int, char  *[]);

int main(int argc, char *argv[])
{
    char tampon[MAXCARAT + 1];
    int colones;
    FILE *f_in;

    if(argc != 3)
    {
        fprintf(stderr, "ERREUR: Appel: %s Nombre de \n", argv[1]);
        return 1;
    }

    if ( (colones = atoi(argv[1])) == 0)
    {
        colones = MAXCARAT;
    }
    else if(colones > MAXCARAT || colones < 0)
    {
        colones = MAXCARAT;
    }
    if( (f_in = fopen(argv[2], "r")) ==NULL)
    {
        fprintf(stderr, "ERREUR: Ouverture de %s\n", argv[2]);
        return 2;
    }

    while(fgets(tampon, colones+1, f_in) != (char *)0)
    {
        fputs(tampon, stdout);
        if(pos(tampon, '\n') == -1)
        {
            while(fgetc(f_in) != '\n');
            putchar('\n');
        } 
    }

    return 0;
}

int pos(char *vk, int caractere)
{
    char *debut = vk;

    while(*vk)
    {
        if (*vk == caractere)
        {
            return vk - debut;
        }
        vk++;
    }
    return -1;
}