#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x){
return x*x - 15;
}
///Pre: f(a)*f(b) < 0, a < b, er > 0 cecano a CERO
float biseccion( float a, float b, float er){
float m=(b+a)/2;
while (f(m)>=0+er||f(m)<=0-er){
    if(f(m)<0)a=m;
    else b=m;
    m = (b+a)/2;
}
return m;
}
void main(){
float a = 1, b =6;
float r = biseccion(a,b,.000001);
printf("Prueba del Metodo de Biseccion:\n");
printf("\n%9.6f es una raiz de la Funcion f.",r);
}
