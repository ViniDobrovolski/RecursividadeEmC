// Vinicius Dobrovolski
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int recursiva(int n){
 int a,b;
 a=n % 10;
 b=(n-a)/10;

 if(b<=0)
    return a;
 else{
    return a+ recursiva(b);
 }



}

int main()
{
    int n;
    setlocale(LC_ALL, "");

    printf("Digite um número para N:\n");
        scanf("%d",&n);

    printf("A soma dos digitos do número N é: %d \n", recursiva(n));




}
