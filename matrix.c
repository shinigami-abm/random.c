#include<stdio.h>
#include<stdbool.h>
void fill(int T[3][3]){

	for(int i=0; i<3; i++){
		printf("filling the %d column \n",i+1);
		for(int j=0; j<3; j++){
			scanf("%d",&T[i][j]);
		}
	}	
}
float cofactor(int T[3][3], float C[3][3]){
 
	int s[4],n=0,det=0,ss=0;
	bool c;
 
 for(int k=0; k<3; k++){
     for(int m=0; m<3; m++){	 
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(i != k || j != m){
				s[n]=T[i][j];
				n++;
			}

		}

	}	
	 C[k][m]=s[0]*s[3]-s[1]*s[2];
	 //det=det+T[k][m]*C[k][m];
     }
 }
   for(int i=0; i<3; i++){
      for(int j=0; j<3; j++){
	      if((i+j)%2==0){
		      c = true;
	      }
	      else{c=false;}
	      if(c != true){
		      C[i][j]=0-C[i][j];
	      }
      	      if(ss!=3){
	      det=det+T[i][j]*C[i][j];
	      ss++;
	      }
      }	       
   }
   return det;
}

int main(){
 int T[3][3];
 float C[3][3];

  fill( T );
  //cofactor ( T, C );
  printf("%f\n",cofactor(T, C));


}
