#include<stdio.h>

  typedef struct{

    int id;
    char name[100];
    char class[4];
    float salary;
  } employee;

int main()
{

	employee e[100];
	int n,s;

	printf("How many employees you have\n");
        scanf("%d",&n);

      for(int i=1;i<n+1;i++){
	      
	      printf("Give me your id for the employee number %d\n",i);
	      scanf("%d",&e[i].id);

              printf("Give me your name\n");
	      scanf("%s",&e[i].name);

	      printf("Give me your class\n");
	      fgets("%s",&e[i].class);

	      printf("Give me your salary\n");
	      scanf("%f",&e[i].salary);

      }  

      printf("who you are looking for\n");
      scanf("%d",&s);

      for(int j=1;j<n+1;j++){
	      if(s==e[j].id){
		      printf("you are %s,your id is %d,and the class %s,and the salary %f",e[j].name,e[j].id,e[j].class,e[j].salary);
	      }

      }






return 0;
}
