#include <stdio.h>
#include <math.h>
#define _USE_MATH_DEFINES

typedef struct coplex_number{
 double real,imaginary,module,argument, power,radical;
 }cplx;
 
double trg(cplx z){
 if(z.module==0){
 printf("trigonometric form: NaN\n");
 return 0; 
 } 
 
 z.argument=acos(z.real/z.module);
 
 if(z.imaginary<0){
 z.argument*=-1;
 }
 printf("trigonometric form: %lf * (cos(%lf)+i*sin(%lf))\n",z.module,z.argument,z.argument);
 return z.argument;
}
int rvrs(cplx z){
 if (z.real==0){
 if(z.imaginary>0){
 printf("reverse: %lf*i\n",-z.imaginary);
 }
 else if(z.imaginary<0){
 printf("reverse: %lf*i\n",-z.imaginary);
 }
 else printf("reverse: %d*i\n",0) ; 
 }
 if(z.imaginary>0){
 printf("reverse: %lf%lf*i\n",z.real,-z.imaginary);
 }
 else if(z.imaginary<0){
 printf("reverse: %lf+%lf*i\n",z.real,-z.imaginary);
 }
 else printf("reverse: %lf\n",z.real);

 }
int dgr(cplx z){
 if(z.module==0){
 printf("degree: %d\n",0);
 return 0;
 }
 
 z.argument=z.power*z.argument;
 while(z.argument>M_PI){
 z.argument-=M_PI;
 }
 printf("degree: %lf * (cos(%lf)+i*sin(%lf))\n", pow(z.module,z.power),z.argument,z.argument);
 
}
int rdcl(cplx z){
 
 z.argument=z.argument/z.radical;
 
 while(z.argument<2*M_PI){
 printf("radical: %lf * (cos(%lf)+i*sin(%lf))\n",pow(z.module,1/z.radical),z.argument,z.argument);
 z.argument+=2*M_PI/z.radical;
 }
}

int main() {

 cplx z;

scanf("%lf%lf%lf%lf",&z.real,&z.imaginary,&z.power,&z.radical);
z.module = sqrt (pow(z.real,2.0)+pow(z.imaginary,2.0));

z.argument = trg(z);
rvrs(z);
dgr(z);
rdcl(z);

 
 return 0;
}
