#include <stdio.h>
#include <stdlib.h>
void escribeArreglo(int a[], char name[], int n){
int k = 0;
printf("\n%s = [", name);
while (k < n-1) {
printf("%d, ", a[k]);
k++;
}
printf("%d].", a[k]);
}
void swap(int *a, int *b){
int t = *a; *a = *b; *b = t;
}
/* Versiones del algoritmo de inserción */

void call(int a[], int n, void (*ord)(int *, int)){
ord(a,n);
}
void insertSort(int a[], int n){
int k = 1, j;
while (k<n){
j = k;
while (j > 1 && a[j-1] > a[j]) {swap(&a[j-1], &a[j]); j--;}
if (a[0] > a[1]) swap(&a[0], &a[1]);
k++;
}
}
//MUY CRACK EL PROFEEEE
void ordenarMarco(int a[],int n){
    int i=0, j;
    while(i<n){
            j=i+1;
            while(j<=n){
                 if(a[i]>a[j])swap(&a[i],&a[j]);
                j++;
            }
    i++;
    }
}
void insertSort21(int a[], int n){
int k = 1, j;
while (k<n){
j = k;
while (j > 0 && a[j-1] > a[j]) {swap(&a[j-1], &a[j]); j--;}
k++;
}
}
void insertSortM(int a[], int n){
int k = 1, j, aux;
   while (k<n){
       j = k; aux = a[k];
       while (j>=1 && a[j-1]>aux) {a[j] = a[j-1]; j--;}
       a[j] = aux;
       k++;
       }
}

void selectionSort(int a[], int n){
int i, j, pm, aux;
for (i = 0; i < n-1; i++){
pm = i; aux = a[i];
for(j = i+1; j<n; j++)
if (a[j] < aux){pm = j; aux = a[pm];}
{a[pm] = a[i]; a[i] = aux;}
}
}
void selectionSortY(int a[], int n){
int i, j, pm, aux;
for (i = 0; i < n-1; i++){
pm = i;
for(j = i+1; j<n; j++) if (a[j] < a[pm]) pm = j;
if (i != pm) {aux = a[pm]; a[pm] = a[i]; a[i] = aux;}
}
}
void intercambio(int a[], int n){
int i, j;
for (i = 0; i < n-1; i++)
for (j = i+1; j < n; j++)
if (a[j] < a[i]) swap(&a[i], &a[j]);
}
void bubbleSort(int a[], int n){
int i, j, x;
for (i = 1; i < n; i++)
for(j = n-1; j >= i; j--)
if(a[j-1] > a[j]){
x = a[j-1]; a[j-1] = a[j]; a[j] = x;
}
}
void shakeSort(int a[], int n){
int j,k, L, R;
L = 1, R = n-1, k = n-1;
do{
for (j= R; j>= L; j--)
if(a[j-1] > a[j]){swap(&a[j-1], &a[j]); k=j;}
L = k+1;
for (j= L; j<= R; j++)
if(a[j-1] > a[j]){swap(&a[j-1], &a[j]); k=j;}
R = k-1;
}while (L <= R);
}

int main(){
printf("\n Probando Ordenar:\n");
int a[] = {12, 7, 4, 9, 2, 6};
escribeArreglo(a, "a", 6);
call(a, 6, shakeSort);
escribeArreglo(a, "a", 6);
return 0;
}
