// Vinicius Dobrovolski
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int n,x;


int recursiva(int x,int n){
    if (n==0)
        return 1;
    else
        return (x*(recursiva (x,n-1)));
}

int main()
{
    setlocale(LC_ALL, "");

    printf("Digite um n�mero para o parametro x e n respectivamente:\n");
    scanf("%d %d",&x,&n);
    printf("O valor de x elevado a n �: %d",recursiva(x,n));


}
