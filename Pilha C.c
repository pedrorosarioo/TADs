#include <stdio.h>
#include <stdlib.h>

typedef struct{
        int p[10];
        int topo;
}Pilha;
        

int is_empity(Pilha *v){
    if (v->topo==-1){
       return 1;
    }else{
       return 0;
    }
}

int is_full(Pilha *v){
    if (v->topo>=10){
       return 1;
    }else{
       return 0;
    }
}
    
int pop (Pilha *v){
int r;
     if(!(is_empity(v))){
        r=v->p[v->topo];
        v->topo--;
        return r;
     }else{
        return 0;
     }
}

void push(Pilha *v, int n){
     if(!(is_full(v))){
        v->topo++;
        v->p[v->topo]=n;
     }else{
        printf("Pilha cheia \n\n");
}
}

int main(){
    int q;
    Pilha x;
    x.topo = -1;
    push(&x, 5);
    printf ("%d  ", x.p[0]);
    system ("pause");
    return 0;      
}

