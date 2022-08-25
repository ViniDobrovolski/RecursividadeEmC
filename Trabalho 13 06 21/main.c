#include <stdio.h>
#include <stdlib.h>

struct No{ //cria a estrutura da arvore
    int num;
    struct No *esq;//ponteiro que aponta para o filho esquerdo
	struct No *dir; //ponteiro que aponta para o filho direito
};
typedef struct No no;
typedef no *ArvBin;

ArvBin* criarArvBin(){
    ArvBin *raiz =(ArvBin*) malloc (sizeof(ArvBin));//aloca ponteiro raiz da arvore
    if(raiz != NULL){
        *raiz=NULL;
    }else{
        printf("Erro na aloca��o...\n");
        exit(0);
    }
    return raiz;
}

int insere_ArvBin(ArvBin* raiz){
    no *novo=(no *) malloc(sizeof(no)); //aloca novo elemento
    if(novo == NULL){//testa se alocacao ocorreu
        printf("Sem memoria disponivel!\n");
        exit(0);
    }
    printf("Novo elemento: ");
    scanf("%d", &novo->num);
    novo->dir = NULL;
    novo->esq = NULL;
    if(*raiz == NULL){//se arvore vazia insere primeiro n�
        *raiz = novo;
    }else{
        no *atual = *raiz;
        no *ant = NULL;
        while (atual != NULL){
            ant = atual;
            if(novo->num == atual->num){
                printf("Elemento j� existe...");
                free(novo);
                return 0;//elemento j� existe
            }
            if(novo->num > atual->num){
                atual = atual->dir;
            }else{
                atual = atual->esq;
            }
        }
        if (novo->num > ant->num){
            ant->dir = novo;
        }else{
            ant->esq = novo;
        }
    }
}


void exibe_NO(no *no_liberar){//fun��o recursiva para percorrer
	if(no_liberar == NULL){
		return;
	}else{
		exibe_NO(no_liberar->esq); //desce subarvore esquerda
		exibe_NO(no_liberar->dir); //desce subarvore direita
		printf("%5d", no_liberar->num);
	}
}
int exibe_ArvBin(ArvBin* raiz){
    if(raiz == NULL){//se arvore vazia
    	//return 0;
 	}else{
        exibe_NO(*raiz);//chama fun��o recursiva
    }
  printf("\n");
}


int exibe_ArvBinPREOrd(ArvBin* raiz){
    if(raiz == NULL){//se arvore vazia
    	//return 0;
 	}else{
        exibe_NOpreORD(*raiz);//chama fun��o recursiva
    }
  printf("\n");
}
void exibe_NOpreORD(no *no_liberar){//fun��o recursiva para percorrer

	if(no_liberar == NULL){
		return;
	}else{
	    printf("%5d", no_liberar->num);


        exibe_NOpreORD(no_liberar->esq);
       exibe_NOpreORD(no_liberar->dir);



	}
}

int exibe_ArvBinINOrd(ArvBin* raiz){
    if(raiz == NULL){//se arvore vazia
    	//return 0;
 	}else{
        exibe_NOINORD(*raiz);//chama fun��o recursiva
    }
  printf("\n");
}
void exibe_NOINORD(no *no_liberar){//fun��o recursiva para percorrer

	if(no_liberar == NULL){
		return;
	}else{



        exibe_NOINORD(no_liberar->esq);
        printf("%5d", no_liberar->num);
       exibe_NOINORD(no_liberar->dir);



	}
}

void libera_NO(no *no_liberar){//fun��o recursiva para percorrer
	if(no_liberar == NULL){
		return;
	}else{
		libera_NO(no_liberar->esq); //desce subarvore esquerda
		libera_NO(no_liberar->dir); //desce subarvore direita
		free(no_liberar);
   }
}
int libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL){//se arvore vazia
    	return 0;
 	}else{
        libera_NO(*raiz);//chama fun��o recursiva
    }
    free(raiz);
}

int altura_ArvBin(ArvBin* raiz){
	if(raiz == NULL){//se arvore vazia
    	return 0;
 	}
 	if(*raiz == NULL){ //se folha
        return 0;
 	}
    int alt_esq = altura_ArvBin(&((*raiz)->esq));//recursiva
    int alt_dir = altura_ArvBin(&((*raiz)->dir));//recursiva
    if (alt_esq > alt_dir){
        return (alt_esq + 1);
    }else{
        return (alt_dir + 1);
    }
}

int totalNO_ArvBin(ArvBin* raiz){
	if(raiz == NULL){//se arvore vazia
    	return 0;
 	}
 	if(*raiz == NULL){
        return 0;
 	}
    int alt_esq = altura_ArvBin(&((*raiz)->esq));//recursiva
    int alt_dir = altura_ArvBin(&((*raiz)->dir));//recursiva
    return (alt_esq + alt_dir + 1);
}

int main(){
    ArvBin *raiz = criarArvBin();
    int opt,altura,numero_no;
    do{
        printf("Escolha a opcao\n");
        printf("1. Insere \n");
        printf("2. Exibe \n");
        printf("3. Remove\n");
        printf("4. Altura\n");
        printf("5. Numero de nos\n");
        printf("6. Exibe arvore Pre ordem\n");
        printf("7. Exibe arvore In ordem\n");
        printf("0. Sair\n");
        scanf("%d", &opt);
        switch(opt){
            case 1:
                insere_ArvBin(raiz);
                break;
            case 2:
                exibe_ArvBin(raiz);;
                break;
            case 3:
                //remove(raiz);
                break;
            case 4:
                altura = altura_ArvBin(raiz);
                printf("Altura da arvore igual a %i\n",altura);
                break;
            case 5:
                numero_no = totalNO_ArvBin(raiz);
                printf("Total de nos igual a %i\n",numero_no);
                break;

            case 6:
                exibe_ArvBinPREOrd(raiz);
                break;

            case 7:
                exibe_ArvBinINOrd(raiz);
                break;


            default:
            	printf("Opcao invalida...\n");
            	break;
        }
    }while(opt != 0);
    libera_ArvBin(raiz);
}
