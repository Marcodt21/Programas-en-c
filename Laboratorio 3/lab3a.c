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
void insertSort(int a[], int n){
int k = 1, j;
while (k<n){
j = k;
while (j > 1 && a[j-1] > a[j]) {swap(&a[j-1], &a[j]); j--;}
if (a[0] > a[1]) swap(&a[0], &a[1]);
k++;
}
}
void call(int a[], int n, void (*ord)(int *, int)){
ord(a,n);
}
int main(){
printf("\n Probando Ordenar:\n");
int a[] = {12, 7, 4, 9, 2, 6};
escribeArreglo(a, "a", 6);
call(a, 6, insertSort);
escribeArreglo(a, "a", 6);
return 0;
}
