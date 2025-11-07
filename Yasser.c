#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct gard{

	char name[10];
	int id;
	struct gard *next;
} gard;
typedef struct interns{

    char name[10];
    int id;
    struct interns *next;
} interns;
typedef struct time{

  int T;
  struct gard *startg;
  struct interns *starti;

  struct gard *endg;
  struct interns *endi;
} time;
  struct gard *make_gard(char n[], int id){
	  int c;
	  struct gard *g;
	  g = (gard *)malloc(sizeof(gard));
          c = strlen(n);

	  for(int i=0; i<c; i++){
		  g->name[i]= n[i];
	  }
	  g->id=id;
	  return g;
  }
  struct interns *make_intr(char n[], int id){
       int c;
       struct interns *it;
       it = (interns *)malloc(sizeof(interns));
       c = strlen(n);

       for(int i=0; i<c; i++){
	       it->name[i]=n[i];
       }
       it->id=id;
   return it;
  }

  void add(time callander[], char n[], int id, int c, int t, int e){
	  if( c == 0){ // add intern
		  struct interns *this;
		  this= make_intr(n, id);
	      int i=0;
	      while( callander[i].T != t){ i++;}
	      if(callander[i].starti == NULL){
	       callander[i].starti= this;
	      }
	      else{
		      struct interns *this2;
		      this2= callander[i].starti;
		      while(this2->next != NULL){this2= this2->next;}
		      this2->next= this;
	      }
	       i=0;
	      while(callander[i].T != e){i++;}
	      if(callander[i].endi == NULL){
		      callander[i].endi= this;
	      }
	      else{
                struct interns *this1;
		this1= callander[i].endi;
		while(this1->next != NULL){this1= this1->next;}
		this1->next= this;
	      }
	  }
	  else if(c == 1){  // add gard
		  struct gard *this;
		  this= make_gard(n ,id);
		  int i=0;
		  while(callander[i].T != t){i++;}
                  if(callander[i].startg == NULL){
		   callander[i].startg= this;
		  }
		  else{
			  struct gard *this1;
			  this1= callander[i].startg;
			  while(this1->next != NULL){this1= this1->next;}
			  this1->next= this;
		  }
		  i=0; 
		  while(callander[i].T != e){i++;}
		  if(callander[i].endg == NULL){
		   callander[i].endg= this;
		  }
		  else{
                        struct gard *this2;
			this2= callander[i].endg;
			while(this2->next != NULL){this2= this2->next;}
			this2->next = this;
		  }
	       }
  }
  void erase(time callander[], int id, int c){
	  if(c == 0){  // erase intern
		  struct interns *this;
		  struct interns *last;
		  int i=0;
		  bool out= true;
                 while(i<24 && out != false){
		     this= callander[i].starti;	 
		     while(this->id != id && this->next != NULL){
			     last= this;
			     this= this->next;
		     } 
		     if(this->id == id){
			     out= false;
			     printf("the intern %s with the id of %d has been erased\n",this->name,this->id);
			     last->next= this->next;
			     free(this);
		     }
	         }
	  }
	  else if(c == 1){ // erase gard
			   struct gard *this;
			   struct gard *last;
			   int i=0;
			   bool out= true;
			 while(i<24 && out != false){
				 this= callander[i].startg;
				   while(this->id != id && this->next != NULL){
					   last= this;
					   this= this->next;
				   }
			      if(this->id == id){
				      out= false;
				      printf("the gard %s with the id of %d has been erased\n",this->name,this->id);
				      last->next= this->next;
				      free(this);
			      }
			 }  
	       }
  }
          void print_hour(time callander[], int t){		     
	       for(int i=0; i<24; i++){
                if(callander[i].T == t){
			printf("---All of this gards start there chifts at %d today:\n",i);
			struct gard *this1;
			this1= callander[i].startg;
			int j=1;
			  while(this1 != NULL){
				  printf("%d-This gard name is %s, his id %d.\n",j,this1->name,this1->id);
				  this1= this1->next;
				  j++;
			  }
		           printf("\n---All of this gards end there chifts at %d today:\n",i);
			    this1= callander[i].endg;
			    j=1;
			    while(this1 != NULL){
				    printf("%d-This gard name id %s, his id is %d.\n",j,this1->name,this1->id);
				    this1= this1->next;
				    j++;
			    }
			    printf("\n---All of this interns start there stage at %d today:\n",i);
			    struct interns *this2;
			    this2= callander[i].starti;
			    j=1;
			    while(this2 != NULL){
				    printf("%d-this intern name is %s, his id is %d.\n",j,this2->name,this2->id);
				    this2= this2->next;
				    j++;
			    }
			     printf("\n---All of this interns end there stage at %d today:\n",i);
			     this2= callander[i].endi;
			     j=1;
			     while(this2 != NULL){
				     printf("%d-this intern name is %s, his id is %d.\n",j,this2->name,this2->id);
				     this2= this2->next;
				     j++;
			     }
	      }
	       }	
	}

  void print(time callander[], int id, int t){
	if(t == 999){
		for(int j=0; j<24; j++){
			print_hour(callander, j);
		}
	}
	else if(t == 69){
		for(int i=0; i<24; i++){
			struct gard *this1;
			this1= callander[i].startg;
			while(this1 != NULL && this1->id != id){
				this1= this1->next;
			}
			if(this1->id == id){
				printf("-this gard start his chift at %d, his name is %s.\n",i,this1->name);
			}
		}
		for(int i=0; i<24; i++){
			struct gard *this2;
			this2= callander[i].endg;
			while(this2 != NULL && this2->id != id){
				this2= this2->next;
			}
			if(this2->id == id){
				printf("And he end it at %d.\n",i);
			}
		}
		 for(int i=0; i<24; i++){
			 struct interns *this1;
			 this1= callander[i].starti;
			 while(this1 != NULL && this1->id != id){
				 this1= this1->next;
			 }
			 if(this1->id == id){
				 printf("-this intern start his session at %d, his name is %s.\n",i,this1->name);
			 }
		 }
		 for(int i=0; i<24; i++){
			 struct interns *this2;
			 this2= callander[i].endi;
			 while(this2 != NULL && this2->id != id){
				 this2= this2->next;
			 }
			 if(this2->id == id){
				 printf("And he end it at %d.\n",i);

			 }

		 }

		
	     }
	     else{
			     print_hour(callander, t);
	     }
  }
