

int pertenece(int x,int n, int a[]){
   int k=0;
   a[n+1]=x;
   while(a[k]==x)k++;
   return k==n+1;
}
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
void main(){
   int n=4;
   int a[n];
   leeAreglo(a, n);
   escribeArreglo(a, n);


}
