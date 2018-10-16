#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x){
return x*x - 2;
}
///Pre: f(a)*f(b) < 0, a < b, er > 0 cecano a CERO
float biseccion( float a, float b, float er){
float m=(b+a)/2;
while (f(m)<=0+er||f(m)>=0-er){
        if(f(m)<0)a=m;
        else b=m;
        m=(a+b)/2;
        printf("%f",m);
}
return m;
}
int main(){
float a = 1.0, b = 2.0; //Cambie el intervalo de búsqueda ...??
float r = biseccion(a,b,.02);
printf("\nPrueba del Metodo de Biseccion:\n");
printf("\n%9.6f es una raiz de la FUNCION f.",r);
return 0;
}
