#include<stdio.h>
#include<math.h>


typedef struct {

   float a,b;

}  copx ;


float module (copx z){

 float s;
 s=z.a*z.a+z.b*z.b;
 s=pow(s,1/2);
 

 return s;
}


copx sum (copx z1,z2){
  copx z3;

  z3.a=z1.a+z2.a;
  z3.b=z1.b+z2.b;


  printf("z3= %f + i%f\n"z3.a,z3.b);


return z3;
}


copx produit (copx z1,z2){
   copx p;


   p.a=z1.a*z2.a-z1.b*z2.b;
   p.b=z1.a*z2.b+z1.b*z2.a;


   printf("z3=%f + i%f",p.a,p.b);

return p;   
}

void compair (copx z1,z2){
    float x,y;
   x=module(z1);
   y=module(z2);

   if(x<y){ printf("z1<z2\n");}
   else if(y<x){printf("z2<z1\n");}
   else{printf("z1=z2\n");}
   
}



int main (){
copx z1,z2;

 scanf("%f,%f"&z1.a,&z1.b);
 scanf








}
















