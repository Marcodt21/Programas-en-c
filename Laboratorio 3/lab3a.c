#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
   char nombre[20];
   float precio;
   char marca[20];

}producto;

int comparaPro(const void * a, const void * b){
    producto *pa=(producto*)a;
    producto *pb=(producto*)b;
    return (pa->precio - pb->precio);

}

int main (){
    int i;
    producto p[3]={{"fiesta", 5000, "ford"}, {"spark", 4000, "chevrolet"}, {"Yaris", 7000, "Toyota"}};
    qsort(p,3, sizeof(producto), comparaPro);

    for(i=0; i<3; i++){
    printf("%d. %s, %f, %s \n" ,i+1, p[i].nombre,  p[i].precio, p[i].marca);
    };

    producto *busqueda = (producto*) bsearch(&p[0], p, 3, sizeof(producto), comparaPro);

    printf(" %s, %f, %s \n" , busqueda->nombre,  busqueda->precio, busqueda->marca);

}
