#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factimpC(int n);
extern int factimpASM(int n);
double powerimpC(double x, int n);
extern double powerimpASM(double x, int n);
double calculaSenC(double x, int n);
double calculaSenASM(double x, int n);
int main(){
	int N, n=5;
	double N2,x=4;
	//N = factimpC(n);
	//printf("%d\n",N);

	//N = factimpASM(n);
	//printf("%d\n",N);

	//N2 = powerimpC(x,n);
	//printf("%.2lf\n",N2);

	//N2 = powerimpASM(x,n);
	//printf("%.2lf\n",N2);

	N2 = calculaSenC(5,1);
	printf("%lf\n",N2);
	N2 = calculaSenC(5,2);
	printf("%lf\n",N2);
	N2 = calculaSenC(5,4);
	printf("%lf\n",N2);
	N2 = calculaSenC(5,8);
	printf("%lf\n",N2);
	N2 = calculaSenC(5,16);
	printf("%lf\n",N2);

	printf("\n");

	N2 = calculaSenASM(5,1);
	printf("%lf\n",N2);
	N2 = calculaSenASM(5,2);
	printf("%lf\n",N2);
	N2 = calculaSenASM(5,4);
	printf("%lf\n",N2);
	N2 = calculaSenASM(5,8);
	printf("%lf\n",N2);
	N2 = calculaSenASM(5,16);
	printf("%lf\n",N2);
}

int factimpC(int n){
	
	int aux=1,aux2=(2*n)+1;
	for(int i=1;i<=aux2;i++){
		aux=aux*i;
	}
	return aux;
}
double powerimpC(double x, int n){
	double resul=1,potencia = (2*n)+1;
	for(int i=0;i<potencia;i++){
		resul=resul*x;
	}
	if(n%2==1){
		resul=resul*(-1);
	}
	return resul;
}
double calculaSenC(double x, int n){
	double respuesta=0;
	for(int i=0;i<=n;i++){
		respuesta=respuesta+(powerimpC(x,i)/factimpC(i));
	}
	return respuesta;
}
double calculaSenASM(double x, int n){
	double respuesta=0;
	for(int i=0;i<=n;i++){
		respuesta=respuesta+(powerimpASM(x,i)/factimpASM(i));
	}
	return respuesta;
}