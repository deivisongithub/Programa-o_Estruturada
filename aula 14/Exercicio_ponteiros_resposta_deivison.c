/*Aluno: Deivison rodrigues jordao
 *Professor: Yuri Malheiros
 *Programaçao estrurada
 */

#include <stdio.h>

void max_min(int array[],int tamanho_do_array,int *maior,int *menor);

int main(void){
    int Maior,Menor;
    int teste[] = {1,2,3,4,0,5,6,100,7,8,9,10};
    max_min(teste,sizeof(teste)/sizeof(teste[0]),&Maior,&Menor);
    printf("maior é %d e o menor é %d",Maior,Menor);
    printf("\nPara testar com novos valores modifique o array teste no código");
    return 0;
}

void max_min(int array[],int tamanho_do_array,int *maior,int *menor){
    *maior = array[0];
    *menor = array[0];
    for(int i = 0;i < tamanho_do_array;i++){
        if(*maior < array[i]){
            *maior = array[i];
        }
    }
    for(int i = 0;i < tamanho_do_array;i++){
        if(*menor > array[i]){
            *menor = array[i];
        }
    }
}