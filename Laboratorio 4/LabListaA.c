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
    if(q!=NULL){
       if(q->val==x){
        p=q;
        q=q->sig;
        free(p);
       }
       else while(q!=NULL&&(q->val)!=x){
        p=q;
        q=q->sig;
       }
       if(q!=NULL){
        p->sig=q->sig;
        free(q);
       }

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
int sizeR(Lista L){
if(L == NULL) return 0;
else return 1+ sizeR(L->sig);
}
int estaEnR(int x, Lista L){
    if(L==NULL||L->val==x)return L!=NULL;
    else estaEnR(x,L->sig);
}
void insertTR(int x,Lista *L){
    if(*L==NULL){
        Nodo*q=malloc(sizeof(Nodo));
        q->val=x;
        q->sig=NULL;
        *L=q;
    }
    else insertTR(x,&(*L)->sig);
}
void eliminaR(int x, Lista *L){
if (*L != NULL){
if ((*L)->val == x) {
Nodo *p = *L;
*L = (*L)->sig;
free(p);
}
else eliminaR(x, &((*L)->sig));
}
}
int sizeI(Lista L){
    int k=0;
    while(L!=NULL){
        L=L->sig;
        k++;
    }
    return k;
}
int maxR(Lista L){
    if(L->sig!=NULL){
       Nodo*q=L;
       if(q->val>=(q->sig)->val){
            q->sig=(q->sig)->sig;
            maxR(&*q);
       }
       else maxR(L->sig);

    }
    else return L->val;
}
void separaParImpar(Lista *L, Lista *K){
    if(*L!=NULL){
       Lista I=NewList();
       Nodo *q=*L;
       Nodo *p;
       Nodo *r;
       while(q!=NULL){
          if((q->val%2)==1){
             p=q;
             q=q->sig;
             p->sig=I;
             I=p;
             }
           else{
              r=q;
              q=q->sig;
              r->sig=*K;
              *K=r;
            }
          }
       *L=NULL;
       q=*K;
       while(q!=NULL){
          p=q;
          q=q->sig;
          p->sig=*L;
          *L=p;
         }
       *K=NULL;
        q=I;
       while(q!=NULL){
           p=q;
           q=q->sig;
           p->sig=*K;
           *K=p;
       }
       }
}
void main(){
    int op,m,opR;
    Lista l=NewList();
    char name[6]="Lista";
    int x;
    do{
            printf("\nSeleccionar metodo a utilizar.\n1)Iteratico\n2)Recursivo\n3)Salir\n");
            scanf("%d",&m);
            switch(m){
                case 1:{
    printf("\nMarque con un numero la opcion deseada:\n1)Eliminar valor\n2)Ingresar un valor en la cabeza de la lista \n3)Verificar si es vacia la lista \n4)Primer valor de la lista \n5)Buscar valor en la lista \n6)Imprimir lista \n7)Insertar valor al final\n8)Copiar lista\n9)Tamaño de la lista\n10)");
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
        case 8:{
            copia(l);
            break;
        }
        case 9:{
            printf("La lista tiene un tamaño de %d",sizeI(l));
            break;
        }
        case 10:{
            Lista K=NewList();
            separaParImpar(&l,&K);
            escribeLista(name, l);
            escribeLista(name, K);
        }

    }
    break;
                }
            case 2:{
                printf("\nMarque con un numero la opcion deseada:\n1)Tamaño de lista\n2)Buscar elemento\n3)Insertar en cola\n4)Eliminar elemanto\n5)Hallar el maximo en la lista\n");
                scanf("%d",&opR);
                switch(opR){
                    case 1:{
                    printf("\nEl tamaño de la lista es %d",sizeR(l));
                    break;
                }
                    case 2:{
                        printf("\nIngrese el numero a buscar:");
                        scanf("%d",&x);
                        if(estaEnR(x,l)==1)printf("\nEl numero %d si se encuentra en la lista",x);
                        else printf("\nNo se encontro en la lista");
                        break;
                    }
                    case 3:{
                        printf("Ingrese el numero a insertar:");
                        scanf("%d",&x);
                        insertTR(x,&l);
                        break;
                    }
                    case 4:{
                        printf("Ingrese el numero a eliminar:");
                        scanf("%d",&x);
                        eliminaR(x,&l);
                        break;
                    }
                    case 5:{
                        printf("El maximo de la lista es %d",maxR(l));
                        break;
                    }
                break;
            }
    }
    }
    }
            while(m!=3);
}
