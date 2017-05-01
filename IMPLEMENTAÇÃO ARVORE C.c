#include <stdio.h>
#include <stdlib.h>

typedef struct arv{
    char chave;
    struct arv *esq;
    struct arv *dir;
}noArv, *Arv;

Arv arvVazia(){
    return NULL;
}

Arv criaNo(char c, Arv a, Arv b){
    Arv aux= (Arv)malloc(sizeof(noArv));
    aux->chave=c;
    aux->esq=a;
    aux->dir=b;
    return aux;
}

void imprimeArv(Arv p){
    printf("<");
    if (p){
        printf("%c ", p->chave);
        imprimeArv(p->esq);
        imprimeArv(p->dir);
    }else printf("0");
    printf(">");
}

Arv liberaArv(Arv *p){
Arv aux=*p;
    if(aux){
        liberaArv(&(aux->esq));
        liberaArv(&(aux->dir));
        free(aux);
    }
    return NULL;
}

int buscaArv(Arv p, char i){
    if(p)
        return p->chave==i || buscaArv(p->esq, i) || buscaArv(p->dir, i);
    else
        return 0;
}

int main(){
Arv x;
x=criaNo('a', criaNo('b', criaNo('c', arvVazia(), arvVazia()), arvVazia()), criaNo('d', arvVazia(), arvVazia()));
imprimeArv(x);
//x=liberaArv(&x);
//imprimeArv(x);
printf("\n%d", buscaArv(x, 'e'));
return 0;
}
