#include <stdio.h>

int sort(int *a, int *b){
        int tmp = *a;
        *a = *b;
        *b = tmp;
        return 0;
}
int main(){
        int n,step=0,b;
        scanf("%d", &n);
        int a[n];
        for (int i=0;i<n;i++) scanf("%d", &a[i]);
        while (1) {
                b=0;
                for (int i=0;i<n;++i){
                        if (i*2 +2 +step<n){
                                if (a[i +step] > a[i*2 +1 +step] || a[i +step] > a[i*2 +2 +step]){
                                        if (a[i*2 +1 +step] < a[i*2 +2 +step]){
                                                sort(&a[i +step], &a[i*2 +1 +step]);
                                                b=1;
                                        }
                                        else if (a[i*2+2+step] < a[i*2+1+step]){
                                                sort(&a[i+step],&a[i*2+2+step]);
                                                b=1;
                                        }
                                }
                        }
                        else if (i*2 +1 +step<n){
                                if (a[i +step] > a[i*2 +1 +step]){
                                        sort(&a[i +step], &a[i*2 +1 +step]);
                                        b=1;
                                }
                        }
                }
                if (!b) step++;
                if (step+2==n) break;
        }
        for (int i=0;i<n;++i) printf("%d ",a[i]);
        printf ("\n");
        return 0;
}
