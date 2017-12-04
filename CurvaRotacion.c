#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define nx 300

double likelihood(double expe[nx], double mymodel[nx])
{
	int i;
	double chi=0;
	double chi_cuadrado;
	double promedio=100;
	for (i=0;i<nx;i++)
	{
		chi = chi+ pow((expe[i]-mymodel[i]) / promedio,2);
		chi_cuadrado=exp(-(0.5)*chi);
	}
	return chi_cuadrado;

}

double distribucion(double x, double y)
{
  double m = drand48();
  double p = drand48();
  return ((sqrt(-2.0*log(m))*cos(2*3.131415*p))*y +x);

}


double*velocidad(double R[nx],double Mb,double Md, double M)
	{
	float b_b=0.2497;
	float b_d=5.16;
	float a_d=0.3105;
	float a_h=64.3;	
	double*V2=malloc(nx*sizeof(double));
	int i;
	for (i=0;i<nx;i++){
	V2[i]=(sqrt(Mb) * R[i] / pow((pow(R[i],2.0)+pow(b_b,2.0)), 0.75)) + (sqrt(Md) * R[i] / pow((pow(R[i],2.0)+pow(b_d+a_d,2.0)), 0.75)) + (sqrt(M) / pow((pow(R[i],2.0)+pow(a_h,2.0)), 0.25));}
		return V2;
	}




int main(void){

double*r_expe=malloc(nx*sizeof(double));
double*v_expe=malloc(nx*sizeof(double));

FILE*datos=fopen("RadialVelocities.dat", "r");
int i;
char greeting1[60];
char greeting2[60];
fscanf(datos,"%s %s \n", &greeting1,&greeting2);
for (i=0;i<nx-1;i++){
	fscanf(datos,"%lf %lf\n", &r_expe[i],&v_expe[i]);
	
}
fclose(datos);

double pasos=20000;

	double*Mb=malloc(pasos*sizeof(double));
	double*Md=malloc(pasos*sizeof(double));
	double*M=malloc(pasos*sizeof(double));
	double*L=malloc(pasos*sizeof(double));
	double*V2_inicial=malloc(nx*sizeof(double));
	double*v_prueba=malloc(nx*sizeof(double));

	Mb[0]=drand48();
	Md[0]=drand48();
	M[0]=drand48();

	V2_inicial=velocidad(r_expe,Mb[0],Md[0],M[0]);
	L[0]=likelihood(v_expe,V2_inicial);
	
	for(i=0;i<nx;i++)
	{

	double Mb_prueba=distribucion(Mb[i],4);
	double Md_prueba=distribucion(Md[i],400);
	double M_prueba=distribucion(M[i],400);
	
	V2_inicial=velocidad(r_expe,Mb[i],Md[i],M[i]);
	v_prueba=velocidad(r_expe,Mb_prueba,Md_prueba,M_prueba);
	
	double L_prueba=likelihood(v_expe,v_prueba);
	double L_inicial=likelihood(v_expe,V2_inicial);

	double alpha;
	alpha=L_prueba/L_inicial;
	if(alpha >=1.0)
        {
            Mb[i+1] = Mb_prueba;
            Md[i+1] = Md_prueba;
            M[i+1] = M_prueba;
	    L[i+1] = L_prueba;
        }
        else
        {

	double beta;
	beta=drand48();
	if (beta<=alpha)
	{
            Mb[i+1] = Mb_prueba;
            Md[i+1] = Md_prueba;
            M[i+1] = M_prueba;
	    L[i+1] = L_prueba;

	}
	else
	{
            Mb[i+1] = Mb[i];
            Md[i+1] = Md[i];
            M[i+1] = M[i];
	    L[i+1] = L[i];
	}
}

}


  double chi_max =L[0];
  int h = 0;
  for(i=1; i<pasos; i++){
    if(L[i] >= chi_max){
      chi_max = L[i];
      h = i;
    }
  }

 FILE *myfile= fopen("Datos.dat","w");
fprintf(myfile, "%f %f %f", Mb[h], Md[h], M[h]);
  printf("El valor de Mb es: %lf\n", Mb[h]);
  printf("El valor de Md es: %lf\n", Md[h]);
  printf("El valor de Mh es: %lf\n", M[h]);
   
  return 0;
}






















