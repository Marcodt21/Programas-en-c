#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
    int val;
    struct nodo* sig;
}Nodo;

typedef Nodo* Lista;
//Pilas
typedef Nodo* Pila;

Pila newPila(){
    return NULL;
}

int noEsVacia(Pila p){
    return p==NULL;
}

int Top(Pila p){
    return p->val;
}

void push(int x, Pila *p){
    Nodo* q=malloc(sizeof(Nodo));
    q->val=x;
    q->sig=*p;
    *p=q;
}

void pop(Pila *p){
    Nodo*q=*p;
    (*p)=q->sig;
    free(q);
}
//Colas
typedef col{
    Nodo* alfa;
    Nodo* omega;
}Col

typedef Col* Cola;

Cola newCola(){
    Cola c = malloc(sizeof(Col));
    c->alfa = NULL;
    c->omega = NULL;
    return c;
}

void queue(int x, Cola c){
    Nodo* q = malloc(sizeof(Nodo));
    q->val = x;
    q->sig = NULL;
    if(c->omega != NULL) (c->omega)->sig = q; else c->alfa = q;
    c->omega = q;
}

void dqueue(Cola c){
    Nodo* q = c->alfa;
    if(c->alfa == c->omega) c->omega = NULL;
    c->alfa = q->sig;
    free(q);
}

//Conjuntos

typedef struct conj {
    int MAX;
    int* a;
    int tam;
} Conj;

typedef Conj* Conjunto;

Conjunto newConjunto(int max_tam){
    Conjunto c = malloc(sizeof(Conj));
    c->tam = 0;
    c->MAX = max_tam;
    c->a = malloc(max_tam*sizeof(int));
    return c;
}

int esVacio(Conjunto c){ return c->tam == 0; }

int pertenece(int x, Conjunto c){
    int k = 0;
    while(k < c->tam && x != (c->a)[k]) k++;
    return k < c->tam;
}

int card(Conjunto c){ return c->tam; }

void escribeConjunto(Conjunto c, char* name){
    printf("\n%s = {", name);
    int k = 0;
    while(k < c->tam -1) printf("%d, ", (c->a)[k++]);
    printf("%d}", (c->a)[k]);
}

void reSize(Conjunto c){
    int newSize = 1.3*c->MAX +1, k = 0;
    int * b = malloc(newSize*sizeof(int));
    while(k < c->tam) b[k] = c->a[k++];
    c->MAX = newSize;
    free(c->a);
    c->a = b;
}

void agregar(int x, Conjunto c){
    int k = 0;
    while(k<c->tam && x != (c->a)[k]) k++;
    if(k >= c->tam) (c->a)[(c->tam)++] = x;
    if(c->tam == c->MAX) reSize(c);
}

void remover(int x, Conjunto c){
    int k = 0;
    while(k < c->tam && x != (c->a)[k]) k++;
    if(k < c->tam) (c->a)[k] = (c->a)[--(c->tam)];
}

typedef struct ite {
    Conjunto t;
    int ind;
} Ite;

typedef Ite* Iter;

Iter newIter(Conjunto c){
    Iter i = malloc(sizeof(Ite));
    i->t = c; i->ind = 0;
    return i;
}

int hasNext(Iter i){
    return i->ind < (i->t)->tam;
}
int next(Iter i){
    return ((i->t)->a)[(i->ind)++];
}

Conjunto differ(Conjunto a, Conjunto b){
    Conjunto c;
    int e;
    int ca=card(a),
    c=newConjunto(ca);
    Iter i=newIter(a);
    while(hasNext(i)){
        e=next(i);
        if(!pertenece(e,b))agregar(e,c);
    }
    return c;
}

Conjunto unir(Conjunto a, Conjunto b){
    Conjunto c=newConjunto(card(a)+card(b));
    Iter ia=newIter(a), ib=newIter(b);
    while(hasNext(ia)){
        agregar(next(ia),c);
    }
    while(hasNext(ib)){
        agregar(next(ib),c);
    }
    return c;
}

int subseteq(Conjunto a, Conjunto b){
    Iter i = newIter(a); int e;
    while(hasNext(i)){
        e = next(i);
        if(!pertenece(e,b))return 0;
    }
    return 1;
}

int equals(Conjunto a, Conjunto b){
    if(card(a)!=card(b))return 0;
    else{
        Iter i=newIter(a);
        while(hasNext(i)){
            if(!pertenece(next(i),b))return 0;
        }
        return 1;
    }    
}

//Arboles binarios de busqueda

typedef struct anodo{
    int key;
    struct anodo*izq;
    struct anodo*der;
}Anodo;

typedef struct raiz{
    Anodo* raiz;
    int tam;
}Raiz;

typedef Raiz* Abb;

Abb newAbb(){
    Abb a = malloc(sizeof(Raiz));
    a->raiz = NULL;
    a->tam = 0;
    return a;
}

int esVacio(Abb a){
    return a->raiz == NULL;
}

int EstaEnA(int x, Abb a){
    return iEstaEn(x, a->raiz);
}
int iEstaEn(int x, Anodo *a){
    if(a==NULL)return 0;
    if(x==a->key)return 1;
    if(x<(a->key))return iEstaEn(x,a->izq);
    else iEstaEn(x->a->der);
}

void insertaA(int x, Abb a){
    a->tam ++;
    iinsertaA(x, a->raiz);
}

void iinserta(int x, Anodo* *a){
    if(*a == NULL){
        (*a) = malloc(sizeof(Anodo));
        (*a)->key = x;
        (*a)->izq = NULL;
        (*a)->der = NULL;
    }
    else {
            if(x < (*a)->key) iinserta(x, &((*a)->izq));
            else iinserta(x, &((*a)->der));
    }
}