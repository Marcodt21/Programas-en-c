#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct nodo {
int val;
struct nodo *sig;
} Nodo;

typedef Nodo * Lista;

Lista newList(){ return NULL;}

void insert(int x, Lista *l){
    Nodo *p=malloc(sizeof(Nodo));
    p->val=x;
    p->sig=*l;
    *l=p;
}
void main(){
    int x=3;
    Lista *L=newList();
    insert(x,*L);
    Nodo *q=L;
    while(q!=NULL){
            printf("\n%d",q->val);
            q=q->sig;
    }
    }
