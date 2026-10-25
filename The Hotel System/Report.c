#include "Report.h"


void report(){

load();
int d;
int m;
int yearr;
char dob1[40];
char dob2[40];
int i;
int flag=0;
printf("enter the day:");
scanf("%d",&d);
while(1){
if(d>=1&&d<=31)
break;
else {
printf("enter valid day");
scanf("%d",&d);}
}
printf("enter the month number:");
scanf("%d",&m);
while(1){
if(m>=1&&m<=12)
break;
else {
printf("enter valid month number:");
scanf("%d",&m);}
}
printf("enter the year:");
scanf("%d",&yearr);
while(1){
if(yearr>=2024)
break;
else {
printf("enter valid year:");
scanf("%d",&yearr);}}
sprintf(dob1,"%02d-%02d-%d",d,m,yearr);
sprintf(dob2,"%d-%d-%d",d,m,yearr);
load();
for(i=0;i<total_customers;i++){
if(strcmp(dob1,x[i].date)==0||strcmp(dob2,x[i].date)==0){
printf("reservation id:%d\n",x[i].id);
printf("room number:%d\n",x[i].room);
printf("room status:%s\n",x[i].status);
printf("the customer name:%s\n",x[i].name);
printf("the national id:%s\n",x[i].nid);
printf("the number of nights:%d\n",x[i].nights);
printf("the check in date:%s\n",x[i].date);
printf("the e-mail:%s\n",x[i].email);
printf("the mobile number:%s\n",x[i].number);
printf("*************************************\n");
flag=1;}
}
if(flag!=1)
printf("there aren't any customers in %s",dob2);
}
