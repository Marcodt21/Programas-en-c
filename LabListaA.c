#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int val;
    struct nodo *sig;
}Nodo;
typedef Nodo* Lista;

Lista NewList(){
    return NULL;
}
void insertCab(int x, Lista*L){
    Nodo*q=malloc(sizeof(Nodo));
    q->val=x;
    q->sig=*L;
    *L=q;
}
int esVacia(Lista L){
    return L==NULL;
}
int firstInList(Lista L){
    return L->val;
}
int estaEn(int x, Lista L){
    Nodo *q=L;
    while(q!=NULL && q->val!=x)q=q->sig;
    return q!=NULL;
}
///Escribe la lista L de nombre name entre dos corchetes
void escribeLista(char name[], Lista L){
    printf("\n%s=[",name);
    if(L==NULL)printf("]");
    else{
        Nodo *q=L;
        while(q->sig!=NULL){
                printf("%d ",q->val);
                q=q->sig;
        }
        printf("%d]",q->val);
    }
}
void insertT(int x,Lista *L){
    Nodo*q=malloc(sizeof(Nodo)),*p;
    if(*L==NULL){
        q->val=x;
        q->sig=*L;
        *L=q;
    }
    else{
        p=*L;
        while(p->sig!=NULL)p=p->sig;
    q->val=x;
    q->sig=p->sig;
    p->sig=q;
    }
}
void elimina1(int x, Lista*L){
    Nodo*q=*L,*p;
    while(q!=NULL&&(q->val)!=x){
            p=q;
            q=q->sig;
    }
    if(q!=NULL){
        p->sig=q->sig;
        free(q);
    }
}
void copia(Lista L){
    Lista k=NewList();
    Nodo*q=malloc(sizeof(Nodo));
    k=q;
    if(L!=NULL){
        while(L->sig!=NULL){
            q->val=L->val;
            q->sig=malloc(sizeof(Nodo));
            q=q->sig;
            L=L->sig;
        }
        q->val=L->val;
        q->sig=NULL;
        }
     escribeLista("Lista2",k);
}
void main(){
    int op;
    Lista l=NewList();
    char name[6]="Lista";
    int x;
    do{
    printf("\nMarque con un numero la opcion deseada:\n1)Eliminar valor\n2)Ingresar un valor en la cabeza de la lista \n3)Verificar si es vacia la lista \n4)Primer valor de la lista \n5)Buscar valor en la lista \n6)Imprimir lista \n7)Insertar valor al final\n8)Salir\n9)Copiar lista\n");
    scanf("%d",&op);
    switch(op){
        case 1:{
            printf("\nIngrese valor a eliminar:");
            scanf("%d",&x);
            elimina1(x,&l);
            break;
        }
        case 2:{
            printf("\nIngrese valor:");
            scanf("%d",&x);
            insertCab(x,&l);
            break;
        }
        case 3:{
            if(esVacia(l)==1)printf("\nLa lista si es vacia");
            else printf("\nNo es vacia");
            break;
        }
        case 4:{
            printf("\nEl primer valor de la lista es %d",firstInList(l));
            break;
        }
        case 5:{
            printf("\nIngrese el numero que busca:");
            scanf("%d",&x);
            if(estaEn(x,l)==1)printf("\nEl numero %d, si se encuentra en la lista",x);
            else printf("\nEl numero  %d no se encuentra",x);
            break;
        }
        case 6:{
            escribeLista(name,l);
            break;
        }
        case 7:{
            printf("\nIngrese valor:");
            scanf("%d",&x);
            insertT(x,&l);
            break;
        }
        case 9:{
            copia(l);
            break;
        }
    }
    }
            while(op!=8);
}
