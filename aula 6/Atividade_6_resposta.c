/*Aluno: Deivison rodrigues jordao
 *Professor: Yuri Malheiros
 *Programaçao estrurada
 *Espero que o senhor goste :D
 */

#include <stdio.h>

int main(void){
    int numero,maior,contador=0;

    do{
        contador += 1;
        printf("Digite um numero: ");
        scanf("%d",&numero);
        if(contador == 1){
            maior = numero;
        }
        else{
            if(numero > maior){
                maior = numero;
            }
        }

    }while(numero != 0);
    printf("O maior numero e %d",maior);
    
    return 0;
}