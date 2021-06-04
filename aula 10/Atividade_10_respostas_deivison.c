/*Aluno: Deivison rodrigues jordao
 *Professor: Yuri Malheiros
 *Programaçao estrurada
 *atividade refeita e otimizada com o que foi apresentado na aula de resolucao de exercicios
 */
#include <stdio.h>

int main(void){
    
    //definicao de variaveis
    char primeira_palavra,segunda_palavra;
    int primeira_contagem[26] = {0};
    int segunda_contagem[26] = {0};
    int avaliador = 1;

    //entrada de dados
    printf("Digite uma palavra: ");
    do{
        primeira_palavra = getchar();
        primeira_contagem[primeira_palavra - 97]++;
    }while (primeira_palavra != '\n');
    
        printf("Digite uma outra palavra: ");
    do{
        segunda_palavra = getchar();
        segunda_contagem[segunda_palavra - 97]++;
    }while (segunda_palavra != '\n');

    //processamento dos dados
    for (int i = 0; i < 26; i++){
        if (primeira_contagem[i] != segunda_contagem[i]){
            avaliador = 0;
            break;
        }
        
    }

    //saída de dados
    if (avaliador == 0){
        printf("NÃO É ANAGRAMA!!!");
    }
    else{
        printf("É UM ANAGRAMA!!!");
    }
    return 0 ;
}