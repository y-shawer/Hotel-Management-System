#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "load.h"
#define USERS 100
#define Rooms 100

typedef struct{
int id,room,nights;
char status[20],name[50],nid[50],date[50],email[50],number[20];
}customer;

customer x[USERS];
int total_customers;


void load(){
int i=0;
total_customers=0;
char a[500];
char*token;
FILE*fl=fopen("reservations.txt","r");
if(fl==NULL){
printf("error in opening file ");
exit(1);}
while(!feof(fl)){
fgets(a,499,fl);
if(a==EOF){
    break;}
token=strtok(a,",");
x[i].id=atoi(token);

token=strtok(NULL,",");
x[i].room=atoi(token);

token=strtok(NULL,",");
strcpy(x[i].status,token);

token=strtok(NULL,",");
strcpy(x[i].name,token);

token=strtok(NULL,",");
strcpy(x[i].nid,token);

token=strtok(NULL,",");
x[i].nights=atoi(token);

token=strtok(NULL,",");
strcpy(x[i].date,token);

token=strtok(NULL,",");
strcpy(x[i].email,token);

token=strtok(NULL,",");
strcpy(x[i].number,token);
i++;
}
total_customers=i;
fclose(fl);
}


typedef struct {
    int room_num, price;
    char status[25],category[25];
} rooms;

rooms y[Rooms];
int total_rooms = 0;

void loadRoom() {
    int i = 0;
    char line[300];
    char *token;
    FILE *f = fopen("Room.txt", "r");
    if (f == NULL) {
        printf("Error in opening file\n");
        exit(1);
    }
    while (fgets(line, 299, f) != NULL) {
        token = strtok(line, " ");
        y[i].room_num = atoi(token);

        token = strtok(NULL, " ");
        strcpy(y[i].status, token);

        token = strtok(NULL, " ");
        strcpy(y[i].category, token);

        token = strtok(NULL, " ");
        y[i].price = atoi(token);

        i++;
    }
    total_rooms = i;
    fclose(f);
}


