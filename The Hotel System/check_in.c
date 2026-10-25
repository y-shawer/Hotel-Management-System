#include <time.h>
#include "check_in.h"

void checkIn() {
    load();
int i;
    char res,datetemp[50];
    date t,d;
      time_t now;
    time(&now);
    struct tm*local =localtime(&now);
    t.d=local->tm_mday;
    t.m=local->tm_mon+1;
    t.y=local->tm_year+1900;
    printf("Does the customer have a reservation?(\033[0;32mY\033[0;37m/\033[0;31mN\033[0;37m)\n");
    scanf(" %c",&res);
    while(res!='y'&&res!='Y'&&res!='n'&&res!='N')
        {
        printf("Please enter a valid character:\n");
        scanf(" %c",&res);
    }
    if(res=='n'||res=='N')
        reserveRoom(1);

    int id, found = 0;
    printf("Enter Reservation ID for Check-In: ");
    scanf(" %d",&id);

    for (i = 0; i < total_customers; i++) {
        if (x[i].id == id) {
            found = 1;
            break;}}
            strcpy(datetemp,x[i].date);
            d.d=atoi(strtok(datetemp,"-"));
            d.m=atoi(strtok(NULL,"-"));
            d.y=atoi(strtok(NULL,","));
            if(found){
                    printf("Reservation id: %d\n",x[i].id);
                printf("Name: %s\n",x[i].name);
                printf("Room Number: %d\n",x[i].room);
                printf("Status: %s\n",x[i].status);
            if (strcmp(x[i].status, "confirmed") == 0)
                {    printf("Reservation is already confirmed or invalid for Check-In.\n");
                return;}

             else if(t.y<d.y){
                    printf("Customer cannot check in before check in date!\n");
                    return;
            }else if(t.y==d.y&&t.m<d.m){
                printf("Customer cannot check in before check in date!\n");
                return;
            }
            else if(t.y==d.y&&t.m&&d.m&&t.d<d.d){
                printf("Customer cannot check in before check in date!\n");
                return;
            }

    else{
        strcpy(x[i].status,"confirmed");
        printf("Customer checked in successfully!\n");
    }

            }
    if (!found) {
        printf("Reservation ID not found.\n");
    }
    char q[50];
    char save;
    printf("Do you want to save?(\033[0;32mY\033[0;37m/\033[0;31mN\033[0;37m):\n");
    getchar();
    gets(q);
    while(strlen(q)!=1||(q[0]!='y'&&q[0]!='Y'&&q[0]!='n'&&q[0]!='N'))
    {   printf("Please enter a valid character:\n");
        gets(q);
    }
    save=q[0];
    if(save=='y'||save=='Y'){

    FILE *fl = fopen("reservations.txt", "w");
    if (fl == NULL) {
        printf("Error in opening file for writing.\n");
        exit(1);
    }
    for (int i = 0; i < total_customers; i++) {
        fprintf(fl, "%d,%d,%s,%s,%s,%d,%s,%s,%s",
                x[i].id, x[i].room, x[i].status, x[i].name, x[i].nid,
                x[i].nights, x[i].date, x[i].email, x[i].number);
    }
    fclose(fl);
}}
