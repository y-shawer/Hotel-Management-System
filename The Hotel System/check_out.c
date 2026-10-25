#include "check_out.h"

void checkOut() {
    load();
    loadRoom();
    int id, found = 0,confirmed=0,price;
    printf("Enter Reservation ID for Check-Out: ");
    scanf("%d", &id);

    for (int i = 0; i < total_customers; i++) {
        if (x[i].id == id) {
            found = 1;
            if (strcmp(x[i].status, "confirmed") == 0) {
                    for(int k=0;k<total_rooms;k++)
                    if(x[i].room==y[k].room_num)
                    price=y[k].price;
                int total_bill = x[i].nights * price;
                printf("Check-Out Successful for %s (Room: %d)\n", x[i].name, x[i].room);
                printf("The total Bill: %d\n", total_bill);
                UpdateRoomStatus(x[i].room);
                confirmed=1;
                for (int j = i; j < total_customers - 1; j++) {
                    x[j] = x[j + 1];
                }
                total_customers--;
            } else {
                printf("Reservation is not confirmed or invalid for Check-Out.\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Reservation ID not found.\n");
        return;
    }
     char q[50],save;

    if(found&&confirmed) {printf("Do you want to save?(\033[0;32mY\033[0;37m/\033[0;31mN\033[0;37m):\n");
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
        printf("Error in opening file.\n");
        exit(1);
    }
    for (int i = 0; i < total_customers; i++) {
        fprintf(fl, "%d,%d,%s,%s,%s,%d,%s,%s,%s",
                x[i].id, x[i].room, x[i].status, x[i].name, x[i].nid,
                x[i].nights, x[i].date, x[i].email, x[i].number);
    }
    fclose(fl);
}else{printf("Check-out not saved!\n");}
}}
