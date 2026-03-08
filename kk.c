#include<stdio.h>
int main(){
 FILE *f;
  f = fopen("kk.txt", "r");
  char name[100],fname[100];
  int age,id;
  float avr;
  char sexe[10];
 while(fscanf(f, "%s %s %d %d %f %s", name, fname, &age, &id, &avr, sexe) != EOF){
   printf("Name; %s\n",name);
   printf("Famly name; %s\n",fname);
   printf("Gender; %s\n",sexe);
   printf("ID; %d\n",id);
   printf("Age; %d\n",age);
   printf("Average; %f\n",avr);
 }
 fclose(f);
return 0;
}
