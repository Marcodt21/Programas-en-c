#ifndef COLAAC_H_INCLUDED
#define COLAAC_H_INCLUDED
typedef struct colC{
    int cap;
    int alfa;
    int omega;
    int *a;
    int tam;
}ColC;
typedef ColC* ColaC;
ColaC newColaC(int maxsize){
    ColC* p=malloc(sizeof(ColC));
    p->cap=maxsize;
    p->alfa=0;
    p->omega=0;
    p->a=malloc(maxsize*sizeof(int));
    p->tam=0;
    return p;
}
int esVaciaCC(ColaC c){
    return c->tam==0;
}
int estaFull(ColaC c){
    return c->tam==c->cap;
}
int firstCC(ColaC c){
    return c->a[c->alfa];
}
void queueC(int x, ColaC c){
    c->a[c->omega]=x;
    c->omega=(c->omega+1)%c->cap;
    (c->tam)++;
    if(c->tam==c->cap){
        int newsize=1.5*c->cap;
        int *b=malloc(newsize*sizeof(int));
        int k;
        for(k=0;k<(c->cap);k++){b[k]=(c->a)[(c->alfa+k)%c->cap];}
        free(c->a);
        c->alfa=0;
        c->omega=k;
        c->cap=newsize;
        c->a=b;
    }
}
void dqueue(ColaC c){
    c->alfa=c->alfa+1;
    (c->tam)--;
}
#endif // COLAAC_H_INCLUDED
