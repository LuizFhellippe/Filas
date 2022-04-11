#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

void InicializaFila(No **fila){
    *fila = NULL;
}

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

No* RemoverDaFila(No **fila){
    No *remover = NULL;

    if(*fila){
        remover = *fila;
        *fila = remover->proximo;
    }
    return remover;
}

int BuscaUsuario(No **fila, int num){
    int i = 1;
    No *aux;
    aux = *fila;

    while(aux->valor != num){
        RemoverDaFila(&aux);
        i++;
    }
    return i;
}

void Imprimir(No *fila){
    printf("\t=========== Fila ===========\n");
    while(fila){
        if(!fila->proximo){
            printf("%d ", fila->valor);
        }else{
            printf("%d, ", fila->valor);
        }
        fila = fila->proximo;
    }
    printf("\n\n");
}

int main(){
    No *r, **fila = NULL;
    int opcao, valor, buscado;
    InicializaFila(&fila);

    do{
        printf("0 - Sair\n1 - Inserir\n2 - Excluir\n3 - Buscar\n4 - Imprimir\n");
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
                printf("Digite um valor: ");
                scanf("%d", &valor);
                buscado = BuscaUsuario(&fila, valor);
                printf("\nNumero na posicao %d da lista\n", buscado);
                break;
            case 4:
                Imprimir(fila);
                break;
            default:
                if(opcao != 0){
                    printf("Opcao invalida\n");
                }
        }
    }while(opcao != 0);
}