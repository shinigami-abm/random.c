



 this=&a;
 printf("This is the numbers of the list in order:\n");

 
                      while(this != NULL){ 
                         
			      printf("%d ",this->data);
                              this=this->next;
                      }

                      printf("\n");

                           this=&a;

			   while(this != NULL){

				   pemp=this->next;
				   this->next=this->prv;
				   this->prv=pemp;
				   this=this->prv;
			   }

                                          this=&e;
					  printf("This is the numbers after the revers:\n");
					  while( this != NULL){
						  printf("%d ",this->data);
						  this=this->next;
					  }
					  printf("\n");






























}  
