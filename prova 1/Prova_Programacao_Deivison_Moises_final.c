/*** ALUNO: MOISES FILIPE COUTINHO CORREIA SANTOS   MATRICULA: 20200025689
 *   ALUNO: DEIVISON RODRIGUES JORDÃO               MATRICULA: 20200023728 
 *   OBSERVACOES: 1. O eixo X so aceita numeros inteiros
 *                2. O programa representa cada unidade de medida como uma unidade no grafico. Por isso, para valores suficientemente grandes de Y, a visualizacao sera prejudicada caso nao haja espaco suficiente no terminal.***/

#include <stdio.h>
#include <stdlib.h>
void barras_verticais(int *a, int *b,int size);
void barras_horizontais(int *a, int *b,int size);
int contador_digitos(int numero);
int compare(const void * a, const void * b);

int main(void){
    int y_values[] = {50,10,31,14,53,16};
    int x_values[] = {2002,2003,2004,2005,2006,2008};

    // Assumi-se que os arrays de x e y tem o mesmo tamanho, do contrario, nao seria possivel fazer um grafico. Este tamanho, por sua vez, e passado como parametro para as funcoes de grafico
    barras_verticais(x_values,y_values,(int)sizeof(x_values)/sizeof(*x_values));
    barras_horizontais(x_values,y_values,(int)sizeof(x_values)/sizeof(*x_values));  
    return 0;
}

int contador_digitos(int numero){
     int contaDigitos = 0, valor = numero;
     do{
         contaDigitos = contaDigitos + 1;
         valor = valor / 10;
     }
     while (valor != 0);
     return contaDigitos;
    }

int compare(const void * a, const void * b){
  if ( *(int*)a <  *(int*)b ) return -1;
  if ( *(int*)a == *(int*)b ) return 0;
  if ( *(int*)a >  *(int*)b ) return 1;
    }
// Funcao que printa o grafico de barras verticais. Tudo pronto, nao precisa mudar nada.
void barras_verticais(int x_vals[], int y_vals[],int size){
    // gera uma copia ordenada de y_vals e x_vals
    int y_sorted[size];
    for (int h = 0; h < size;h++){
        y_sorted[h] = y_vals[h];
    }
    int x_sorted[size];
    for (int h = 0; h < size;h++){
        x_sorted[h] = x_vals[h];
    }      
    qsort(y_sorted,size,sizeof(*y_vals),compare);
    qsort(x_sorted,size,sizeof(*x_vals),compare);

    // printa o grafico
    int max_digits_y = contador_digitos(y_sorted[size-1]);
    int max_digits_x = contador_digitos(x_sorted[size-1]);
    for (int i = size-1; i > -1; i--){
        // printa as legendas de Y
        int start = y_sorted[i];
        int end;
        if (i == 0){
            end = 0;
        }
        else{
            end = y_sorted[i-1];
        }

        for (int n = 0; n < start - end;n++){
            if (n == 0){
                printf("%d",y_sorted[i]);
                int digits = contador_digitos(y_sorted[i]);
                if (i != size-1){
                    for (int space = 0; space <= (max_digits_y - digits)-1; space++){
                        printf(" ");
                    }
                }
            }
            else{
                for (int space=0; space < max_digits_y; space++){
                    printf(" ");
                }
            }
            printf("|");
            for (int space = 0; space < max_digits_x+1; space++){
                printf("‾");
            }

            // printa as colunas linha por linha
            for (int j = 0; j < size; j++){
                if (y_vals[j] >= y_sorted[i]){
                    printf("▉");
                    for (int space = 0; space < (max_digits_x+1)*2; space++){
                        printf("‾");
                    }
                }
                else{
                    printf("‾");
                    for (int space = 0; space < (max_digits_x+1)*2; space++){
                        printf("‾");
                    }
                }
            }
            printf("\n");
        }
    }
    // printa a legenda do eixo X
    for (int space = 0; space < max_digits_y+max_digits_x+2; space++){
     printf("‾");
    }
    for (int k = 0; k <size; k++){
        printf("%d",x_vals[k]);
        int digits = contador_digitos(x_vals[k]);
        for (int space = 0; space < ((max_digits_x+1)*2) - (digits-1);space++){
         printf("‾");
        }
    }
    printf("\n");
}

void barras_horizontais(int x_vals[],int y_vals[],int size){
    int y_sorted[size];
    for (int h = 0; h < size;h++){
        y_sorted[h] = y_vals[h];
    }
    int x_sorted[size];
    for (int h = 0; h < size;h++){
        x_sorted[h] = x_vals[h];
    }      
    qsort(y_sorted,size,sizeof(*y_vals),compare);
    qsort(x_sorted,size,sizeof(*x_vals),compare);

    int max_digits_x = contador_digitos(x_sorted[size-1]);

    
    for (int i = 0; i < size; i++){
        //printa as legendas e colunas do eixo X
        printf("%d",x_vals[i]);
        int spaces_to_print = max_digits_x-contador_digitos(x_vals[i]);
        for (int space = 0; space < spaces_to_print; space++){
            printf(" ");
        }
        printf("|");

        for (int j = 0; j < y_vals[i]; j++){
            printf("███");
        }
        printf("\n");
        if (i != size-1){
            printf("\n");
        }
    }

    // printa as legendas do eixo Y
    for (int space= 0; space <= max_digits_x; space++){
        printf("‾");
    }
    for (int k = 0; k < size; k++){
        int sep = 0;
        if (k != 0){
            sep = y_sorted[k-1];
        }
        if (k == 0){
            for (int l = 0; l < ((y_sorted[k]-sep)*3)-1; l++){
                printf("‾");
            }
        }
        else{
            for (int l = 0; l < ((y_sorted[k]-sep)*3)-contador_digitos(y_sorted[k]); l++){
                printf("‾");
            }
        }
        printf("%d",y_sorted[k]);
    }
    printf("\n");
}
