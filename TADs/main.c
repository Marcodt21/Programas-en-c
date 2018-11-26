#include <stdio.h>
#include <stdlib.h>
#include "Nodo.h"
#include "Pila.h"
#include "Cola.h"
#include "ColaAC.h"
#include "PilaArr.h"
void imprimePilaL(PilaL p){
    printf("[");
    while(p!=NULL){
        printf("%d ",topL(p));
        popL(&p);
    }
    printf("]");
}
void imprimePilaA(PilaA p){
    printf("[");
    while(!esVaciaPA(p)){
        printf("%d ",topA(p));
        pop(p);
    }
    printf("]");
}
void imprimeColaL(ColaL c){
    printf("[");
    while(!esVaciaCL(c)){
        printf("%d ",first(c));
        enqueue(c);
    }
    printf("]");
}
void imprimeColaA(ColaC c){
    printf("[");
    while(!esVaciaCC(c)){
        printf("%d ",firstCC(c));
        dqueue(c);
    }
    printf("]");
}
int main(){
int m,ca,pa,colx,pilx,x;
PilaL p=newPilaL();
PilaA par=newPilaA(10);
ColaC c=newColaC(10);
ColaL coll=newColaL();
do{
    printf("\n1)Pila con Lista\n2)Cola con lista\n3)Pila con arreglo\n4)Cola con arreglo\n5)Salir\n");
    scanf("%d",&m);
    switch(m){
        case 1:{
            do{
                printf("\n1)Es vacia\n2)Top\n3)Push\n4)Pop\n5)Imprimir\n6)Salir\n");
                scanf("%d",&pilx);
                switch(pilx){
                    case 1:{
                        if(esVaciaPL(p))printf("\nEs vacia");
                        else printf("\nNo es vacia");
                        break;
                    }
                    case 2:{
                        if(esVaciaPL(p))printf("\nError");
                        else printf("\n%d",topL(p));
                        break;
                    }
                    case 3:{
                        printf("\nIngrese un numero:");
                        scanf("%d",&x);
                        pushL(x,&p);
                        break;
                    }
                    case 4:{
                        if(esVaciaPL(p))printf("\nError");
                        else popL(&p);
                        break;
                    }
                    case 5:{
                        imprimePilaL(p);
                        break;
                    }
                }
            }while(pilx<6);
            break;
        }
        case 2:{
            do{
                 printf("\n1)Es vacia\n2)First\n3)Queue\n4)Enqueue\n5)Imprimir\n6)Salir");
                scanf("%d",&colx);
                switch(colx){
                    case 1:{
                        if(esVaciaCL(coll))printf("\nEs vacia");
                        else printf("\nNo es vacia");
                        break;
                    }
                    case 2:{
                        if(esVaciaCL(coll))printf("\nError");
                        else printf("\n%d",first(coll));
                        break;
                    }
                    case 3:{
                        printf("\nIngrese un numero:");
                        scanf("%d",&x);
                        queue(x,coll);
                        break;
                    }
                    case 4:{
                        if(esVaciaCL(coll))printf("\nError");
                        else enqueue(coll);
                        break;
                    }
                    case 5:{
                        imprimeColaL(coll);
                        break;
                    }
                }
            }while(colx<6);
            break;
        }
        case 3:{
            do{
              printf("\n1)Es vacia\n2)Top\n3)Push\n4)Pop\n5)Esta Full\n6)Imprimir\n7)Salir");
                scanf("%d",&pa);
                switch(pa){
                    case 1:{
                         if(esVaciaPA(par))printf("\nEs vacia");
                        else printf("\nNo es vacia");
                        break;
                    }
                    case 2:{
                        if(esVaciaPA(par))printf("\nError");
                        else printf("\n%d",topA(par));
                        break;
                    }
                    case 3:{
                        printf("\nIngrese un numero:");
                        scanf("%d",&x);
                        PushA(x,par);
                        break;
                    }
                    case 4:{
                        if(esVaciaPA(par))printf("\nError");
                        else pop(par);
                        break;
                    }
                    case 5:{
                        if(esFull(par))printf("\nEsta full");
                        else printf("\nNo esta full");
                        break;
                    }
                    case 6:{
                        imprimePilaA(par);
                        break;
                    }
                }
            }while(pa<7);
            break;
        }
        case 4:{
            do{
                printf("\n1)Es vacia\n2)First\n3)Queue\n4)Enqueue\n5)Esta Full\n6)Imprimir\n7)Salir\n");
                scanf("%d",&ca);
                switch(ca){
                    case 1:{
                        if(esVaciaCC(c))printf("\nEs vacia");
                        else printf("\nNo es vacia");
                        break;
                    }
                    case 2:{
                        if(esVaciaCC(c))printf("\nError");
                        else printf("\n%d",firstCC(c));
                        break;
                    }
                    case 3:{
                        printf("\nIngrese un numero:");
                        scanf("%d",&x);
                        queueC(x,c);
                        break;
                    }
                    case 4:{
                        if(esVaciaCC(c))printf("\nError");
                        else dqueue(c);
                        break;
                    }
                    case 5:{
                        if(estaFull(c))printf("\nEsta full");
                        else printf("\nNo esta full");
                        break;
                    }
                    case 6:{
                        imprimeColaA(c);
                        break;
                    }
                }
            }while(ca<7);
            break;
        }
    }
}while(m<5);
return 0;
}
