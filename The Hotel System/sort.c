
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "load.h"
#define USERS 100
#define PASS 50


void sorting() {
    load();
    customer xc[total_customers];
    int d1, d2, m1, m2, y1, y2;
    int pass, i;
    char date1[50], date2[50];
    customer temp;
    FILE *f = fopen("reservations.txt", "w");
    if (f == NULL) {
        printf("error in opening file ");
        exit(1);
    }
    for (i = 0; i < total_customers; i++) {
        xc[i] = x[i];
    }

    for (pass = 1; pass < total_customers; pass++) {
        for (i = 0; i < total_customers - pass; i++) {
            strcpy(date1, xc[i].date);
            strcpy(date2, xc[i + 1].date);

            char *token = strtok(date1, "-");
            d1 = atoi(token);
            token = strtok(NULL, "-");
            m1 = atoi(token);
            token = strtok(NULL, "-");
            y1 = atoi(token);

            token = strtok(date2, "-");
            d2 = atoi(token);
            token = strtok(NULL, "-");
            m2 = atoi(token);
            token = strtok(NULL, "-");
            y2 = atoi(token);

            if (y2 < y1 || (y2 == y1 && m2 < m1) || (y2 == y1 && m2 == m1 && d2 < d1)) {
                temp = xc[i];
                xc[i] = xc[i + 1];
                xc[i + 1] = temp;
            }
        }
    }

    for (i = 0; i < total_customers; i++) {
        fprintf(f,"%d,%d,%s,%s,%s,%d,%s,%s,%s", xc[i].id, xc[i].room, xc[i].status, xc[i].name, xc[i].nid, xc[i].nights, xc[i].date, xc[i].email, xc[i].number);
        if(i==1)
            fprintf(f,"\n");
    }
    fclose(f);
}

