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

int reduc(int a, int b){
    int n=mcd(a,b);
    a=a/n;
    b=b/n;
    printf("\nLa fraccion mas reducida sera %d/%d",a,b);
}

int mcm(int a, int b){
    int n=(a*b)/mcdR(a,b);
    return n;
}
void main(){
    int a,b,m;
    printf("\nIngrese dos numeros para calcular el MCD:\na=");
    scanf("%d",&a);
    printf("\nb=");
    scanf("%d",&b);
    printf("\nSeleccione el metodo a utilizar:\n1)Recusivo\n2)Iterativo\n");
    scanf("%d",&m);
    if(m==1)printf("\nMCD=%d",mcdR(a,b));
    else printf("\nMCD=%d",mcd(a,b));
    printf("\n1)Reducir la fraccion %d/%d\n2)Reducir la fraccion %d/%d \n3)No\n",a,b,b,a);
    scanf("%d",&m);
    switch(m){
        case 1:reduc(a,b);
        break;
        case 2:reduc(b,a);
        break;
    }
    printf("\nCalcular mcm:\n1)Si\n2)No\n");
    scanf("%d",&m);
    if(m==1)printf("\nEl mcm sera %d",mcm(a,b));
}
