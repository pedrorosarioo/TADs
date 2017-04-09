#include <stdio.h>
#include <stdlib.h>

typedef struct NoLista{
    int chave;
    struct NoLista *prox;
}NoLista, *Lista;

void inicializa(Lista *x){
    *x=NULL;
}

int InsereLista(Lista *x, int n){
Lista aux, ant=NULL, dep=*x;

aux=(Lista)malloc(sizeof(NoLista));
if (aux==NULL) return 0;
aux->chave=n;
if (dep==NULL){
    *x=aux;
    aux->prox=NULL;
    return 1;
}else{
    while (dep!=NULL){
        if (aux->chave<dep->chave)break;
        ant=dep;
        dep=dep->prox;
    }
    if (ant==NULL){
        aux->prox=*x;
        *x=aux;
    }else{
        aux->prox=ant->prox;
        ant->prox=aux;
    }
}
return 1;
}

Lista BuscaLista(Lista *x, int n){
Lista aux;
    for (aux=*x; aux!=NULL; aux=aux->prox){
        if (aux->chave==n){
            return aux;
        }
    }
return NULL;
}

int ExcluiLista(Lista *x, int n){
Lista ant=NULL, aux=*x;
if ((BuscaLista(x, n))){
    while (aux!=BuscaLista(x, n)){
        ant=aux;
        aux=aux->prox;
    }
    if (ant==NULL){
        *x=aux->prox;
        free(aux);
    }else{
        ant->prox=aux->prox;
        free(aux);
    }
    return 1;
}
return 0;
}

int main(){
int p;
Lista x;
inicializa(&x);
p=InsereLista(&x, 1);
p=InsereLista(&x, 3);
p=InsereLista(&x, 2);
printf ("%d %d %d %d\n", BuscaLista(&x, 1),BuscaLista(&x, 2), BuscaLista(&x, 3), BuscaLista(&x, 4));
printf ("%d %d ", ExcluiLista(&x, 3), ExcluiLista(&x, 2));
return 0;
}
