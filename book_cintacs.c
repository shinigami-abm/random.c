#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ps 115

typedef struct contact{
 char name[100];
 char pn[10];//phone_number
} contact;

 void fill_file(contact r){
    FILE *f;
    int ctr=-1;
    f= fopen("contacts.txt", "a");
    fprintf(f,"%-100s %d %-10s\n",r.name,ctr,r.pn);
    //fwrite(&r, sizeof(contact), 1, f);
    fclose(f); 
 }
 
 void read_file(){
  FILE *f;
  char n[100],p[11];
  int ctr;
  f= fopen("contacts.txt", "r");
  printf("Name,Phone Number\n");
  while(fscanf(f,"%s %d %s",n,&ctr,p) != EOF){
    printf("%s,%s\n",n,p);
  }
   printf("\n\n");
  fclose(f);
 }

 int search(char who[]){
   FILE *f;
  char n[100],p[11];
  int ctr,i=0;
  f= fopen("contacts.txt", "r");
  while(fscanf(f,"%s %d %s",n,&ctr,p) != EOF){
   if(strcmp(n, who) == 0){
     fclose(f);	   
    return i;
   }
   i++;
  }
  fclose(f);
  return -1;
 }
 
 void update(char p[],char newP[]){
    FILE *f;
    f= fopen("contacts.txt", "r+");
    int count,ctr=-1;
    if(search(p) != -1){
    count = search(p);
    char n[100];
    fseek(f,count*ps, SEEK_SET);
    //printf("%s\n",n);
    fprintf(f,"%-100s %d %-10s",p,ctr,newP);
    }
    else{
	    printf("this person dont exist.\n");
    }
    fclose(f);
 }

int main(){
contact c={"Grace", "0795703211"};
contact c0={"Alice", "0612345678"};
contact c1={"carol", "0698525674"};
contact c2={"David", "0745452102"};
contact c3={"Emma", "0265696326"};
contact c4={"Frank", "0398148794"};
contact c5={"Bob", "0698163728"};
contact c6={"Henry", "0792468392"};
contact c7={"Irene", "0863192455"};
contact c8={"Jack", "0999999999"};
fill_file(c);
fill_file(c0);
fill_file(c1);
fill_file(c2);
fill_file(c3);
fill_file(c4);
fill_file(c5);
fill_file(c6);
fill_file(c7);
fill_file(c8);
read_file();
update("Bob","0000000000");
//printf("%ld\n",sizeof("Grace0795703211Alice0612345678carol0698525674David0745452102Emma0265696326Frank039814"));
read_file();
return 33;
}
