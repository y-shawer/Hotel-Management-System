#include "TrackingRoomsAvailability.h"
void trackRoom(){

    loadRoom();
    int i,r;
    printf("enter the room number:");
    scanf(" %d",&r);
    getchar();
    for(i=0;i<total_rooms;i++){
            if(r==y[i].room_num){
        printf(" the room status is %s\n", y[i].status);
        printf(" the category is %s\n", y[i].category);
        printf(" the price is %d\n", y[i].price);
        return;}

    }
    printf("invalid room number ");
}
