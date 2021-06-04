/*Aluno: Deivison rodrigues jordao
 *Professor: Yuri Malheiros
 *Este foi meu primeiro codigo em C,espero que o senhor tenha gostado :D
 */
#include <stdio.h>
int main(void){
    float valor_usuario;
    printf("Digite um valor em Fharenheit: ");
    scanf("%f",&valor_usuario);
    float resultado = (valor_usuario-32)*5/9;
    printf("%.2f Fharenheit e equivalente a %.2f Celsius",valor_usuario,resultado);
    return 0;
}