int main(){
 
   time callander[24];
   int in,id,t,e;
   char n[10];
   for(int i=0; i<24; i++){
	   callander[i].T= i;
   }
   bool test= true;
   while( test != false){
   printf("-Do you want to search for gard/intern or add or erase one?\n");
   printf("-search= 0;\n-add= 1;\n-erase= 2;\n");
   printf("-to exit do 99\n");
   printf("/-");
   scanf("%d",&in);
   if(in == 99){return 0;}
   if(in == 1){
	   printf("-Do you want to add gard or an intern?\n-intern= 1;\n-gard= 2;\n");
	   scanf("%d",&in);
	   if(in == 1 || in == 2){
		   printf("Give me his name\n/-");
		   scanf("%s",n);
		   printf("Give me his id\n/-");
		   scanf("%d",&id);
		   printf("Give me the time he starts\n/-");
		   scanf("%d",&t);
		   printf("Give me the time he exit\n/-");
		   scanf("%d",&e);
		   add(callander, n, id, in-1, t, e);
	   }
	        else{printf("wrong input\n");}
   }
   else if( in == 2){
	printf("-Do you want to erase gard or intern?\n-intern= 1;\n-gard= 2;\n");
	scanf("%d",&in);
	 if(in == 1 || in == 2){
		 printf("Give me his id\n");
		 scanf("%d",&id);
	   erase(callander, id, in-1);
	 }
	 else{printf("wrong input");}
        }
        else if(in == 0){
		printf("-Do you want to search for person or print the fool hour or all the day\n-person= 1;\n hour= 2;\n day= 3.\n /-");
		scanf("%d",&in);
		if(in == 2){
			printf("give me the hour\n/-");
			scanf("%d",&t);
		print(callander, 000, t);
		}
		else if(in == 3){
			print(callander, 000, 999);
		     }
		     else if(in == 1){
			     printf("give me his id\n/-");
			     scanf("%d",&id);
			     print(callander, id, 999);
		          }
	     }
	     else{printf("wrong input\n");}
  }	     
}
