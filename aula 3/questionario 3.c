/*Aluno: Deivison rodrigues jordao
 *Professor: Yuri Malheiros
 *Espero que o senhor tenha gostado :D
 */

#include <stdio.h>

int main(void){
    int x;
    int contrario;
    printf("Digite um numero inteiro de dois digitos: ");
    scanf("%d",&x);
    contrario = ((x%10)*10)+(x/10);
    printf("%d",contrario);
    return 0;
}