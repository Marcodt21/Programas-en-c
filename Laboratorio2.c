#include<stdio.h>

int factR(int x){
    if(x==0)return 1;
    else return factR(x-1)*x;
}
int fact(int x){
    int r=1,y=0;
    while(y<x){r=r*(y+1);
    y++;};
    return r;
}

void main(){
    int x,m;
    printf("\nIngrese un numero para calcular su factorial:");
    scanf("%d",&x);
    printf("\nSeleccione el metodo a utilizar:\n1)Recusivo\n2)Iterativo\n");
    scanf("%d",&m);
    if(m==1)printf("\nfact(%d)=%d",x,factR(x));
    else printf("\nfact(%d)=%d",x,fact(x));
}
