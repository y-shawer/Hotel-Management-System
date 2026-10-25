#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UpdateRoomStatus.h"


void UpdateRoomStatus(int id){

     loadRoom();


    for (int i = 0; i < total_rooms; i++) {
        if (y[i].room_num == id) {
                if(strcmp(y[i].status,"Available")==0){
                     strcpy(y[i].status, "Reserved");
                }
                else if(strcmp(y[i].status,"Reserved")==0){
                    strcpy(y[i].status,"Available");
                }

                break;
        }
    }
        FILE *f = fopen("Room.txt", "w");
    if (f == NULL) {
        printf("Error in opening file\n");
        exit(1);
    }

     for (int j = 0; j < total_rooms; j++) {
        fprintf(f, "%d %s %s %d\n",
                y[j].room_num, y[j].status, y[j].category, y[j].price);
    }
    fclose(f);
}
