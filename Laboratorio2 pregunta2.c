#include<stdio.h>

int mcd(int a, int b){
    int n;
    if(a>=b)n=b;
    else n=a;
    while(n>1&&(a%n!=0 || b%n!=0))n--;
    return n;
}
int mcdR(int a,int b){
    if(a%b==0)return b;
    else return mcdR(b,a%b);
}
void main(){
    int a,b,m;
    printf("\nIngrese dos numeros para calcular el MCD:");
    scanf("%d %d",&a,&b);
    printf("\nSeleccione el metodo a utilizar:\n1)Recusivo\n2)Iterativo\n");
    scanf("%d",&m);
    if(m==1)printf("\n%d",mcdR(a,b));
    else printf("\n%d",mcd(a,b));
}
