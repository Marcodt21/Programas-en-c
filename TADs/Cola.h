#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include"Nodo.h"
typedef struct colL{
    Nodo* alfa;
    Nodo* omega;
}ColL;
typedef ColL* ColaL;
ColaL newColaL(){
    ColL*q=malloc(sizeof(ColL));
    q->alfa=NULL;
    q->omega=NULL;
    return q;
}
int esVaciaCL(ColaL c){
    return c->alfa==NULL;
}
int first(ColaL c){
    return (c->alfa)->val;
}
void queue(int x, ColaL c){
    Nodo*q=malloc(sizeof(Nodo));
    q->val=x;
    q->sig=NULL;
    if(c->alfa==NULL){
        c->alfa=q;
        c->omega=q;
    }
    else{
        (c->omega)->sig=q;
        c->omega=q;
    }
}
void enqueue(ColaL c){
    Nodo*q=c->alfa;
    c->alfa=(c->alfa)->sig;
    free(q);
}
#endif // COLA_H_INCLUDED
