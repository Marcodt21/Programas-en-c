#include <stdio.h>

float f(float x){
    return x*x-2;
}
///Pre: f(a)*f(b) < 0, a < b, er > 0 cecano a CERO
float biseccion( float a, float b, float er){
    float m=(b+a)/2;
    int k=1;
    while (f(m)>=0+er||f(m)<=0-er){
            if(f(m)<0)a=m;
            else b=m;
            m = (b+a)/2;
            printf("\nIteracion %d, raiz=%f\n",k,m);
            k++;
            }
        return m;
}
void main(){
    float a, b,er;
    printf("\nDiga la presicion que desea, ejemplo:.000001\nprec:");
    scanf("%f",&er);
    ini: printf("Ingrese la frontera:\ni=");
    scanf("%f",&a);
    printf("f=");
    scanf("%f",&b);
    if(f(a)*f(b)>0){
            printf("Error, intente de nuevo\n");
            goto ini;
    }
    else{
            float r = biseccion(a,b,er);
    printf("Prueba del Metodo de Biseccion:\n");
    printf("\n%9.6f es una raiz de la Funcion f.",r);
    }
}
