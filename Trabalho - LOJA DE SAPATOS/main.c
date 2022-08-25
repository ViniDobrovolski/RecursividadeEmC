//Vinicius Dobrovolski

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct SAPATO
{
    int cod;
    char marca[15];
    int numero;
    int quantidade;
    float valor;
}*ptr;


int main()
{
    setlocale(LC_ALL, "");
    int opc,tam=1;
    int pos_cal=0;
    int relat;
    char marca_comp[15];
    int num_comp,cod_comp;
    struct SAPATO aux;

    ptr=(struct SAPATO*) malloc (tam*sizeof(struct SAPATO));


    do
    {
        printf("\nDigite '1' para adicionar um calçado novo\nDigite '2' para alterar um calçado através do seu código\nDigite '3' para tirar um relatório\nDigite '4' para excluir um calçado através do seu código");
        printf("\nDigite '0' para finalizar o programa\n");
        scanf("%d",&opc);

        switch(opc)
        {
        case (1):


            printf("\nQual o código do calçado: \n");
            scanf("%d",&ptr[pos_cal].cod);
            printf("\nQual a marca do calçado?\n");
            scanf("%s",&ptr[pos_cal].marca);
            printf("\nQual o número do calçado?\n");
            scanf("%d",&ptr[pos_cal].numero);
            printf("\nQual a quantidade de calçados?\n");
            scanf("%d",&ptr[pos_cal].quantidade);
            printf("\nQual o valor do calçado?\n");
            scanf("%f",&ptr[pos_cal].valor);

            printf("\nCódigo:%d\nMarca:%s\nNúmero:%d\nQuantidade:%d\nValor:%.2f\n",ptr[pos_cal].cod,ptr[pos_cal].marca,ptr[pos_cal].numero,ptr[pos_cal].quantidade,ptr[pos_cal].valor);

            tam++;
            pos_cal++;
            ptr=(struct SAPATO*) realloc(ptr,tam*sizeof(struct SAPATO));

            break;

        case(2):
            printf("\nQual o código do calçado que você deseja alterar?\n");
            scanf("%d",&cod_comp);

            for(int i=0; i<pos_cal; i++)
            {
                if(ptr[i].cod==cod_comp)
                {

                    printf("\nQual a marca do calçado?\n");
                    scanf("%s",&ptr[i].marca);
                    printf("\nQual o número do calçado?\n");
                    scanf("%d",&ptr[i].numero);
                    printf("\nQual a quantidade de calçados?\n");
                    scanf("%d",&ptr[i].quantidade);
                    printf("\nQual o valor do calçado?\n");
                    scanf("%f",&ptr[i].valor);
                }
            }

            break;

        case(3):
            printf("\nDigite 1 se deseja tirar um relatório por marca\nDigite 2 se desejar tirar um relatório por número\nDigite 3 se deseja tirar um relatório por Código\nDigite 4 se deseja tirar um relatório de todos os calçados do sistema\n");
            scanf("%d",&relat);
            switch(relat)
            {
            case(1):
                printf("Qual marca?\n");
                scanf("%s",&marca_comp);

                for(int i=0; i<pos_cal; i++)
                {
                    if(strcmp(ptr[i].marca,marca_comp)==0)
                    {
                        printf("\nCalçado:\nCódigo:%d\nMarca:%s\nNúmero:%d\nQuantidade:%d\nValor:%.2f\n\n\n",ptr[i].cod,ptr[i].marca,ptr[i].numero,ptr[i].quantidade,ptr[i].valor);
                    }
                }
                break;
            case(2):
                printf("Qual número?\n");
                scanf("%d",&num_comp);

                for(int i=0; i<pos_cal; i++)
                {
                    if(ptr[i].numero==num_comp)
                    {

                        printf("\nCalçado:\nCódigo:%d\nMarca:%s\nNúmero:%d\nQuantidade:%d\nValor:%.2f\n\n\n",ptr[i].cod,ptr[i].marca,ptr[i].numero,ptr[i].quantidade,ptr[i].valor);

                    }
                }

                break;

            case(3):
                printf("Qual código?\n");
                scanf("%d",&cod_comp);

                for(int i=0; i<pos_cal; i++)
                {
                    if(ptr[i].cod==cod_comp)
                    {

                        printf("\nCalçado:\nCódigo:%d\nMarca:%s\nNúmero:%d\nQuantidade:%d\nValor:%.2f\n\n\n",ptr[i].cod,ptr[i].marca,ptr[i].numero,ptr[i].quantidade,ptr[i].valor);

                    }
                }

                break;

            case(4):

                printf("\nRelatório de todos os calçados do sistema:\n");

                for(int i=0; i<pos_cal; i++)
                {
                    printf("\nCalçado:\nCódigo:%d\nMarca:%s\nNúmero:%d\nQuantidade:%d\nValor:%.2f\n\n\n",ptr[i].cod,ptr[i].marca,ptr[i].numero,ptr[i].quantidade,ptr[i].valor);
                }
                break;

            }
            break;

        case(4):
            printf("\nDigite o código do calçado que deseja excluir:\n");
            scanf("%d",&cod_comp);

            for(int i=0; i<pos_cal; i++)
            {
                if(ptr[i].cod==cod_comp)
                {
                    if(ptr[i].cod==ptr[pos_cal].cod)
                    {
                        ptr=(struct SAPATO*) realloc(ptr,tam-1*sizeof(struct SAPATO));
                    }
                    if(ptr[i].cod!=ptr[pos_cal].cod)
                    {
                        tam=tam-1;
                        aux=ptr[pos_cal];
                        ptr[pos_cal]=ptr[i];
                        ptr[i]=aux;

                        ptr=(struct SAPATO*) realloc(ptr,tam*sizeof(struct SAPATO));
                        pos_cal=pos_cal-1;
                    }
                }
            }

        }

    }

    while(opc!=0);

    free(ptr);
}
