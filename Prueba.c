#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int compInt(const void *a, const void *b){
    int *aa=(int*)a;
    int *bb=(int*)b;
    return -(*aa-*bb);
}

int comparapa(const void *a, const void *b){
    int *aa=(int*)a;
    int *bb=(int*)b;
    if(*aa%2==0&&*bb%2==0)return *aa-*bb;
    else {if(fabs(*aa%2)==1&&fabs(*bb%2)==1)return *bb-*aa;
         else {if(*aa%2==0)return -fabs(*aa);
              else if(*bb%2==0)return fabs(*aa);
         }
    }
}
 comparadorLindo(void const *a, void const *b){
                int c= *(int*)a, d=*(int*)b;
                if(c%2==0 && d%2 ==0)return c-d;
                    else if(c%2==1 && d%2 ==1) return d-c;
                        else if(c%2==0) return -fabs(c);
                            else if(d%2==0) return fabs(d);
 }
void main(){
   int n=10;
   int a[n];
   leerArreglo(a,n);
   qsort(a,n,sizeof(int),comparapa);
   escribirArreglo(a,n);
}
