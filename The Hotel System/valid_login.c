#define USERS 100
#define PASS 50

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "valid_login.h"

int valid_login(){
FILE*fr=fopen("users.txt","r");
if(fr==NULL){
printf("error in opening file\n");
exit(1);}
char u[USERS];
char p[PASS];
char user[USERS];
char pswd[PASS];
int flag=0;
printf("enter the user name:");
scanf(" %s",u);
printf("enter the password:");
scanf(" %s",p);
while(!feof(fr)){
fscanf(fr,"%s",user);
fscanf(fr,"%s",pswd);
if((strcmp(user,u)==0) && (strcmp(pswd,p)==0)){
flag=1;
break;
}
}
 fclose(fr);
  if(flag==1)
  printf("valid login\n");
  else printf("invalid login ,error in username or password\n");
  return flag;
}
