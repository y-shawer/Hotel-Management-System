#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "check_in.h"
#include "Reservation.h"
#include "check_out.h"
#include "Report.h"
#include "edit.h"
#include "cancel.h"
#include "search.h"
#include "TrackingRoomsAvailability.h"
#include "ViewCustomerDetails.h"
#include "valid_login.h"
#include "sort.h"





int main() {



    printf("\033[1;36mWelcome to the Hotel Management System\n\033[0m");

      system("pause");


      system("cls");


    char s[50];
    char m = '0', n = '0';
    printf("1. Login\n2. Exit\n");
    fgets(s, sizeof(s), stdin);
    while (strlen(s) != 2 || (s[0] != '1' && s[0] != '2')) {
        printf("Please enter a valid number!\n");
        fgets(s, sizeof(s), stdin);
    }
    m = s[0];

    if (m == '2') {
        exit(0);
    }

    while(valid_login()==0){
    }
    getchar();

    system("cls");

    while (m != '0') {

        system("cls");
        printf("\033[0;36m");
        printf("1. Reserve\n2. Check in\n3. Cancel reservation.\n4. Check out.\n");
        printf("5. Check room availability.\n6. View customer details.\n7. Edit reservation.\n");
        printf("8. Search.\n9. Report.\n0. Exit\n");
        printf("\033[0;37m");

        fgets(s, sizeof(s), stdin);
        while (strlen(s) != 2 || strchr("0123456789", s[0]) == NULL) {
            printf("Please enter a valid number!\n");
            fgets(s, sizeof(s), stdin);
        }
        m = s[0];
        system("cls");

        switch (m) {
            case '1':
                reserveRoom(0);
                break;
            case '2':
                checkIn();
                break;
            case '3':
                CancelReservation();
                break;
            case '4':
                checkOut();
                break;
            case '5':
                trackRoom();
                break;
            case '6':
                view_customer_by_id_or_room();
                break;
            case '7':
                EditReservation();
                break;
            case '8':
                search();
                break;
            case '9':
                report();
                break;
            case '0':
                sorting();
                exit(0);
                break;
            default:
                printf("Please enter a valid number!\n");
                break;
        }


        printf("Would you like to:\n1. Exit.\n2. Go back to the menu.\n");
        fgets(s, sizeof(s), stdin);
        while (strlen(s) != 2 || (s[0] != '1' && s[0] != '2')) {
            printf("Please enter a valid number!\n");
            fgets(s, sizeof(s), stdin);
        }
        n = s[0];
        if (n == '1') {
            exit(0);
        }
    }

    return 0;
}
