#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

void InserirNaFila(No **fila, int num){
    No *aux, *new = malloc(sizeof(No));

    if(new){
        new->valor = num;
        new->proximo = NULL;
        if(*fila == NULL){
            *fila = new;
        }else{
            aux = *fila;
            while(aux->proximo){
                aux = aux->proximo;
            }
            aux->proximo = new;
        }
    }else{
        printf("Erro ao alocar memoria\n");
    }
}

void InserirComPrioridade(No **fila, int num){
    No *aux, *new = malloc(sizeof(No));

    if(new){
        new->valor = num;
        new->proximo = NULL;
        if(*fila == NULL){
            *fila = new;
        }else{
            //é prioridade
            if(num > 59){
                if((*fila)->valor < 60){
                    new->proximo = *fila;
                    *fila = new;
                }else{
                    aux = *fila;
                    while(aux->proximo && aux->proximo->proximo > 59){
                        aux = aux->proximo;
                    }
                    new->proximo = aux->proximo;
                    aux->proximo = new;
                }
            }else{
                aux = *fila;
                while(aux->proximo){
                    aux = aux->proximo;
                }
                aux->proximo = new;
            }
        }
    }else{
        printf("Erro ao alocar memoria\n");
    }
}

No* RemoverDaFila(No **fila){
    No *remover = NULL;

    if(*fila){
        remover = *fila;
        *fila = remover->proximo;
    }
    return remover;
}

void Imprimir(No *fila){
    printf("\t=========== Fila ===========\n");
    while(fila){
        printf("%d", fila->valor);
        fila = fila->proximo;
    }
    printf("\n\t=========== FIM Fila ===========\n");
}

int main(){
    No *r, **fila = NULL;
    int opcao, valor;

    do{
        printf("0 - Sair\n1 - Inserir\n2 - Excluir\n3 - Imprimir\n4 - Inserir com prioridade\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                InserirNaFila(&fila, valor);
                break;
            case 2:
                r = RemoverDaFila(&fila);
                if(r){
                    printf("Removido: %d\n", r->valor);
                    free(r);
                }
                break;
            case 3:
                Imprimir(fila);
                break;
            case 4:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                InserirComPrioridade(&fila, valor);
                break;
            default:
                if(opcao != 0){
                    printf("Opcao invalida\n");
                }
        }
    }while(opcao != 0);
}