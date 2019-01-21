#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void swap(char *a, char *b){
    int t = *a;
    *a = *b;
    *b = t;
}
void qSortL(char **a, int l, int u){
    int i;
    if (l < u){
        int m = l;
        for (i = l+1; i <= u; i++)if (strcmp(a[i] , a[l])<0) swap(&a[++m], &a[i]);
        swap(&a[l], &a[m]);
        qSortL(a, l, m-1);
        qSortL(a, m+1, u);
    }
}
void qSortH(char **a, int l, int u){
    if (l < u){
        char* t = a[l], i = l, j = u+1;
        while (i <= j){
            do i++; while(i <= u && strcmp(a[i] , t)<0);
            do j--; while (strcmp(a[j] , t)>0);
            if (i <= j) swap(&a[i], &a[j]);
        }
        swap(&a[l], &a[j]);
        qSortH(a, l, j-1);
        qSortH(a, j+1, u);
    }
}
int main(){
    int k;
    char *s[6] = {"zixia", "calor", "amargura", "amor", "amar","puta"};
    for (k = 0; k< 6; k++) printf("%s, ", s[k]);
    printf("\n");
    qSortH(s, 0,5);
    for (k = 0; k< 6; k++) printf("%s, ", s[k]);
    return 0;
}

