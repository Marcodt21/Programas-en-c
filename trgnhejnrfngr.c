#include<stdio.h>
#include<stdlib.h>

typedef struct anodo{
    struct anodo* izq;
    int key;
    struct anodo* der;
}Anodo;

typedef struct raiz{
    Anodo* raiz;
    int tam;
}Raiz;

typedef Raiz* Abb;

Abb newAbb(){
    Abb a=malloc(sizeof(Raiz));
    a->raiz=NULL;
    a->tam=0;
    return a;
}

int esVacio(Abb a){
    return a->raiz==NULL;
}
int iestaEnr(int x, Anodo *a){
    if(a==NULL)return 0;
    if(a->key==x)return 1;
    if(x<a->key)return iestaEnr(x,a->izq);
    else return iestaEnr(x,a->der);
}
int estaEnR(int x, Abb a){
    return iestaEnr(x,a->raiz);
}
void iinsertaR(int x, Anodo **a){
    if(*a==NULL){
        (*a)=malloc(sizeof(Anodo));
        (*a)->der=NULL;
        (*a)->izq=NULL;
        (*a)->key=x;
    }
    else if(x<(*a)->key)return iinsertaR(x,&((*a)->izq));
         else return iinsertaR(x,&((*a)->der));
}

void insertaR(int x, Abb a){
    (a->tam)++;
    iinsertaR(x,&(a->raiz));
}
void ienOrdenR(Anodo *a){
    if(a!=NULL){
        ienOrdenR(a->izq);
        printf("%d", a->key);
        ienOrdenR(a->der);
    }
}
void enOrdenR(Abb a){
    printf("[");
    ienOrdenR(a->raiz);
    printf("]");
}
///////////////////////////gxb
int itamano(Anodo* a){
    if (a!=NULL){
        int der=itamano(a->der),izq=itamano(a->izq);
        return der+izq+1;
    }
    else return 0;
}
int tamano(Abb a){
    return itamano(a->raiz);
}
int iminimo(Anodo* a){
    if(a==NULL)return 0;
    if(a->izq==NULL)return (a->key);
    else return iminimo(a->izq);
}
int minimo(Abb a){
    return iminimo(a->raiz);
}
int ialturade(int x, Anodo* a){
    if(a->key==x)return 0;
    else{
        if(x<a->key)return(ialturade(x,a->izq))+1;else return(ialturade(x,a->der))+1;
    }

}
int alturade(int x, Abb a){
    if(!estaEnR(x,a))return 0;
    else return ialturade(x,a->raiz);
}
void inserta(int x, Abb a){
    Anodo* p=NULL,*q;
    q=a->raiz;
    while(q!=NULL){
        p=q;
        if(x<q->key)q=q->izq;else q=q->der;
    }
    q=malloc(sizeof(Anodo));
    q->der=NULL;q->izq=NULL;q->key=x;
    if(p==NULL)a->raiz=q;
    else{
        if(x<p->key)p->izq=q;
        else p->der=q;
    }
}
int estaEn(int x,Abb a){
    Anodo*q=a->raiz;
    while(q!=NULL && x!=q->key){
        if(x<q->key)q=q->izq;
        else q=q->der;
    }
    return q!=NULL;
}
int minimoi(Abb a){
    Anodo *q=a->raiz;
    while(q->izq!=NULL)q=q->izq;
    return (q->key);
}
Anodo* iclon(Anodo* a){
Anodo* c = NULL;
if(a != NULL){
c = malloc(sizeof(Anodo));
c->key = a->key;
c->izq=iclon(a->izq);
c->der=iclon(a->der);
}
return c;
}
Abb clon(Abb a){
Abb c = newAbb();
c->tam = a->tam;
c->raiz = iclon(a->raiz);
return c;
}
int main(){
Abb a = newAbb();
Abb b= newAbb();
inserta(6,a); inserta(8,a); inserta(3,a); inserta(5,a);inserta(1,a);
enOrdenR(a);
b=clon(a);
enOrdenR(b);
int z = 0;
int k=minimo(a);
int m=minimoi(a);
if(estaEn(z,a)) printf("%d esta en a",m); else printf("%d NO esta en a");
printf("\nMision cumplida!!!!\n");

return 0;
}
