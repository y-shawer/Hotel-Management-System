#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "Reservation.h"

typedef struct{
    int d;
    int m;
    int y;
}date;

void reserveRoom(int p){

    load();
    FILE *fp,*fp1,*fpt;
    char save,exit,n[100],em[100],rc[100],*rn,s[100],line[200],rline[200][200],mn[100],nid[100],nights[100];
    int nrid,i=0,emflag=0,mnv,nidv,b,idi,nv,ni,rcn,nvi,nvv;
    date d,c;

    long pos;
    time_t now;
    time(&now);
    struct tm*local =localtime(&now);
    c.d=local->tm_mday;
    c.m=local->tm_mon+1;
    c.y=local->tm_year+1900;
    fp=fopen("reservations.txt","r");
    if(!fp){
        printf("Error in opening file");
        return;
    }
    rewind(fp);
   while(!feof(fp)){
    fgets(line,200,fp);
    i++;
   }
    rewind(fp);
    int j;
    for(j=0;j<i-1;j++){
        fgets(line,200,fp);
    pos=ftell(fp);
}
    fseek(fp,pos,SEEK_SET);
    fgets(s,200,fp);
    char *rid = strtok(s,",");
    fclose(fp);
    nrid=atoi(rid);
    srand(nrid);
    nrid=rand();
    while(nrid<9999){
        srand(nrid);
        nrid=rand();
    }
    fp=fopen("reservations.txt","a");
    if(!fp){
        printf("Error in opening file");
        return;
    }
    printf("Customer name:\n");
    if(p==1)
    getchar();
    gets(n);
    for(nvi=0;nvi<strlen(n);nvi++){
        if(n[nvi]==' '){
            nvv=1;
            break;}

    }
    while(strlen(n)<7||nvv==0){
        printf("Please enter a valid name (minimum 3 characters in two names)!\n");
        nvv=0;
        gets(n);
         for(nvi=0;nvi<strlen(n);nvi++){
        if(n[nvi]==' '){
            nvv=1;
            break;}

    }
    }
    printf("National ID:\n");
    gets(nid);
    for(idi=0;idi<14;idi++){
        if(!isdigit(nid[idi])){
            nidv=0;
        break;}
        nidv=1;
    }
    while((strlen(nid)!=14&&(nid[0]!=2||nid[0]!=3))||nidv==0){
        printf("Please enter a Valid national ID:\n");
        gets(nid);
        for(idi=0;idi<14;idi++){
        if(!isdigit(nid[idi])){
            nidv=0;
        break;}
        nidv=1;

    }
    }
    printf("Customer Email:\n");
    gets(em);
    for(i=1;i<100;i++){
        if(em[0]!='@')
        if(em[i]=='@')
            if(em[i+1]!='.')
            for(j=i;j<100;j++)
        if(em[j]=='.')
        if(em[j+1]!='\0'){
            emflag=1;
            break;
        }

    }
    while(emflag==0){
        printf("Please enter a valid Email:\n");
        gets(em);
         for(i=0;i<100;i++)
             if(em[0]!='@'){
        if(em[i]=='@')
             if(em[i+1]!='.')
            for(j=i;j<100;j++)
        if(em[j]=='.')
         if(em[j+1]!='\0'){
            emflag=1;
            break;
        }

    }
    }
    printf("Customer mobile number:\n");
    gets(mn);
    for(b=0;b<11;b++){
        if(!isdigit(mn[b])){
            mnv=0;
        break;}
        mnv=1;

    }
    while(strlen(mn)!= 11||mn[0]!='0'||mnv==0)
    {
        printf("Please enter a valid Egyptian mobile number:\n");
        gets(mn);
         for(b=0;b<11;b++){
        if(!isdigit(mn[b])){
            mnv=0;
        break;}

    }mnv=1;
    }
    if(p==1){
        d.d=c.d;
        d.m=c.m;
        d.y=c.y;

    }
  if(p==0){   printf("Year of check-in:\n");
    scanf("%d",&d.y);
    while(d.y<c.y||d.y>2026)
    {
        printf("Please enter a valid year (maximum 2026):\n");
        scanf("%d",&d.y);

    }
     printf("Month of check-in:\n");
    scanf("%d",&d.m);
    if(d.y==c.y){
        while(d.m<c.m||d.m>12)
    {
        printf("Please enter a valid month:\n");
        scanf("%d",&d.m);
    }
    }
    else while(d.m<1||d.m>12)
    {
        printf("Please enter a valid month:\n");
        scanf("%d",&d.m);

    }
    printf("Day of check-in:\n");
    scanf("%d",&d.d);
    if(d.y==c.y)
    {
        if(d.m==1 || d.m==3 || d.m==5 || d.m==7 || d.m==8 || d.m==10 || d.m==12)
    while(d.d<c.d||d.d>31)
    {
        printf("Please enter a valid day:\n");
        scanf("%d",&d.d);

    }
    else if(d.m==4||d.m==6||d.m==9||d.m==11)
         while(d.d<c.d||d.d>30)
    {
        printf("Please enter a valid day:\n");
        scanf("%d",&d.d);

    }
    else
        while(d.d<c.d||d.d>28)
    {
        printf("Please enter a valid day:\n");
        scanf("%d",&d.d);

    }
    }
    else {if(d.m==1 || d.m==3 || d.m==5 || d.m==7 || d.m==8 || d.m==10 || d.m==12)
    while(d.d<1||d.d>31)
    {
        printf("Please enter a valid day:\n");
        scanf("%d",&d.d);

    }
    else if(d.m==4||d.m==6||d.m==9||d.m==11)
         while(d.d<1||d.d>30)
    {
        printf("Please enter a valid day:\n");
        scanf("%d",&d.d);

    }
    else
        while(d.d<1||d.d>28)
    {
        printf("Please enter a valid day:\n");
        scanf("%d",&d.d);

    }

    }}
    printf("Number of nights:\n");
   if(p==0) getchar();
    gets(nights);
    for(ni=0;ni<strlen(nights);ni++){
        if(!isdigit(nights[ni])){
            nv=0;
            break;
        }nv=1;

    }

    while(nv==0){
        printf("Please enter a valid nights number:\n");
        gets(nights);
        for(ni=0;ni<strlen(nights);ni++){
        if(!isdigit(nights[ni])){
            nv=0;
            break;
        }nv=1;

    }

    }
    printf("Room category:\n1-LakeView\n2-GardenView\n3-SeaView:\n");
    scanf(" %d",&rcn);
    getchar();
    while(rcn!=1&&rcn!=2&&rcn!=3)
    {
        printf("Please enter a valid room category\n1-LakeView\n2-GardenView\n3-SeaView:\n");
        scanf(" %d",&rcn);
        getchar();
    }
    if(rcn==1){
        strcpy(rc,"LakeView");
    }
    if(rcn==2){
        strcpy(rc,"GardenView");
    }
    if(rcn==3){
        strcpy(rc,"SeaView");
    }

    rn="0";
    int k=0;
    fp1=fopen("Room.txt","r");
    if(!fp1){
        printf("Error in opening file");
        return;
    }
   i=0;
    while(!feof(fp1)){
        fgets(rline[i],200,fp1);
        i++;
    }
    k=i;
    for(i=0;i<k;i++){
    if(rline[i][5]=='A')
        if(rline[i][15]==rc[0])
        { rn=strtok(rline[i]," ");
        break;
        }

    }
    while(rn[0]=='0')
    {   printf("No available rooms of this category!\n");
        printf("Would you like to exit?(\033[0;32mY\033[0;37m/\033[0;31mN\033[0;37m)\n");
        scanf(" %c",&exit);
    while(exit!='Y'&&exit!='N'&&exit!='y'&&exit!='n')
    {
        printf("Please enter a valid character:\n");
        scanf(" %c",&exit);
    }
    if(exit=='y'|| exit=='Y')
        return;
    else{
            rcn=0;
        printf("Room category:\n1-LakeView\n2-GardenView\n3-SeaView:\n");
        scanf(" %d",&rcn);
    getchar();
    while(rcn!=1&&rcn!=2&&rcn!=3)
    {
        printf("Please enter a valid room category\n1-LakeView\n2-GardenView\n3-SeaView:\n");
        scanf(" %d",&rcn);
        getchar();
    }
    if(rcn==1){
        strcpy(rc,"LakeView");
    }
    if(rcn==2){
        strcpy(rc,"GardenView");
    }
    if(rcn==3){
        strcpy(rc,"SeaView");
    }

     i=0;
     rewind(fp1);
    while(!feof(fp1)){
        fgets(rline[i],200,fp1);
        i++;
    }
    k=i;
    for(i=0;i<k;i++){
    if(rline[i][5]=='A')
        if(rline[i][15]==rc[0])
        { rn=strtok(rline[i]," ");
        break;
        }
    }
    }
    }
fclose(fp1);
    char q[50];
    printf("Do you want to save?(\033[0;32mY\033[0;37m/\033[0;31mN\033[0;37m):\n");
    gets(q);
    while(strlen(q)!=1||(q[0]!='y'&&q[0]!='Y'&&q[0]!='n'&&q[0]!='N'))
    {   printf("Please enter a valid character:\n");
        gets(q);
    }
    save=q[0];
    if(save=='y'||save=='Y')
{
    total_customers=total_customers+1;
    x[total_customers].id=nrid;
    x[total_customers].room=atoi(rn);
    if(p==0)
    strcpy(x[total_customers].status,"unconfirmed");
    else if(p==1)
    strcpy(x[total_customers].status,"confirmed");
    strcpy(x[total_customers].name,n);
    strcpy(x[total_customers].nid,nid);
    x[total_customers].nights=atoi(nights);
    sprintf(x[total_customers].date,"%d-%d-%d",d.d,d.m,d.y);
    strcpy(x[total_customers].email,em);
    strcpy(x[total_customers].number,mn);



    fprintf(fp,"%c",'\n');
    fprintf(fp,"%d,",x[total_customers].id);
    fprintf(fp,"%d,",x[total_customers].room);
    fprintf(fp,"%s,",x[total_customers].status);
    fprintf(fp,"%s,",x[total_customers].name);
    fprintf(fp,"%s,",x[total_customers].nid);
    fprintf(fp,"%d,",x[total_customers].nights);
    fprintf(fp,"%s,",x[total_customers].date);
    fprintf(fp,"%s,",x[total_customers].email);
    fprintf(fp,"%s",x[total_customers].number);

    fpt=fopen("temp.txt","w");
    if(!fpt){
        printf("Error in opening file");
        return;
    }
    fp1=fopen("Room.txt","r");
    if(!fp1){
        printf("Error in opening file");
        return;
    }
    int linen=0;
    char * pos1;
    char liner[200];
    while(fgets(liner,200,fp1)){
        if(linen==i){
        pos1=strstr(liner, "Available");
        if(pos1){
        *pos1='\0';
        fprintf(fpt,"%s%s%s",liner,"Reserved",pos1+9);
        }else{
        fprintf(fpt,"%s",liner);
            }
        }else{
        fprintf(fpt,"%s",liner);
            }
        linen++;
        }
    fclose(fp1);
    fclose(fpt);
    remove("Room.txt");
    rename("temp.txt","Room.txt");

    printf("The reservation ID is: %d\n",x[total_customers].id);
    printf("The reservation has been confirmed\n");

}
else printf("The reservation has been canceled\n");
    fclose(fp);

}
