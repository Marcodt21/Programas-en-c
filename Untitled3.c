#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x){
return x*x - 2;
}
///Pre: f(a)*f(b) < 0, a < b, er > 0 cecano a CERO
float biseccion( float a, float b, float er){
float m=(b+a)/2;
while (f(m)<=0+er||f(m>=0-er)){
    m = (b+a)/2;
    if(fabs(f(a))<fabs(f(b)))b=m;
    else a=m;
}
return m;
}