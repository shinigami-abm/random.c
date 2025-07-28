#include<stdio.h>
int main(){
	float n;
	printf("What is hte price of the prudct\n");
	scanf("%f",&n);
	if(n<=300){
		printf("Thank you for your purshes you have to pay %fDA \n",n);
	}
	else{
		n=n-(0.2)*n;
			 printf("Congrats you have a discount of 20 \n");
		if(n>300){
			 n=n-(0.3)*n;
			 printf("congrats you have a scond discount of 30 \n");
	         }	 
			 printf("Thank you for your purshes you have to pay %fDA \n",n);

		 


	}




































}
