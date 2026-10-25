#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cancel.h"

void CancelReservation() {
    load();
    loadRoom();
    int choice, id,r, found = 0, confirmed = 0;
    char q, save;
    printf("Cancel:\n");
    printf("1.by Reservation ID\n");
    printf("2.by by Room Number\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    getchar();
    if (choice == 1) {
        printf("Please enter reservation ID:\n");
        scanf("%d", &id);
        getchar();
    } else if (choice == 2) {
        printf("Please enter room number:\n");
        scanf("%d", &r);
        getchar();
    } else {
        printf("Invalid choice. Please enter 1 or 2.\n");
        return;
    }
     if (choice == 1) {
    for (int i = 0; i < total_customers; i++) {
        if (x[i].id == id) {
            found = 1;
            if (strcmp(x[i].status, "unconfirmed") == 0) {
                confirmed = 1;
                UpdateRoomStatus(x[i].room);

                for (int j = i; j < total_customers - 1; j++) {
                    x[j] = x[j + 1];
                }
                total_customers--;
                printf("Reservation canceled successfully.\n");
            } else {
                printf("Reservation cannot be canceled as it is already confirmed.\n");
            }
            break;}}}
       else if (choice == 2) {
              for (int i = 0; i < total_customers; i++) {
        if (x[i].room == r) {
            found = 1;
            if (strcmp(x[i].status, "unconfirmed") == 0) {
                confirmed = 1;
                UpdateRoomStatus(x[i].room);

                for (int j = i; j < total_customers - 1; j++) {
                    x[j] = x[j + 1];
                }
                total_customers--;
                printf("Reservation canceled successfully.\n");
            } else {
                printf("Reservation cannot be canceled as it is already confirmed.\n");
            }
            break;}}}

    if (!found) {
        printf("room not found.\n");
        return;
    }
    if (found && confirmed) {
        printf("Do you want to save? (\033[0;32mY\033[0;37m/\033[0;31mN\033[0;37m): ");
        scanf("%c",&q);

        while (q != 'y' && q != 'Y' && q != 'n' && q != 'N') {
            printf("Please enter a valid character (Y/N): ");
            scanf("%c",&q);
        }
        save = q;
        if (save == 'y' || save == 'Y') {
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
            printf("Changes saved successfully.\n");
        } else {
            printf("Changes not saved.\n");
        }
    }
}