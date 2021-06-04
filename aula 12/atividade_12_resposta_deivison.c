/*Aluno: Deivison rodrigues jordao
 *Professor: Yuri Malheiros
 *Programaçao estrurada
 */

#include <stdio.h>

// 1. Converter a a função fatorial de recursiva para um laço

//RESPOSTA:

int fatorial(int n) {
    int fat = 1;            //Por ser definido como int a variavel só suporta até o fatorial de 12,acima disso será necessário mudar o tipo.
    for(;n>0;n--){
        fat *= n; 
    }
    return fat;
}

int impressor_de_elementos(int lista[],int tamanho,int n){ // O parametro n é o index inicial
        printf("%d ",lista[n]);                            // O qual, a partir dele será printado todos o maiores que ele.
        if(tamanho - 1 > n){
        impressor_de_elementos(lista,tamanho,n + 1);
        }
}


int main(void){
    int num;
    printf("Digite um numero para ser calculado o fatorial: ");
    scanf("%d",&num);
    printf("O fatorial de %d é %d \n",num,fatorial(num));
    int teste[] = {1,2,3,4,5,6,7,8,9,10};
    printf("resultado da função recursiva de print de arrays: ");
    impressor_de_elementos(teste,sizeof(teste)/sizeof(teste[0]),0);
    printf("\nCaso queira mudar o array representado faça a mudança direto no código");

}

