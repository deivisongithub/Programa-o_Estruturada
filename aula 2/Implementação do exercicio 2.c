/*Aluno: Deivison rodrigues jordao
 *Professor: Yuri Malheiros
 *Espero que o senhor tenha gostado :D
 */

#include <stdio.h>

int main(void){

    float dividendo1,divisor1,dividendo2,divisor2;
    float resultado;
    printf("digite uma fracao: ");
    scanf("%f/%f",&dividendo1,&divisor1);
    printf("digite outra fracao: ");
    scanf("%f/%f",&dividendo2,&divisor2);
    resultado = dividendo1/divisor1+dividendo2/divisor2;
    printf("O resultado da soma das fracoes digitadas e %.2f",resultado);

    return 0;
}