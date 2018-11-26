#ifndef PILAARR_H_INCLUDED
#define PILAARR_H_INCLUDED
typedef struct pilaArr{
    int top;
    int *a;
    int n;
}PilaArr;
typedef PilaArr* PilaA;
PilaA newPilaA(int siz ){
    PilaA p=malloc(sizeof(PilaArr));
    p->a=malloc(siz*sizeof(int));
    p->top=0;
    p->n=siz;
    return p;
}
int esVaciaPA(PilaA p){
    return p->top==0;
}
int esFull(PilaA p){
    return p->top==p->n;
}
int topA(PilaA p){
    return p->a[p->top-1];
}
void PushA(int x,PilaA p){
    (p->a)[p->top]=x;
    (p->top)++;
}
void pop(PilaA p){
    (p->top)--;
}
#endif // PILAARR_H_INCLUDED
