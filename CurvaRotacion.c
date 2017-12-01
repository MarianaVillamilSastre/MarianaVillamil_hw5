#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int leeDatos(void);




int main(void){

	leeDatos();
	return 0;
}



int leeDatos(void){
float b=0.2497;
float d=5.16;
float a=0.3105;
float h=64.3;
float M=2.325E7;
int G=1;
int nx=300;
double*x=malloc(nx*sizeof(double));
double*y=malloc(nx*sizeof(double));

FILE*datos=fopen("RadialVelocities.dat", "r");
int i;


char greeting1[60];
char greeting2[60];
fscanf(datos,"%s %s \n", &greeting1,&greeting2);
for (i=0;i<nx-1;i++){
	fscanf(datos,"%lf %lf\n", &x[i],&y[i]);
	printf("%lf \n",x[i]);
}
fclose(datos);

}

int sum();
int likelihood(y1,y2){
	chi_cuadrado=(1.0/2.0)*



}






















