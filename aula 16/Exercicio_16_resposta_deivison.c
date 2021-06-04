/*Aluno: Deivison rodrigues jordao
 *Professor: Yuri Malheiros
 *Programaçao estrurada
 */

#include <stdio.h>
#include <string.h>

int main(void){
    char Maior_palavra[60] = {0}; // palavras ficam limitadas a 59 caracteres
    char Aux_palavra[60];

    while(strcmp(Aux_palavra,"fim") != 0){
        printf("digite uma palavra: ");
        scanf("%s",Aux_palavra);

        if(strlen(Aux_palavra) > strlen(Maior_palavra)){
            strcpy(Maior_palavra,Aux_palavra);
        }
    }
    printf("A palavra com maoir número de caracteres é %s",Maior_palavra);
    return 0;
}