// ALUNO: DEIVISON RODRIGUES JORDÃO               MATRICULA: 20200023728 //

#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
#include <math.h>

// Funções para criação de matrizes

//Matrix
struct matrix create_matrix(int *data, int n_rows, int n_cols){

    struct matrix Matrix;
        Matrix.data = malloc((n_cols*n_rows)*sizeof(int));
        Matrix.n_rows = n_rows;
        Matrix.n_cols = n_cols;
        Matrix.stride_rows = n_cols;
        Matrix.stride_cols = 1;
        Matrix.offset = 0;

    for(int i=0;i < (n_cols*n_rows);i++){
        Matrix.data[i] = data[i];
    }
    return Matrix;

}
//Matrix nula
struct matrix zeros_matrix(int n_rows, int n_cols){

    int *data_zeros = malloc((n_cols*n_rows)*sizeof(int));

    for(int i = 0;i < (n_cols*n_rows);i++){
        data_zeros[i] = 0;
    }

    struct matrix Matrix_zeros;
    Matrix_zeros = create_matrix(data_zeros,n_rows,n_cols);

    return Matrix_zeros;
}
//Matrix random
struct matrix random_matrix(int n_rows, int n_cols, int b, int e){

    int *data_random = malloc((n_cols*n_rows)*sizeof(int));

    for(int i = 0;i < (n_cols*n_rows);i++){
        data_random[i] = b + ( rand() % e );
    }

    struct matrix Matrix_random;
    Matrix_random = create_matrix(data_random,n_rows,n_cols);

    return Matrix_random;
}
//Matrix identidade
struct matrix i_matrix(int n){

    int acumulador = 0;

    struct matrix Matrix_i;
    Matrix_i = zeros_matrix(n,n);

    for(int i = 0;i < Matrix_i.n_rows;i++){
        if(i == 0){
            Matrix_i.data[i] = 1;
        }
        else{
            acumulador += Matrix_i.stride_rows;
            Matrix_i.data[acumulador + i] = 1;
        }
    }
    return Matrix_i;
}


// Funções para acessar elementos

//Get element
int get_element(struct matrix a_matrix, int ri, int ci){

    int index;
    index = ((ri - 1)*a_matrix.stride_rows) + (ci - 1);

    return a_matrix.data[index];
}
//put element
void put_element(struct matrix a_matrix, int ri, int ci, int elem){

    int index;
    index = ((ri - 1)*a_matrix.stride_rows) + (ci - 1);

    a_matrix.data[index] = elem;
}
//Print
void print_matrix(struct matrix a_matrix){

    int acumulador = 0;

    for(int j = 0;j < a_matrix.n_rows;j++){
        for(int i = 0; i < (a_matrix.n_cols);i++){
            printf("%d ",a_matrix.data[acumulador + i]);
        }
        acumulador += a_matrix.stride_rows;
        printf("\n");
    }

}


// Funções para manipulação de dimensões

//Matrix transposta
struct matrix transpose(struct matrix a_matrix){

    int rows = a_matrix.n_rows;
    int cols = a_matrix.n_cols;

    a_matrix.n_rows = cols;
    a_matrix.n_cols = rows;
    a_matrix.stride_rows = rows;
    a_matrix.stride_cols = 1;
    a_matrix.offset = 0;

    return a_matrix;
}
//Reshape
struct matrix reshape(struct matrix a_matrix, int new_n_rows, int new_n_cols){

    a_matrix.n_rows = new_n_rows;
    a_matrix.n_cols = new_n_cols;
    a_matrix.stride_rows = new_n_cols;
    a_matrix.stride_cols = 1;
    a_matrix.offset = 0;

    return a_matrix;
}
//Flatten
struct matrix flatten(struct matrix a_matrix){

    int rows = a_matrix.n_rows;
    int cols = a_matrix.n_cols;

    a_matrix.n_rows = 1;
    a_matrix.n_cols = (rows * cols);
    a_matrix.stride_rows = 0;
    a_matrix.stride_cols = 1;
    a_matrix.offset = 0;

    return a_matrix;
}


