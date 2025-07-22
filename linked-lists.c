#include<stdio.h>
#include<stdlib.h>


typedef struct node{
        
	float data2;
	char data1;
	int data0;
        struct node *next;
        struct node *prv;

} node;

typedef struct{

      int d0;
      float d2;
      char d1;

} data;

   void export(node head, node tail){
           struct node *this;
	   this=head.next;

	   while(this!=NULL && this!=&tail){

     printf("%f",this->data2);
     printf("%d",this->data0);
     printf("%c,",this->data1);
	   }
         printf("\n");
   }





   void erase (node head, node tail, int nd){
            
            struct node *this;
	    struct node *last;
	    struct node *enext;
	    this=&head;

	   for(int j=1; j<nd+1; j++){

            this=this->next;

	   }
	   last=this->prv;
	   enext=this->next;

	   last->next=enext;
	   enext->prv=last;

	   this->prv=NULL;
	   this->next=NULL;

	   free(this);
   }





    int count(node head, node tail){
              int c=0;
          struct node *this;
	  this= &head;

      while(this->next != NULL){
	      this=this->next;
	      c++;
      }
return c;
    }


    void ADD( node tail, node head, int b,  data input, int p){
              struct node *linka;
              struct node *this1;
	      struct node *this0;


            this0= &head;
	    this1=this0->next;
            linka= (node *)malloc(sizeof(node));

	    if(b==0){

                    linka->data0= input.d0;

		      for(int i=1; i<p; i++ ){

			      this0= this0->next;
			      this1=this0->next;
		      }
		      
		      linka->prv= this0;
		      linka->next= this1;

		      this0->next= linka;
		      this1->prv= linka;
	    }
	    else if(b==1){
                    
		    linka->data1= input.d1;
 
                      for(int i=1; i<p; i++){
			      
			      this0= this0->next;
                              this1=this0->next;
		      }

		      linka->prv= this0;
		      linka->next= this1;

		      this0->next= linka;
		      this1->prv= linka;

	    }   
	    else{

		    linka->data2= input.d2;

		     for(int i=1; i<p; i++){

			     this0= this0->next;
			     this1= this0->next;
		     }



		     linka->prv= this0;
		     linka->next= this1;

		     this0->next= linka;
		     this1->prv= linka;
	    }
   }  

int main(){
	int p,a,b,a0,a1,a2,a3,p1,a4,nd,a5;
   node head,tail;
     
     head.prv= NULL;
     head.next= &tail;
     tail.prv= &head;
     tail.next= NULL;


     struct node *link;
     data input;

     printf("Do you whant to add or erase a node\n");
     printf("erase=e , add=d:\n");
           char f,f0,s,r;    
           while(a!=1){

               scanf("%s",&f);
                 
     
                    if(f=='e'){ 
			    a=1;
                      p1=count(head, tail);
		       
		         printf("Wich node you whant to erase\n");

			 while(a4!=1){
                              scanf("%d",&nd);
                                  if(nd<p1-1 && nd>0){
					  erase(head, tail, nd);
					  a4=1;
				  }
				  else{a4=0;
                                        printf("wrong input try again\n");
				  }
			 }
		    }
		    else if(f=='d'){ 
			   a=1;
while(a2!=1){
 			   printf("What is the type you whant to add\n ");
			   printf("float=f, int=i, char=c:\n");

                            while(a0!=1){
                                  scanf("%s",&f0);
				    if(f0=='f'){ a0=1;
                                            b=2;
					    printf("Give me your float\n");
					    scanf("%f",&input.d2);
				    }
				    else if (f0=='i'){ a0=1;
					    b=0;
					    printf("Give me your integer\n");
					    scanf("%d",&input.d0);
				    }
				    else if (f0=='c'){ a0=1;
					    b=1;
					    printf("Give me you caracter\n");
					    scanf("%c",&input.d1);
				    }
				    else{ a0=0;
					    printf("Wrong input, try again\n");
				    }
			    }
			     p1=count(head, tail);
			    printf("In wich position in the list\n");

			    while(a1!=1){
				    scanf("%d",&p);

                                  if(p<p1+1 && p>0){
					  a1=1;
				  }
				  else{
                                            printf("wrong input try again\n");
					    a1=0;
				  }
			    } 

 //                    printf("Do you whant to see your list\n");
//		     printf("yes=y, no=n\n");
//
//		     while(a5!=1){
//
//                       scanf("%c",&r);
//			     if(r=='y'){ a5=1;
//				     export(head, tail);
//			     }
//			     else if(r=='n'){ a5=1;}
  //                           else{
    //                             printf("Wrong input try again\n");
//				 a5=0;
//			     }
//		     }
                         
                       ADD(tail, head, b, input, p);
               printf("do you whant to add or erase anouther node\n");
	       printf("yes=y, no=n\n");
	        while(a3!=1){

                    scanf("%c",&s);

		        if(s=='n'){a3=1;
				a2=1;
			}
			else if(s=='y'){
				a3=1;
				a2=0;
			}
			else{
                             printf("Wrong input try again\n");
			     a3=0;
			}
		}
}

		    }

		    else {
                                printf("404, wrong input\n");
		                printf("try again\n");
				a=0;
		    }
          }
return 0;
}
