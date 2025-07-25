#include <stdio.h>
int main()
{
	int n,i,s,s1,s2;
	printf("What is the value of N ?\n");
	printf("N=");
	scanf("%d",&n);
	i=0;
	s=0;
	s1=0;
	s2=1;
		if(n%2==0){
			for(i=0;i<(n+1)/2;i++){
				s1=s1+2;
				//printf("%d",s1);
				s=s-s1;
			}
			for(i=1;i<n/2;i++){
				s2=s2+2;
				//printf("%d+",s2);
				s=s+1+s2;
			}
			//s=1+s2-s1;
			printf("S=%d\n",s);
		}
		//else{
			//s=s+i;

		//}
	        
		//i++;
		
		//printf("S=%d \n",s);


	
}	
