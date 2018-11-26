#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include "Nodo.h"
typedef Nodo* PilaL;

PilaL newPilaL(){
    return NULL;
    }
int esVaciaPL(PilaL p){
    return p==NULL;
}
int topL(PilaL p){
    return p->val;
}
void pushL(int x, PilaL *p){
    Nodo* q=malloc(sizeof(Nodo));
    q->val=x;
    q->sig=*p;
    *p=q;
}
void popL(PilaL* p){
    Nodo* q=*p;
    *p=(*p)->sig;
    free(q);
}
#endif // PILA_H_INCLUDED
