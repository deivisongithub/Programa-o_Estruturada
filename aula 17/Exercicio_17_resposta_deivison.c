/*Aluno: Deivison rodrigues jordao
 *Professor: Yuri Malheiros
 *Programaçao estrurada
 */

#include <stdio.h>

int main(int argc,char *argv[]){
    for (int i=argc; i != 0; i--){
        printf("%s ", argv[i]);
    }
    printf("\n");
    return 0;
}