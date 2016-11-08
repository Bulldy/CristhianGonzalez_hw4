#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define rho 10
#define L 100
#define T 40
#define tmax 200

double ut0(double x);
int main(){
  double *x,*u0,*u1,*u2;
  int i,j,Nx,Nt;
  double dx,dt;
  dx=2.0;
  dt=0.2;
  double c=sqrt(T/rho);
  double r=c*dt/dx;
  Nx=L/dx;
  Nt=tmax/dt;
  
  x=malloc(Nx*sizeof(double));
  u0=malloc(Nx*sizeof(double));
  u1=malloc(Nx*sizeof(double));
  u2=malloc(Nx*sizeof(double));
  
  for(i=0;i<=Nx;i++){
    x[i]=i*dx;
    u0[i]=ut0(x[i]);
    printf("%f ",x[i]);
  }
  printf("\n");
  
  u0[0]=0;
  printf("%f ",u0[0]);
  for(i=1;i<=Nx-1;i++){
    u1[i]=u0[i]+(r*r/2)*(u0[i+1]-2*u0[i]+u0[i-1]);
    printf("%f ",u0[i]);
  }
  u0[Nx]=0;
  printf("%f \n",u0[Nx]);
  

  for(j=2;j<=Nt;j++){
    u1[0]=0;
    u1[Nx]=0;
    printf("%f ",u1[0]);
    u2[0]=0;
    u2[Nx]=0;
    for(i=1;i<=Nx-1;i++){
      u2[i]=2*(1-(r*r))*u1[i]-u0[i]+(r*r)*(u1[i+1]+u1[i-1]);
      printf("%f ",u1[i]);
    }
    printf("%f \n",u1[Nx]);
    for(i=0;i<=Nx;i++){
      u0[i]=u1[i];
      u1[i]=u2[i];
    }
  }

  return 0;
}

double ut0(double x){
  double a;
  if(x<=0.8*L){
    a=1.25*x/L;
  }
  else{
    a=5-(5*x/L);
  }
  return a;
}

