 #include <stdio.h>
 
 int contador_digitos(numero){
     int contaDigitos = 0, valor = numero;
     do
     {
         contaDigitos = contaDigitos + 1;
         valor = valor / 10;
     }
     while (valor != 0);
     return contaDigitos;
}
int main(void){
    printf("%d",contador_digitos(1234));
}