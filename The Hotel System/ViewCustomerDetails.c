#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ViewCustomerDetails.h"


void view_customer_by_id_or_room() {
    load();
    int choice, id, room;
    printf("View Customer Details\n");
    printf("1. Search by Reservation ID\n");
    printf("2. Search by Room Number\n");
    printf("Enter your choice (1 or 2): ");
    scanf(" %d", &choice);

    if (choice == 1) {
        printf("Enter Reservation ID: ");
        scanf(" %d", &id);
        getchar();
        for (int i = 0; i < total_customers; i++) {
            if (x[i].id == id) {
                printf("Customer Details:\n");
                printf("Name: %s\n", x[i].name);
                printf("Contact Number: %s", x[i].number);
                printf("Email: %s\n", x[i].email);
                printf("Status: %s\n", x[i].status);
                printf("Room Number: %d\n", x[i].room);
                printf("Nights: %d\n", x[i].nights);
                printf("Reservation Date: %s\n", x[i].date);
                return;
            }
        }
        printf("No customer found with Reservation ID %d\n", id);
    } else if (choice == 2) {
        printf("Enter Room Number: ");
        scanf(" %d", &room);
        getchar();
        for (int i = 0; i < total_customers; i++) {
            if (x[i].room == room) {
                printf("Customer Details:\n");
                printf("Name: %s\n", x[i].name);
                printf("Contact Number: %s\n", x[i].number);
                printf("Email: %s\n", x[i].email);
                printf("Status: %s\n", x[i].status);
                printf("Reservation ID: %d\n", x[i].id);
                printf("Nights: %d\n", x[i].nights);
                printf("Reservation Date: %s\n", x[i].date);
                return;
            }
        }
        printf("No customer found with Room Number %d\n", room);
    } else {
        printf("Invalid choice!\n");
    }
}
