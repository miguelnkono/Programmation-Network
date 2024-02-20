#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    int caractere;
    FILE *f_in, *f_out;
    char n_source[10], n_destination[10];

    printf("Entrez le nom du fichier source et la nom du fichier de destination: ");
    scanf("%s %s", n_source, n_destination);

    /*if(argc !=3)
    {
        fprintf(stderr, "ERREUR: Appel: %s entree sortie\n", argv[0]);
        return 1;
    }*/
    printf("source: %s\ndestination: %s\n", n_source, n_destination);

    f_in = fopen(n_source, "r");
    f_out = fopen(n_destination, "w");
    if(f_in == NULL || f_out == NULL)
    {
        fprintf(stderr, "ERREUR: ouverture du fichier\n");
        return 2;
    }

    while ( (caractere = fgetc(f_in)) != EOF)
    {
        if (fputc(caractere, f_out) == EOF)
        {
            fprintf(stderr, "ERREUR: Ecriture dans %s\n", n_destination);
            return 3;
        }
    }

    if (fclose(f_in ) == EOF || (fclose(f_out) ) == EOF)
    {
        fprintf(stderr, "ERREUR: Fermeture du fichier\n");
        return 4;
    }

    return 0;
}