// Funções de agregação
//Sum
int sum(struct matrix a_matrix){

    int soma = 0;

    for(int i = 0;i < (a_matrix.n_cols * a_matrix.n_rows);i++){
        soma += a_matrix.data[i];
    }

    return soma;
}
//Mean
float mean(struct matrix a_matrix){

    int soma_valores = sum(a_matrix);

    float media = soma_valores / (a_matrix.n_rows * a_matrix.n_cols);

    return media;
}
//Min
int min(struct matrix a_matrix){

    int acumulador_min = a_matrix.data[0];

    for(int i = 0;i < (a_matrix.n_cols * a_matrix.n_rows);i++){
        if(a_matrix.data[i] <= acumulador_min){
            acumulador_min = a_matrix.data[i];
        }
    }

    return acumulador_min;
}
//Max
int max(struct matrix a_matrix){

    int acumulador_max = a_matrix.data[0];

    for(int i = 0;i < (a_matrix.n_cols * a_matrix.n_rows);i++){
        if(a_matrix.data[i] >= acumulador_max){
            acumulador_max = a_matrix.data[i];
        }
    }

    return acumulador_max;
}

// Funções de operações aritméticas
// ADD
struct matrix add(struct matrix a_matrix, struct matrix b_matrix){

    int *data_add = malloc((a_matrix.n_cols * a_matrix.n_rows) * sizeof(int));

    for(int i = 0;i < (a_matrix.n_cols * a_matrix.n_rows);i++){
        data_add[i] = a_matrix.data[i] + b_matrix.data[i];
    }

    struct matrix Matrix_add = create_matrix(data_add,a_matrix.n_rows,a_matrix.n_cols);

    return Matrix_add;
}
//SUB
struct matrix sub(struct matrix a_matrix, struct matrix b_matrix){

    int *data_sub = malloc((a_matrix.n_cols * a_matrix.n_rows) * sizeof(int));

    for(int i = 0;i < (a_matrix.n_cols * a_matrix.n_rows);i++){
        data_sub[i] = a_matrix.data[i] - b_matrix.data[i];
    }

    struct matrix Matrix_sub = create_matrix(data_sub,a_matrix.n_rows,a_matrix.n_cols);

    return Matrix_sub;
}
//Division
struct matrix division(struct matrix a_matrix, struct matrix b_matrix){

    int *data_division = malloc((a_matrix.n_cols * a_matrix.n_rows) * sizeof(int));

    for(int i = 0;i < (a_matrix.n_cols * a_matrix.n_rows);i++){
        data_division[i] = a_matrix.data[i] / b_matrix.data[i];
    }

    struct matrix Matrix_division = create_matrix(data_division,a_matrix.n_rows,a_matrix.n_cols);

    return Matrix_division;
}
//MUL
struct matrix mul(struct matrix a_matrix, struct matrix b_matrix){

    int *data_mul = malloc((a_matrix.n_cols * a_matrix.n_rows) * sizeof(int));

    for(int i = 0;i < (a_matrix.n_cols * a_matrix.n_rows);i++){
        data_mul[i] = a_matrix.data[i] * b_matrix.data[i];
    }

    struct matrix Matrix_mul = create_matrix(data_mul,a_matrix.n_rows,a_matrix.n_cols);

    return Matrix_mul;

}
//Matmul

struct matrix matmul(struct matrix a_matrix, struct matrix b_matrix){
    int value;
    int i = 0, j = 0 ,k = 0, fator = 0;
    int conta_linha = 1;
    int indice;
    int *data_matmul = malloc((a_matrix.n_cols * a_matrix.n_rows) * sizeof(int));

    while(a_matrix.n_rows--){
        for(; i < a_matrix.n_cols*b_matrix.n_cols;){
            conta_linha = i / b_matrix.n_cols;
            value += a_matrix.data[i] * b_matrix.data[j];
            i++;
            j += b_matrix.n_cols;

            if(j > ((pow(b_matrix.n_cols, 2) - (b_matrix.n_cols) + fator) + 1)){
               j = fator;
               indice = i == b_matrix.n_cols ? fator : fator + b_matrix.n_cols*(conta_linha);
               data_matmul[indice] = value;
               value = 0;
            }
            if(i == pow(b_matrix.n_cols,2)){
                break;
            }
            conta_linha = 0;
        }
        ++fator;
        j = fator;
        i = 0;
    }

    struct matrix MatMul = create_matrix(data_matmul, b_matrix.n_cols, b_matrix.n_cols);

    return MatMul;
}

