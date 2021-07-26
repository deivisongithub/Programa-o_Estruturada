/*Aluno: Deivison rodrigues jordao
 *Professor: Yuri Malheiros
 *Programaçao estrurada
 */

#include <stdio.h>
#include <stdlib.h>

int *range(int inicio, int fim, int passo);

int main(void){
    int start,end,add;
    printf("Digite o número de inicio: ");
    scanf("%d",&start);
    printf("Digite o número final: ");
    scanf("%d",&end);
    printf("Digite o número de passo: ");
    scanf("%d",&add);
    range(start,end,add);
    return 0;
}

int *range(int inicio, int fim, int passo){
    float tamanho_float = (fim - inicio)/passo;
    int auxliar = (fim - inicio)/passo;
    float verificador = tamanho_float - auxliar;
    int tamanho;
    if (verificador > 0){
        tamanho = (fim - inicio)/passo + 1;
    }
    else{
        tamanho = (fim - inicio)/passo;
    }
    int *matriz = malloc(tamanho * sizeof(int));
    if (matriz == NULL) {
        printf("Erro: falha no malloc\n");
        exit(1);
    }
    matriz[0] = inicio;
    for(int i=1;i <= tamanho;i++){
        if(matriz[i-1] + passo < fim){
            matriz[i] = matriz[i-1] + passo;
        }
        else{
            break;
        }
    }
    printf("O array de %d resultante é ",tamanho);
    for(int i=0;i <= tamanho ;i++){
        printf("%d ",matriz[i]);
    }
}