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

int maior(int x, int y){
    if (x>=y) return x;
    else return y;
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

void insereArvBB(Arv *p, Arv no){
    if (!(*p)) *p=no;
    else if((*p)->chave>no->chave) insereArvBB(&((*p)->esq), no);
    else insereArvBB(&((*p)->dir), no);
}

Arv liberaArv(Arv *p){ //LIBERA UMA RAIZ E TODOS OS SEUS FILHOS
Arv aux=*p;
    if(aux){
        liberaArv(&(aux->esq));
        liberaArv(&(aux->dir));
        free(aux);
    }
    return NULL;
}



int buscaArv(Arv p, char i){ //VERIFICA SE O CARACTER i APARECE NA ARVORE
    if(p)
        return p->chave==i || buscaArv(p->esq, i) || buscaArv(p->dir, i);
    else
        return 0;
}

int buscanArv(Arv p, char i){ //PROCURA QUANTAS VEZES O CARACTER i SE REPETE NA ARVORE
    if(p==NULL) return 0;
    if (p->chave==i) return (1+buscanArv(p->esq, i)+buscanArv(p->dir, i));
    else return (buscanArv(p->esq, i)+buscanArv(p->dir, i));
}

int igualArv(Arv p, Arv b){ //COMPARA SE O FORMATO DAS DUAS ARVORES SÃO IGUAIS
    if ((!p)&&(!b)) return 1;
    if ((!p)||(!b)) return 0;
    else return (igualArv(p->esq, b->esq)*igualArv(p->dir, b->dir));
}

int simetricArv(Arv p, Arv b){ //VERIFICA SE DUAS ARVORES SAO SIMETRICAS
    if ((!p)&&(!b)) return 1;
    if ((!p)||(!b)) return 0;
    else return (igualArv(p->esq, b->dir)*igualArv(p->dir, b->esq));
}

int alturaArv(Arv p){
    if(p==NULL) return 0;
    else return maior(1+alturaArv(p->esq), 1+alturaArv(p->dir));
}

int main(){
Arv x,y, k;

x=criaNo('a', arvVazia(), criaNo('c', arvVazia(), arvVazia()));
y=criaNo('b', arvVazia(), criaNo('d', arvVazia(), arvVazia()));
insereArvBB(&x, y);
//printf("%d", simetricArv(x, y));
//x=liberaArv(&x);
imprimeArv(x);
//printf("%d\n", alturaArv(x));
//printf("\n%d", buscaArv(x, 'e'));
return 0;
}
