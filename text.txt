Les fonctions defines en matiere de traitement de fichiers:
    ouverture de fichier: fopen()
    fermeture de fichier: fclose()
    lecture dans un fichier: fgetc, fgets, fread, fscanf
    ecriture dans un fichier: fputc, fputs, fwrite, fprintf
    deplacement dans un fichier: fseek, rewind

Syntaxe d'ouverture d'un fichier:
    FILE *fopen(char  *NomFichier, char *mode)

Les modes:
    r : lecture
    w : ecriture
    a : ecriture
    r+: lecture/ecriture
    w+: lecture/ecriture
    a+: lecture/ecriture