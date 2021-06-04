/*Aluno: Deivison rodrigues jordao
 *Professor: Yuri Malheiros
 *Programaçao estrurada
 *Espero que o senhor goste :D
 */

#include <stdio.h>

int main(void){
    int hora,minutos,conversao_hora;
    printf("Digite um horario: ");
    scanf("%d:%d",&hora,&minutos);
    if(hora < 12){
        if(minutos == 0){
            if(hora < 10){
                printf("Resposta:  0%d:%d0",hora,minutos,minutos);
            }
            else{
                printf("Resposta:  %d:%d0",hora,minutos,minutos);
            }
        }
        else{
            if(minutos < 10){
                printf("Resposta:  %d:0%d",hora,minutos);
            }
            else{
                printf("Resposta:  %d:%d",hora,minutos);
            }
        }
    }
    else{
        if(minutos == 0){
            conversao_hora = hora - 12;
            if(conversao_hora < 10){
                printf("Resposta:  0%d:%d0",conversao_hora,minutos);
            }
            else{
                printf("Resposta:  %d:%d0",conversao_hora,minutos);
            }
        }
        else{
            conversao_hora = hora - 12;
            if(minutos < 10){
                if(conversao_hora < 10){
                    printf("Resposta:  0%d:0%d",conversao_hora,minutos);
                }
                else{
                    printf("Resposta:  %d:0%d",conversao_hora,minutos);
                }
            }
            else{
                if(conversao_hora < 10){
                    printf("Resposta:  0%d:%d",conversao_hora,minutos);
                }
                else{
                    printf("Resposta:  %d:%d",conversao_hora,minutos);
                }
            }
        }
    }


    return 0;
}