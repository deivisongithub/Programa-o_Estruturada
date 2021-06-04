/*Aluno: Deivison rodrigues jordao
 *Professor: Yuri Malheiros
 *Programaçao estrurada
 */
#include <stdio.h>

int ano_bissexto(ano){
     if (ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0)) {return 1;}
    else {return 0;}}

int dia_do_ano(dia,mes,ano){
    if(ano_bissexto(ano) == 0){
        switch(mes){
            case 1: return dia;
            case 2: return 31 + dia;
            case 3: return 59 + dia;
            case 4: return 90 + dia;
            case 5: return 120 + dia;
            case 6: return 151 + dia;
            case 7: return 181 + dia;
            case 8: return 212 + dia;
            case 9: return 243 + dia;
            case 10: return 273 + dia;
            case 11: return 304 + dia;
            case 12: return 334 + dia;}}
    else{
        switch(mes){
            case 1: return dia;
            case 2: return 31 + dia;
            case 3: return 59 + dia + 1;
            case 4: return 90 + dia + 1;
            case 5: return 120 + dia + 1;
            case 6: return 151 + dia + 1;
            case 7: return 181 + dia + 1;
            case 8: return 212 + dia + 1;
            case 9: return 243 + dia + 1;
            case 10: return 273 + dia + 1;
            case 11: return 304 + dia + 1;
            case 12: return 334 + dia + 1;}}}

int main(void){
    int dia_usuario,mes_usuario,ano_usuario;
    printf("Digite o dia/mes/ano(usando barra para separar): ");
    scanf("%d/%d/%d",&dia_usuario,&mes_usuario,&ano_usuario);
    printf("dia %d do ano em questao",dia_do_ano(dia_usuario,mes_usuario,ano_usuario));
    return 0;}