// Vinicius Dobrovolski
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int n;


int recursiva(int n){
    if (n==1)
        return 1;
    else
        return (n+(recursiva (n-1)));
}

int main()
{
    setlocale(LC_ALL, "");

    printf("Digite um n�mero para o parametro n:\n");
    scanf("%d",&n);
    printf("O valor da soma de n �: %d",recursiva(n));


}
