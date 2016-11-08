#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define L 5
#define l 2
#define d 1
#define h 0.02
#define V0 100

int main(){
  double **u1,**u2;
  double ex,ey;
  int M,i,k,j,N,j1,j2,iu,id;
  M=L/h;
  N=2*M*M;
  j1=(0.5*(L-l))/h;
  j2=((0.5*(L-l))+l)/h;
  iu=(0.5*(L-d))/h;
  id=((0.5*(L-d))+d)/h;

  u1=(double **)malloc(M*sizeof(double *));
  u2=(double **)malloc(M*sizeof(double *));
  for(i=0;i<M;i++){
    u1[i]=(double *)malloc(M*sizeof(double));
    u2[i]=(double *)malloc(M*sizeof(double));
  } 
  
  for(i=0;i<M;i++){
    for(j=0;j<M;j++){
      u2[i][j]=0;
      if(i==iu && j>=j1 && j<=j2){
	u1[i][j]=-1*V0/2;
      }
      else if(i==id && j>=j1 && j<=j2){
	u1[i][j]=V0/2;
      }
      else{
	u1[i][j]=0;
      }
    }
  }
  
  for(k=0;k<N;k++){
    for(i=1;i<M-1;i++){
      for(j=1;j<M-1;j++){
	if(i==iu && j>=j1 && j<=j2){
	  u2[i][j]=-1*V0/2;
	} 
	else if(i==id && j>=j1 && j<=j2){
	  u2[i][j]=V0/2;
	}
	else{
	  u2[i][j]=0.25*(u1[i+1][j]+u2[i-1][j]+u1[i][j+1]+u2[i][j-1]);
	}
      }
    }
    
    for(i=0;i<M;i++){
      for(j=0;j<M;j++){
	u1[i][j]=u2[i][j];
      }
    }
  }

  FILE *fp1,*fp2,*fp3;
  fp1=fopen("v.txt","w");
  fp2=fopen("ex.txt","w");
  fp3=fopen("ey.txt","w");
  for(i=0;i<M;i++){
    for(j=0;j<M;j++){
      fprintf(fp1,"%f ",u1[i][j]);
    }
    fprintf(fp1,"\n");
  }
  fclose(fp1);
  
  for(i=1;i<M-1;i++){
    for(j=1;j<M-1;j++){
      ex=(-1/(2*h))*(u1[i+1][j]-u1[i-1][j]);
      ey=(-1/(2*h))*(u1[i][j+1]-u1[i][j-1]);
      fprintf(fp2,"%f ",ex);
      fprintf(fp3,"%f ",ey);
    }
    fprintf(fp2,"\n");
    fprintf(fp3,"\n");
  }
  fclose(fp2);
  fclose(fp3);
  return 0;
}
