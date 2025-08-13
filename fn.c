#include<stdio.h>
int main ()
{
            int s=0, n, i, j, e, s1=0;

	printf("Give a value for n\n");
	scanf("%d",&n);

	for(i=0;i<n+1;i++){
		s=0;
		for(j=1;j<i+1;j++){
		     
			if(i%j==0){
			     s=s+i;
		        }
		}
		
		    if(s<n+1){
			 s1=0;
			    for(e=1;e<s+1;e++){
				 
				     if(s%e==0){
                                        s1=s1+e;
				     }
		            }
		        if(s!=i && s1==i){
			    printf("%d and %d are freand numbers\n",i,s);
		        }
		     }
		     

	}

  


}	
