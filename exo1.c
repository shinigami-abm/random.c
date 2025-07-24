 #include<stdio.h>

#define max_c 50
#define max_l 50
void p1 (int n,int m,float mrx[max_l][max_c]){

 float t[n];
 float a=0;
 int b=0;





     for(int i=1;i<n+1;i++){
	     for(int j=1;j<m+1;j++){

		     a=a+ mrx[i][j];

	     }

	     t[i]=a/m;
	     printf("%f in the posetion %d in t[n]\n",t[i],i);
     }
}


void p2 (int n,int m, float mrx[max_l][max_c]){



	float c[m],k=mrx[1][1];

    for(int i=1;i<m+1;i++){
	    for(int j=1;j<n+1;j++){
		    if(mrx[i][j]<k){
			    k= mrx[i][j];
		    }
	    }
         c[i]=k;
	 printf("the minimal value in the colonne %d is %f\n",i,c[i]);
    }

}





int main (){

   int n,m;
   float mrx[n][m];
   char x,y,z;

     for(int i=1;i<n+1;i++){
	     printf("we are going to fill the ligne %d\n",i);
	     for(int j=1;j<m+1;j++){
		     printf("Give me a random value\n");
		     scanf("%f",&mrx[i][j]);
	     }
     }
  

     printf("if you want to use p1 print x\n");
     printf("is you want to use p2 print y\n");
     scanf("%c",&z);

     if(z==x){
        p1(n, m, mrx);
     }
     else if (z==y){
	     p2(n, m, mrx);
     }
     else{printf("404\n");}



return 0;
}














