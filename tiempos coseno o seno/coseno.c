
//gcc powFuncASM factFuncASM coseno.c -lm -o coseno
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double factFuncC(int n);
double powFuncC(int n,double x);
extern double factFuncASM(int n);
extern double powFuncASM(int n,double x);

int main(){
    int n=50;
    double x=3.0,sum1=0.0,sum2=0.0;
    double factC,factASM,powC,powASM,elapsed1,elapsed2,error1,error2;
    struct timespec ti,tf;

    printf("El fact=%.2lf es %lf\n",factFuncC(0),powFuncC(4,3));
    printf("El fact=%.2lf es %lf\n",factFuncASM(0),powFuncASM(4,3));
    clock_gettime(CLOCK_REALTIME,&ti);
    for (int i = 0; i < n; i++){
        factC=factFuncC(i);
        powC=powFuncC(i,x);
        sum1+=(powC/factC);
    }
    clock_gettime(CLOCK_REALTIME,&tf);
    elapsed1=(tf.tv_nsec-ti.tv_nsec)+(tf.tv_sec*10e9-ti.tv_sec*10e9);
    clock_gettime(CLOCK_REALTIME,&ti);
    for (int i = 0; i < n; i++){
        factASM=factFuncASM(i);
        powASM=powFuncASM(i,x);
        sum2+=(powASM/factASM);
    }
    clock_gettime(CLOCK_REALTIME,&tf);
    elapsed2=(tf.tv_nsec-ti.tv_nsec)-(tf.tv_sec*10e9-ti.tv_sec*10e9);
    double coseno=cos(x);
    error1=(fabs(coseno-sum1)/coseno);
    error2=(fabs(coseno-sum2)/coseno);
    printf("El coseno de x=%.2lf es %lf\n",x,coseno);
    printf("(EN C)El coseno de x=%.2lf es %lf y demora: %lf\n",x,sum1,elapsed1);
    printf("ERROR RELATIVO: %lf\n",error1);
    printf("(EN ASM)El coseno de x=%.2lf es %lf y dedmora: %lf\n",x,sum2,elapsed2);
    printf("ERROR RELATIVO: %lf\n",error2);
    return 0;
}
double factFuncC(int n){
    double resp=1;
    for(int i=1;i<=2*n;i++){
        resp*=i;
    }
    return resp;
}
double powFuncC(int n,double x){
    double resp=1;
    for(int i=0;i<2*n;i++){
        resp*=x;
    }
    if(n%2!=0){
        resp*=-1;
    }
    return resp;
}