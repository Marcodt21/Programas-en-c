#include<stdio.h>
int bb(int E, int n, int a[]){
int x = 0, y = n, m;
while (x+1 != y){
m = (x+y)/2;
if (E < a[m]) y = m; else x = m;
}
return a[x] == E;
}
void leerArreglo(int a[],int n){
    int k=0;
    printf("\nCompletamos el arreglo");
    while(k<n){
        printf("\nIngrese el valor de la posicion A[%d]=",k);
        scanf("%d",&a[k]);
        k++;
    }
}
void escribirArreglo(int a[],int n){
    int k=0;
    printf("\n[");
    while(k<n)printf("%d ",a[k++]);
    printf("]\n");
}
int bbR(int E, int x, int y, int a[]){
    if(x+1==y)return a[x] == E;
    else {
        int n;
        n=(x+y)/2;
        if(E>=a[n])x=n;
        else y=n;
        return bbR(E, x, y, a);
    };
}
int posbbR(int E, int x, int y, int a[]){
    if(x+1==y){
            if(a[x] == E)return x;
            else return 0;
    }
    else {
        int n;
        n=(x+y)/2;
        if(E>=a[n])x=n;
        else y=n;
        return posbbR(E, x, y, a);
    };
}
void main(){
    int n=8,b;
    int a[n];
    leerArreglo(a,n);
    escribirArreglo(a,n);
    printf("\nNumero que busca\n");
    scanf("%d",&b);
    if(bbR(b,0,n,a)==1)printf("\nSe encuentra en el arreglo");
    else printf("\nNo se consiguio");
    if(posbbR(b,0,n,a)==0)printf("\nPosicion n");
    else printf("\nPosicion %d",posbbR(b,0,n,a));
}
