/*Aluno: Deivison rodrigues jordao
 *Professor: Yuri Malheiros
 *Programaçao estrurada
 *Espero que o senhor goste :D
 */
#include <stdio.h>
int main(void){
    int numero,dezen,unid;
    printf("Digite um numero: ");
    scanf("%d",&numero);
    dezen = numero / 10;
    unid =   numero % 10;
    if ((numero > 10) && (numero < 20)){
        switch (numero){
        case 11:printf("onze");break;
        case 12:printf("doze");break;
        case 13:printf("treze");break;
        case 14:printf("quatorze");break;
        case 15:printf("quinze");break;
        case 16:printf("dezesseis");break;
        case 17:printf("dezessete");break;
        case 18:printf("dezoito");break;
        default:printf("dezenove");break;}}
        else{
        switch (dezen){
        case 1:printf("dez");break;
        case 2:if (numero == 20){printf("vinte");}else{printf("vinte e ");}break;
        case 3:if (numero == 30){printf("trinta");}else{printf("trinta e ");}break;
        case 4:if (numero == 40){printf("quarenta");}else{printf("quarenta e ");}break;
        case 5:if (numero == 50){printf("cinquenta");}else{printf("cinqueta e ");}break;
        case 6:if (numero == 60){printf("sessenta");}else{printf("sessenta e ");}break;
        case 7:if (numero == 70){printf("setenta");}else{printf("setenta e ");}break;
        case 8:if (numero == 80){printf("oitenta");}else{printf("oitenta e ");}break;
        case 9:if (numero == 90){printf("noventa");}else{printf("noventa e ");}break;
        default:printf("");break;}
        switch (unid){
        case 1:printf("um");break;
        case 2:printf("dois");break;
        case 3:printf("tres");break;
        case 4:printf("quatro");break;
        case 5:printf("cinco");break;
        case 6:printf("seis");break;
        case 7:printf("sete");break;
        case 8:printf("oito");break;
        case 9:printf("nove");break;
        default:if (numero < 10){printf("zero");}break;}}
        return 0;}
