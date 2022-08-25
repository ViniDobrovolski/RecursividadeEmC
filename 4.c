// Vinicius Dobrovolski
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int n1,n2;


int Multip_Rec(int n1,int n2){
    if (n2==1)
        return n1;
    else
        return (n1+(Multip_Rec(n1,n2-1)));
}

int main()
{
    setlocale(LC_ALL, "");

    printf("Digite um número para os parametros n1 e n2 respectivamente:\n");
    scanf("%d %d",&n1,&n2);
    printf("O valor de x elevado a n é: %d",Multip_Rec(n1,n2));


}
