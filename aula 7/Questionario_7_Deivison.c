/*Aluno: Deivison rodrigues jordao
 *Professor: Yuri Malheiros
 *Programaçao estrurada
 *Espero que o senhor goste :D
 */

#include <stdio.h>

int main(void){
    float resultado = 1,n,fat,regulador;
    printf("digite um numero: ");
    scanf("%f", &regulador);
    for (;regulador > 0;regulador--){
        n = regulador;
        for(fat = 1; n > 1; n = n - 1){
            fat = fat * n;
        }
        resultado += 1/fat;
    }
    printf("%f",resultado);
    return 0;
}