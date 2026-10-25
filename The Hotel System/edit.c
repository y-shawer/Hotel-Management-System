#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "edit.h"


void EditReservation()
{
    char x[10];
   printf("please Enter Room number or reservation ID  :\n");
    scanf(" %s", x);
    getchar();



int night=0,emflag=0,i=0,j=0,nvi=0,nvv=0,ni=0,nv=0,b=0,mnv=0;
date d,c;

    time_t now;
    time(&now);
struct tm*local =localtime(&now);
    c.d=local->tm_mday;
    c.m=local->tm_mon+1;
    c.y=local->tm_year+1900;

FILE *res_file, *temp_file;
res_file = fopen("reservations.txt", "r");
temp_file = fopen("Temp.txt", "w");
if(!res_file||!temp_file)
{printf("Error opening file Reservation.txt\n");return;}

char line[120];
int found = 0;
char *room_number;
char *res_id;
char rm[20];
while (fgets(line, sizeof(line), res_file))
{
char temp_line[120];
strcpy(temp_line, line);
int n;
char *search = strtok(temp_line, ",");

if(strlen(x)<5){res_id=search;search= strtok(NULL, ",");n=2;room_number=search;}
else{n=3;res_id=search;}
if(search && (strcmp(search, x) == 0)){
        found=1;


char newName[50]="";
char newMobile[20]="";
char newEmail[50]="";
char*Status ;
char*National_ID;
char newNights[5]="";
char newdate[10]="";
for (int i = 0; i < n && search != NULL; i++)
{search = strtok(NULL, ",");
if(n==3&&i==0){room_number=search;}
if(n==3&&i==1){Status=search;}
if(n==2&&i==0){Status=search;}}

char ena,eni,ed,eem,em,roc;
 char a[50];
printf("Do you want to edit name?(\033[0;32mY\033[0;37m/\033[0;31mN\033[0;37m):\n");
    gets(a);
    while(strlen(a)!=1||(a[0]!='y'&&a[0]!='Y'&&a[0]!='n'&&a[0]!='N'))
    {   printf("Please enter a valid character:\n");
        gets(a);
    }
    ena=a[0];
if(ena=='y'||ena=='Y')
{printf("Enter new name:\n");

gets(newName);
for(nvi=0;nvi<strlen(newName);nvi++){
        if(newName[nvi]==' '){
            nvv=1;
            break;}
    }

while(strlen(newName)<7||nvv==0){
    printf("Please enter a valid name (minimum 3 characters in two names)!\n");
    nvv=0;
    gets(newName);
    for(nvi=0;nvi<strlen(newName);nvi++){
        if(newName[nvi]==' '){
            nvv=1;
            break;}
}
    }

}
else strcpy(newName,search);

search = strtok(NULL, ",");
National_ID=search;
search = strtok(NULL, ",");


printf("Do you want to edit Nights?(\033[0;32mY\033[0;37m/\033[0;31mN\033[0;37m):\n");
  char f[50];
    gets(f);
    while(strlen(f)!=1||(f[0]!='y'&&f[0]!='Y'&&f[0]!='n'&&f[0]!='N'))
    {   printf("Please enter a valid character:\n");
        gets(f);
    }
   eni=f[0];
if(eni=='y'||eni=='Y')
{
printf("Number of nights:\n");
gets(newNights);
    for(ni=0;ni<strlen(newNights);ni++){
        if(!isdigit(newNights[ni])){
            nv=0;
            break;
        }nv=1;

    }

    while(nv==0){
        printf("Please enter a valid nights number:\n");
        gets(newNights);
        for(ni=0;ni<strlen(newNights);ni++){
        if(!isdigit(newNights[ni])){
            nv=0;
            break;
        }nv=1;

    }

    }
}
else night=atoi(search);

search = strtok(NULL, ",");

printf("Do you want to edit Date?(\033[0;32mY\033[0;37m/\033[0;31mN\033[0;37m):\n");
char k[50];

    gets(k);
    while(strlen(k)!=1||(k[0]!='y'&&k[0]!='Y'&&k[0]!='n'&&k[0]!='N'))
    {   printf("Please enter a valid character:\n");
        gets(k);
    }
    ed=k[0];
if(ed=='y'||ed=='Y')
{


printf("Year of check-in:\n");
    scanf("%d",&d.y);
while(d.y<c.y||d.y>2026)
    {printf("Please enter a valid year (maximum 2026):\n");scanf("%d",&d.y);}

printf("Month of check-in:\n");
    scanf("%d",&d.m);
if(d.y==c.y)
{while(d.m<c.m||d.m>12)
{printf("Please enter a valid month:\n");scanf("%d",&d.m);}
}
else
    while(d.m<1||d.m>12)
    {printf("Please enter a valid month:\n");scanf("%d",&d.m);}
printf("Day of check-in:\n");
    scanf("%d",&d.d);
    if(d.y==c.y)
    {
if(d.m==1 || d.m==3 || d.m==5 || d.m==7 || d.m==8 || d.m==10 || d.m==12)
    while(d.d<c.d||d.d>31)
    {printf("Please enter a valid day:\n");scanf("%d",&d.d);}
else if(d.m==4||d.m==6||d.m==9||d.m==11)
    while(d.d<c.d||d.d>30)
    {printf("Please enter a valid day:\n");scanf("%d",&d.d);}
else
    while(d.d<c.d||d.d>28)
    {printf("Please enter a valid day:\n");scanf("%d",&d.d);}

     }
else {
if(d.m==1 || d.m==3 || d.m==5 || d.m==7 || d.m==8 || d.m==10 || d.m==12)
    while(d.d<1||d.d>31)
    {printf("Please enter a valid day:\n");scanf("%d",&d.d);}
else if(d.m==4||d.m==6||d.m==9||d.m==11)
         while(d.d<1||d.d>30)
    {printf("Please enter a valid day:\n");scanf("%d",&d.d);}
else
    while(d.d<1||d.d>28)
{printf("Please enter a valid day:\n");scanf("%d",&d.d);}}

sprintf(newdate,"%d-%d-%d",d.d,d.m,d.y);
}
else strcpy(newdate,search);

search = strtok(NULL, ",");

printf("Do you want to edit email?(\033[0;32mY\033[0;37m/\033[0;31mN\033[0;37m):\n");
char d[50];
if(ed=='y'||ed=='Y')
getchar();
    gets(d);
    while(strlen(d)!=1||(d[0]!='y'&&d[0]!='Y'&&d[0]!='n'&&d[0]!='N'))
    {   printf("Please enter a valid character:\n");
        gets(d);
    }
    eem=d[0];
if(eem=='y'||eem=='Y')
{
printf("Customer Email:\n");

    gets(newEmail);
for(i=1;i<100;i++){
if(newEmail[0]!='@')
if(newEmail[i]=='@')
if(newEmail[i+1]!='.')
for(j=i;j<100;j++)
if(newEmail[j]=='.')
if(newEmail[j+1]!='\0'){emflag=1;break;}}
    while(emflag==0){
printf("Please enter a valid Email:\n");
gets(newEmail);
for(i=0;i<100;i++)
if(newEmail[0]!='@'){
if(newEmail[i]=='@')
if(newEmail[i+1]!='.')
for(j=i;j<100;j++)
if(newEmail[j]=='.')
if(newEmail[j+1]!='\0'){emflag=1;break;}}}

}
else strcpy(newEmail,search);

search = strtok(NULL, ",");

printf("Do you want to edit mobile?(\033[0;32mY\033[0;37m/\033[0;31mN\033[0;37m):\n");
  char c[50];

    gets(c);
    while(strlen(c)!=1||(c[0]!='y'&&c[0]!='Y'&&c[0]!='n'&&c[0]!='N'))
    {   printf("Please enter a valid character:\n");
        gets(c);
    }
    em=c[0];
if(em=='y'||em=='Y')
{
    printf("Customer mobile number:\n");

    gets(newMobile);
    for(b=0;b<11;b++){
        if(!isdigit(newMobile[b])){
            mnv=0;
        break;}
        mnv=1;

    }
    while(strlen(newMobile)!= 11||newMobile[0]!='0'||mnv==0)
    {
        printf("Please enter a valid Egyptian mobile number:\n");
        gets(newMobile);
         for(b=0;b<11;b++){
        if(!isdigit(newMobile[b])){
            mnv=0;
        break;}

    }mnv=1;
    }
}
else strcpy(newMobile,search);
char *rn;
char rline[200][200];
char rc[20];
printf("Do you want to edit room category?(\033[0;32mY\033[0;37m/\033[0;31mN\033[0;37m):\n");
 char b[50];

    gets(b);
    while(strlen(b)!=1||(b[0]!='y'&&b[0]!='Y'&&b[0]!='n'&&b[0]!='N'))
    {   printf("Please enter a valid character:\n");
        gets(b);
    }
    roc=b[0];
if(roc=='y'||roc=='Y')
{
printf("Room category:\n");

gets(rc);
while((strcmp(rc,"GardenView")!=0)&&(strcmp(rc,"LakeView")!=0)&&(strcmp(rc,"SeaView")!=0))
{printf("Please enter a valid room category (LakeView - GardenView - SeaView):\n");gets(rc);}
rn="0";
int k=0;
FILE*fp1=fopen("Room.txt","r");
if(!fp1){printf("Error in opening file");return;}
   int i=0;
while(!feof(fp1)){fgets(rline[i],200,fp1);i++;}
k=i;
for(i=0;i<k;i++){if(rline[i][5]=='A')if(rline[i][15]==rc[0]){ rn=strtok(rline[i]," ");break;}}
char exit;
while(rn[0]=='0'){printf("No available rooms of this category!\n");printf("Would you like to exit?(Y/N)\n");
scanf(" %c",&exit);
    while(exit!='Y'&&exit!='N'&&exit!='y'&&exit!='n')
    {printf("Please enter a valid character:\n");scanf(" %c",&exit);}
    if(exit=='y'|| exit=='Y')return;
else{printf("Room category:\n");getchar();gets(rc);i=0;
while(!feof(fp1)){fgets(rline[i],200,fp1);i++;}
k=i;
for(i=0;i<k;i++){if(rline[i][5]=='A')if(rline[i][15]==rc[0]){ rn=strtok(rline[i]," ");break;}}}}

UpdateRoomStatus(atoi(room_number));
strcpy(room_number,rn);

UpdateRoomStatus(atoi(room_number));
fclose(fp1);

}
strcpy(rm,room_number);
fprintf(temp_file, "%s,%s,%s,%s,%s,%d,%s,%s,%s",res_id,room_number,Status,newName,National_ID,night,newdate,newEmail,newMobile );
if(em=='y'||em=='Y')fprintf(temp_file,"\n");

}
else  fprintf(temp_file, "%s", line);
}

fclose(res_file);
fclose(temp_file);
char save;
if (!found) {
    remove("Temp.txt");
    printf("Reservation not found.\n");
}
else{
     char q[50];
    printf("Do you want to save?(\033[0;32mY\033[0;37m/\033[0;31mN\033[0;37m):\n");

    gets(q);
    while(strlen(q)!=1||(q[0]!='y'&&q[0]!='Y'&&q[0]!='n'&&q[0]!='N'))
    {   printf("Please enter a valid character:\n");
        gets(q);
    }
    save=q[0];

    if(save=='y'||save=='Y'){
remove("reservations.txt");
rename("Temp.txt", "reservations.txt");
printf("Reservation updated successfully.\n");
if(found==1)printf("the new room number is %s \n",rm);

}

else {remove("Temp.txt");
    printf("Edits not saved!\n");
}
}
}
