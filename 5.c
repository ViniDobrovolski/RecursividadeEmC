// Vinicius Dobrovolski
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int n=5;

void recursiva(int vet[n],int esq,int dir,int n){
    int aux;
    if (esq>=dir){
         for(int a=0;a<5;a++)
        printf("\n%d",vet[a]);
         }
    else{
        aux = vet[esq];
        vet[esq]= vet [dir];
        vet[dir] = aux;
        recursiva(vet,esq+1,dir-1,n);
    }

}

int main()
{
     int vet[n];
    int esq,dir;
    setlocale(LC_ALL, "");

    printf("Preencha o vetor de 5 posições:\n");
    for(int a=0;a<5;a++){
        scanf("%d",&vet[a]);
    }
    printf("\n");

    esq=0;
    dir=n-1;
    recursiva(vet[n],esq,dir, n);



}
