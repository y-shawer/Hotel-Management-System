#ifndef LOAD_H_INCLUDED
#define LOAD_H_INCLUDED

#define USERS 100
#define Rooms 100
#include "load.c"



customer x[USERS];
int total_customers;

void load();
void load_room();
#endif // LOAD_H_INCLUDED
