#include "search.h"



void print_rooms(int i){
printf("the number of room:%d\n",y[i].room_num);
printf("the category of the room:%s\n",y[i].category);
printf("the price of the room:%d\n",y[i].price);
printf("****************\n");
}

void search(){
int key,i;
printf("if you want to search by customer name press 1\n");
printf("if you want to search by room number press 2\n");
printf("if you want to search by  room status press 3\n");
printf("******************\n");
printf("enter a valid number: ");
scanf("%d",&key);
while(getchar()!='\n');
while(1){
if(key==1||key==2||key==3)
break;
else {printf("enter a valid number: ");
      scanf(" %d",&key);
      while(getchar()!='\n');}
}
if(key==1){
load();
char cname[40];
printf("enter the customer name: ");
gets(cname);
for(i=0;i<total_customers;i++){
if(strcmp(cname,x[i].name)==0)
break;
}
if(i<total_customers){
printf("reservation id:%d\n",x[i].id);
printf("room number:%d\n",x[i].room);
printf("room status:%s\n",x[i].status);
printf("the customer name:%s\n",x[i].name);
printf("the national id:%s\n",x[i].nid);
printf("the number of nights:%d\n",x[i].nights);
printf("the check in date:%s\n",x[i].date);
printf("the e-mail:%s\n",x[i].email);
printf("the mobile number:%s\n",x[i].number);
printf("*************\n");}
else printf("invalid name\n");
}
if(key==2){
load();
loadRoom();
int rnumber;
printf(" enter the room number: ");
scanf("%d",&rnumber);
for(i=0;i<total_rooms;i++){
if(rnumber==y[i].room_num)
break;}
if(i<total_rooms)
printf("the room is:%s\n",y[i].status);
else {printf("invalid room number ");
return;}
if(strcmp("Reserved",y[i].status)==0){
for(i=0;i<total_customers;i++){
if(rnumber==x[i].room)
break;
}
if(i<total_customers){
printf("reservation id:%d\n",x[i].id);
printf("room number:%d\n",x[i].room);
printf("room status:%s\n",x[i].status);
printf("the customer name:%s\n",x[i].name);
printf("the national id:%s\n",x[i].nid);
printf("the number of nights:%d\n",x[i].nights);
printf("the check in date:%s\n",x[i].date);
printf("the e-mail:%s\n",x[i].email);
printf("the mobile number:%s\n",x[i].number);
printf("*************\n");}
else printf("invalid room number\n");
}}
if(key==3){
loadRoom();
int skey;
printf("if you want available rooms press 1\n");
printf("if you want reserved rooms press 2\n\n");
printf("enter a valid number to search: ");
scanf("%d",&skey);
while(1){
if(skey==1||skey==2)
break;
else{
printf("enter a valid number: ");
scanf("%d",&skey);}
}
if(skey==1){
for(i=0;i<total_rooms;i++){
if(strcmp("Available",y[i].status)==0)
print_rooms(i);}
}
if(skey==2){
for(i=0;i<total_rooms;i++){
if(strcmp("Reserved",y[i].status)==0)
print_rooms(i);}
}}}
