// Vinicius Dobrovolski
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int n=5;
int vet[5];


int recursiva(int n){
    if (n==0)
        return vet[0];
    else
        return (vet[n]+(recursiva (n-1)));
}

int main()
{
    setlocale(LC_ALL, "");

    printf("Preencha o vetor de 5 posições:\n");
    for(int a=0;a<5;a++){
        scanf("%d",&vet[a]);
    }

    printf("A soma de todos valores do vetor é: %d",recursiva(n));


}
