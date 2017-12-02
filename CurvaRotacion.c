#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int leeDatos(void);
double likelihood(double*V,double*V2);
void Caminata(double *V, double *V2, double*R);
void velocidad(double *R,double*Mb,double *Md, double*M);

int main(void){

	leeDatos();
	likelihood(double*V,double*V2);
	velocidad(double *R,double*Mb,double *Md, double*M);
	Caminata(double *V, double *V2, double*R);
	return 0;
}

float b_b=0.2497;
float b_d=5.16;
float a_d=0.3105;
float a_h=64.3;
float M=2.325E7;
int G=1;
int nx=300;

int leeDatos(void){

double*x=malloc(nx*sizeof(double));
double*y=malloc(nx*sizeof(double));

FILE*datos=fopen("RadialVelocities.dat", "r");
int i;


char greeting1[60];
char greeting2[60];
fscanf(datos,"%s %s \n", &greeting1,&greeting2);
for (i=0;i<nx-1;i++){
	fscanf(datos,"%lf %lf\n", &R[i],&V[i]);
	printf("%lf \n",R[i]);
}
fclose(datos);

}

double likelihood(double*V,double*V2)
	{
		
		double j;
		double promedio=0;
		for(i=0;i<nx;i++)
		{
			chi_cuadrado=0.5*pow(sum(V[i]-V2[i]),2);
			j=j+chi_cuadrado;
			promedio=promedio+1;
		}
			chi=exp(-j/promedio);
			return chi;
	}

void Caminata(double *V, double *V2, double*R)
{
	double*Mb=malloc(nx*sizeof(double));
	double*Md=malloc(nx*sizeof(double));
	double*M=malloc(nx*sizeof(double));
	double*L=malloc(nx*sizeof(double));

	Mb[0]=1E14*drand48()-1E7;
	Md[0]=1E14*drand48()-1E7;
	M[0]=1E14*drand48()-1E7;

	V2_inicial=velocidad(R[0]);
	L[0]=likelihood(V2_inicial,chi);
	
	for(i=0;i<nx;i++)
	{

	Mb_prime=1E14*drand48()-1E7;
	Md_prime=1E14*drand48()-1E7;
	M_prime=1E14*drand48()-1E7;
	
	V2_inicial=velocidad(R[i],Mb[i],Md[i],M[i]);
	V_prime=velocidad(R[i],Mb_prime,Md_prime,M_prime);
	
	L_prime=likelihood(V[i],V_prime[i]);
	L_inicial=likelihood(V[i],V2_inicial[i]);

	double alpha;
	alpha=L_prime/L_inicial;
	if(alpha >=1.0)
        {
            Mb[i+1] = Mb_prime[i];
            Md[i+1] = Md_prime[i];
            M[i+1] = M_prime[i];
	    L[i+1] = L_prime[i];
        }
        else
        {

	double beta;
	if (beta<=alpha)
	{
            Mb[i+1] = Mb_prime[i];
            Md[i+1] = Md_prime[i];
            M[i+1] = M_prime[i];
	    L[i+1] = L_prime[i];

	}
	else
	{
            Mb[i+1] = Mb[i];
            Md[i+1] = Md[i];
            M[i+1] = M[i];
	    L[i+1] = [i];
	}
}

}}

double Mb=1E14*drand48()-1E7;
double Md=1E14*drand48()-1E7;
double M=1E14*drand48()-1E7;

void velocidad(double *R,double*Mb,double *Md, double*M)
	{
	double*V2=malloc(nx*sizeof(double));
		
	for (i=0;i<nx;i++){
	V2[i]=(((sqrt(M_b))*R[i])/pow(pow(R[i],2) + pow(b_b,2)),3/4) + (((sqrt(M_d))*R[i])/pow(pow(R[i],2) + pow(b_d + a_d,2)),3/4) + ((sqrt(M_h))/pow(pow(R[i],2) + pow(a_h,2)),1/4);}
		return V2;
	}

























