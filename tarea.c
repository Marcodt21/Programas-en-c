/* 1. Recordar cómo se leen y escriben los arreglos de la entrada y salida estandard.
a) A continuación se le dan varias funciones que permiten leer, escribir e intercambiar dos elementos
de un arreglo de enteros y un main() que permite probar dichas funciones.*/

void leeArreglo(int a[], int n){
int i = 0;
while (i<n) {
printf("\na[%d] = ", i);
scanf("%d", &a[i]);
i++;
}
}
void escribeArreglo(int a[], int n){
int i = 0;
printf("\n[ ");
while (i < n-1) printf(" %d,",a[i++]);
if (n > 0) printf(" %d]",a[i]); else printf("]");
}
void swap(int *a, int *b){
int t = *a; *a = *b; *b =t;
}

/*b) Escriba las funciones que se indican a continuación y use leerArreglo y escribeArreglo para probarlas.
1) Una función que reciba tres arreglos de enteros a; b; c y sume los elementos de los arreglos a; b
en el arreglo c.*/

void sumarArreglos(int a[], int b[], int c[], int n){
   int k=0;
   while(k<n){
      c[k]=a[k]+b[k];
      k++;
    };
}

/*2) Una función que halle la posición de la primera ocurrencia del máximo de los elementos del
arreglo de enteros a en sus primeras n casillas.*/
  
int max(int a[], int n){
   int k=0,max=a[0],p=0;
   while(k<n){
      if(a[k]>max){
         max=a[k];
         p=k;
      };
      k++;
    }
   return p;
}

//2. Búsqueda Lineal Acotada y no Acotada.

int pertenece(int x, int n, int a[]){
int k = 0;
while(k<n && a[k] != x) k++;
return k < n;
}

int primaOcur(int x, int n, int a[]){
int k = 0;
while(k<n && a[k] != x) k++;
return k;
}

//a) Haga un NUEVO programa que permita probar los algoritmos de búsqueda lineal vistos en clase:

void main(){
   int n=10,a[n];
   int x, p;
   printf("Ingrese los valores del arreglo");
   leeArreglo(a,n);
   printf("\nEl resultado del arreglo fue el siguiente\n");
   escribeArreglo(a,n);
   printf("\nEscriba el numero a buscar\n");
   scanf("%d",x);
   if(pertenece(x, n, a)==1){
   p=primaOcur(x, n, a)
   printf("\nSi pertenece y su posicion es %d",p);
   }
   else printf("\nNo pertenece\n");
 } 
   
/*b) Modique los algoritmos anteriores agregando lo que se busca en a[n]primera casilla vacíay
eliminando k < n de la condición. Nota: De esta manera la búsqueda se fuerza a ser fructuosa y
no-acotada!*/

int pertenece2(int x, int n, int a[]){
   int k=0;
   a[n]=x;
   while(a[k]!=x)k++;
   return k!=n;
}

int posicion(int x, int n, int a[]){
   int k=0;
   a[n]=x;
   while(a[k]!=x)k++;
   return k;
}

/*c) Búsquedas sin ArreglosPrimalidad Use el esquema de búsqueda del ejercicio anterior para
decidir si un entero positivo mayor que 1 es primo.*/

int esPrimo(int x){   
   int k=2;// ya que el 1 no se considera como un numero primo
   while(k<x && x%k!=0)k++;
   return k==x;
}

/*d) Use el hecho de que n divide a n para sabiendo que la búsqueda va ser fructuosa eliminar k < n
de la condición.*/

int esPrimo2(int x){
  int k=2;
  while(x%k!=0)k++;
  return k==x;
}

/*3.- Búsqueda Binaria 
b) Escriba el algoritmo de búsqueda binaria en el caso que el arreglo de entrada esté ordenado no
crecientemente.*/

int busquedabinaria (int E, int n, int a[])
{   int x=0, y=n, m;
    while (x+1!=y){
        m=(y+x)/2;
        if (E>=a[m]) y=m;
        else x=m;
    }
    return a[y]==E;
}

/*c) Escriba un algoritmo que genere un arreglo de enteros aleatorios en el intervalo [0; 100), lo ordene
y luego haga varias búsquedas binarias sobre él.*/

#include <stdio.h>
#include <time.h>

void swap(int*a, int *b);
int bb(int E, int n, int a[]);
void arregloAleatorio(int a[], int n);
void intercambioM(int a[], int n);

int main()
{
    int n=5, a[n], k;
    arregloAleatorio(a, n);
    intercambioM(a , n);

    printf("\nBusqueda 1: Número 6 ");
    if (bb(6, n, a)) printf("\n Exitosa"); else printf("\n NO Exitosa");
    printf("\nBusqueda 2: Numero 49");
    if (bb(6, n, a)) printf("\n Exitosa"); else printf("\n NO Exitosa");

    return 0;
}

int bb(int E, int n, int a[])
{   int x=0, y=n, m;
    while (x+1!=y){
        m=(x+y)/2;
        if (E<a[m]) y=m;
        else x=m;
    }
    return a[x]==E;
}

void swap(int*a, int *b){
    int t=*a; *a=*b; *b=t;
}

void intercambioM(int a[], int n){
    int i, j, m;
    for(i=0; i<n-1; i++){
        m=i;
        for(j=i+1; j<n; j++) if(a[j]<a[m]) m=j;
        if(i!=m) swap(&a[i] , &a[m]);
    }
}

void arregloAleatorio(int a[], int n){
    int i=0;
    srand(time(NULL));
    while (i<n){
        a[i]= 0+ rand() % ((100+0)-0);
        printf("%d", a[i]);
        i++;
    }
}



/*d) Modifique el algoritmo de búsqueda binaria que se da para que devuelva el lugar donde lo encontró
o n si no lo encontró.*/

int bbp(int E, int n, int a[])
{   int x=0, y=n, m, p=n;
    while (x+1!=y){
        m=(x+y)/2;
        if (E==a[m]) p=m;
        if (E<a[m]) y=m;
        else x=m;
    }
    return p;
}
