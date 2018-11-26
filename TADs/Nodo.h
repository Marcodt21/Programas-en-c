#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

typedef struct nodo{
    int val;
    struct nodo* sig;
}Nodo;
typedef Nodo* Lista;

#endif // NODO_H_INCLUDED
