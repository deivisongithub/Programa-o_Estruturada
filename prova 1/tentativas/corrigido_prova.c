/*** ALUNO: MOISES FILIPE COUTINHO CORREIA SANTOS - 20200025689
 *   
 *   OBS: O eixo X so aceita numeros inteiros ***/

#include <stdio.h>
#include <stdlib.h>
void barras_verticais(int *a, int *b,int size);
void barras_horizontais(int *a, int *b,int size);
int contador_digitos(int numero);
int compare(const void * a, const void * b){
  if ( *(int*)a <  *(int*)b ) return -1;
  if ( *(int*)a == *(int*)b ) return 0;
  if ( *(int*)a >  *(int*)b ) return 1;
}

int main(void){
    int y_values[] = {12,13,19,15,23,22};
    int x_values[] = {201700000,20200000,202100000,201900000000,20000000,200998765};
    printf("Com estes valores, temo um um bom resultado: \n");
    barras_verticais(x_values,y_values,(int)sizeof(x_values)/sizeof(*x_values));
    barras_horizontais(x_values,y_values,(int)sizeof(x_values)/sizeof(*x_values));
    printf("Porem, com estes, a representacao das barras horizontais buga: \n");
    barras_verticais(y_values,x_values,(int)sizeof(x_values)/sizeof(*x_values));
    barras_horizontais(y_values,x_values,(int)sizeof(x_values)/sizeof(*x_values));
    printf("Isto acontece pois o numero de espacos necessarios eh MENOR quando os valores do eixo Y CRESCE\n");
    printf("O seu trabalho e corrigir este bug, para que independente dos valores de Y terem 1~4 digitos, a representacao de barras horizontais permaneca funcionando! Boa sorte.\n");
    return 0;
}

// Funcao que printa o grafico de barras verticais. Tudo pronto, nao precisa mudar nada.
void barras_verticais(int x_vals[], int y_vals[],int size){
    // gera uma copia ordenada de y_vals
    int y_sorted[size];
    for (int h = 0; h < size;h++){
        y_sorted[h] = y_vals[h];
    }    
    qsort(y_sorted,size,sizeof(*y_vals),compare);

    // printa as colunas
    for (int i = size-1; i > -1; i--){
        printf("%d|\t", y_sorted[i]); // printa a legenda vertical/valor de y
        for (int j = 0; j < size; j++){
            /*** percorre por todos os valores de y_vals, se y_vals[j] for maior ou igual ao i-esimo maior valor de y_sorted,
             printa na coluna e passa para a proxima, caso contrario, nao printa nada e passa para proxima ***/
            if (y_vals[j] >= y_sorted[i]){
                printf("█\t");
            }
            else{
                printf("\t");
            }
        }
        printf("\n");
    }
    // printa a legenda das abscissas
    printf("\t");
    for (int k = 0; k <size; k++){
        printf("%d\t",x_vals[k]);
    }
    printf("\n");
}

void barras_horizontais(int x_vals[],int y_vals[],int size){
    int y_sorted[size];
    for (int h = 0; h < size;h++){
        y_sorted[h] = y_vals[h];
    }    
    qsort(y_sorted,size,sizeof(*y_vals),compare);

    int contador_digitos(numero){
     int contaDigitos = 0, valor = numero;
     do{
         contaDigitos = contaDigitos + 1;
         valor = valor / 10;
     }
     while (valor != 0);
     return contaDigitos;
    }

    int contagem_x[size];
    for(int o = 0;o < size;o++){
        contagem_x[o] = contador_digitos(x_vals[o]);
    }
    int contagem_y[size];
    for(int o = 0;o < size;o++){
        contagem_y[o] = contador_digitos(y_vals[o]);
    }
    int contagem_espaco;

    int flag = 0;
    for(int i = 0; i < size; i++){
        if(y_vals[i] > 99){
            flag++;
        }
    }

    if(flag != 0){
        for (int a = 0;a < size;a++){
            printf("%d|",x_vals[a]);
            contagem_espaco = 10 - (contagem_x[a] + 1) + (contagem_y[a]/2) + ((4 + contagem_y[a])*a);
                for (int j = 0; j < contagem_espaco; j++){
                    printf("■");
                }
                printf("\n");
        }        

        printf("          ");
        for (int k = 0; k < size; k++){
            printf("%d    ",y_vals[k]);
        }
        printf("\n");
    }
    else{
        for (int i = 0; i < size; i++){
            printf("%d|",x_vals[i]);
            for (int j = 0; j < size; j++){
                if (y_vals[i] >= y_sorted[j]){
                    printf("■■■■■■");
                }
            }
            printf("\n");
        }

        printf("          ");
        for (int k = 0; k < size; k++){
            printf("%d    ",y_sorted[k]);
        }
        printf("\n");
    }
}