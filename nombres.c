#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *file;
    char number[10];
    char number1[10];
    file = fopen("NOMBRES", "a+");
    if (file == NULL) return 1;

    printf("Entrez des nombres concecutifs: \n");
// isBlank
    while(1) {
        printf("> ");
        scanf("%s", number);
        if(isdigit(number[0])){
            fputs(number, file);
            fputs("\n", file); // Add a newline to separate the numbers
        } else {
            break;
        }
    }
    printf("Fin d'ecriture...\n");
    // Reset file pointer to start of file
    fseek(file, 0, SEEK_SET);
    
    printf("Affichage...\n");
    while(fgets(number1, 10, file) != NULL) {
        printf("%s\n", number1);
    }
    
    if(fclose(file) != 0) return 0;
    return 0;
}
