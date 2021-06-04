/*Aluno: Deivison rodrigues jordao
 *Professor: Yuri Malheiros
 *Programaçao estrurada
 */
#include <stdio.h>
int main(void){
    char frase;
    int contagem = 1;
    printf("Digite sua frase: ");
    frase = getchar();
    
    while(frase != '\n'){
        if(frase == ' '){
            contagem++;
        }
        frase = getchar();
    }
    printf("Quantidade de palavras: %d",contagem);
    return 0;
}