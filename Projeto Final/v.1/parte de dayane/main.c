// ALUNO: DEIVISON RODRIGUES JORDÃO               MATRICULA: 20200023728 //
#include <stdio.h>
#include "matrix.h"

int main(void){

    int data_teste[] = {1,2,3,4,5,6,7,8,9};

    printf("matrix criada: \n");
    struct matrix create_matrix_teste = create_matrix(data_teste,3,3);
    print_matrix(create_matrix_teste);
    printf("%d", sizeof(create_matrix_teste));

    printf("\nmatrix zeros criada: \n");
    struct matrix create_matrix_zeros_teste = zeros_matrix(3,3);
    print_matrix(create_matrix_zeros_teste);

    printf("\nmatrix random criada: \n");
    struct matrix create_matrix_random_teste = random_matrix(3,3,10,20);
    print_matrix(create_matrix_random_teste);

    printf("\nmatrix identidade criada: \n");
    struct matrix create_matrix_i_teste = i_matrix(3);
    print_matrix(create_matrix_i_teste);

    printf("\nGet element \n");
    printf("\nmatrix original: \n");
    print_matrix(create_matrix_teste);
    printf("\nElemento requisitado: %d \n",get_element(create_matrix_teste,3,2));

    printf("\nPut element \n");
    printf("\nmatrix original: \n");
    print_matrix(create_matrix_teste);
    put_element(create_matrix_teste,3,2,9);
    printf("\nmatrix modificada: \n");
    print_matrix(create_matrix_teste);

    //desfazendo a modificação
    create_matrix_teste = create_matrix(data_teste,3,3);

    int data_teste_2[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    struct matrix create_matrix_teste_2 = create_matrix(data_teste_2,5,4);
    printf("\nmatrix original: \n");
    print_matrix(create_matrix_teste_2);
    printf("\n");
    struct matrix trasposta_teste = transpose(create_matrix_teste_2);
    print_matrix(trasposta_teste);
    printf("\n");
    create_matrix_teste_2 = create_matrix(data_teste_2,5,4);
    struct matrix reshape_teste = reshape(create_matrix_teste_2,2,10);
    print_matrix(reshape_teste);
    printf("\n");
    create_matrix_teste_2 = create_matrix(data_teste_2,5,4);
    struct matrix flatten_teste = flatten(create_matrix_teste_2);
    print_matrix(flatten_teste);
    printf("\n");

    printf("\nSoma : %d\n",sum(create_matrix_teste));
    printf("\nMedia : %f\n",mean(create_matrix_teste));
    printf("\nValor minimo : %d\n",min(create_matrix_teste));
    printf("\nValor maximo : %d\n",max(create_matrix_teste));

    printf("\nmatrizes originais:\n");
    print_matrix(create_matrix_teste);
    printf("\n");
    print_matrix(create_matrix_teste);
    printf("\nmatrizes somadas:\n");
    struct matrix matrix_ADD = add(create_matrix_teste,create_matrix_teste);
    print_matrix(matrix_ADD);
    printf("\nmatrizes subitraidas:\n");
    struct matrix matrix_SUB = sub(create_matrix_teste,create_matrix_teste);
    print_matrix(matrix_SUB);
    printf("\nmatrizes divididas:\n");
    struct matrix matirx_division = division(create_matrix_teste,create_matrix_teste);
    print_matrix(matirx_division);
    printf("\nmatrizes multiplicadas:\n");
    struct matrix matrix_mul = mul(create_matrix_teste,create_matrix_teste);
    print_matrix(matrix_mul);
    printf("\nmultiplicacao matricial:\n");
    struct matrix Matmul = matmul(create_matrix_teste, create_matrix_teste);
    print_matrix(Matmul);

    return 0;
}
