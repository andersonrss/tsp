
#ifndef ROUTE_FUNCTIONS_H
#define ROUTE_FUNCTIONS_H


#include "types.h"

extern void create_route ( route *r );
extern int empty_route ( route r );
extern int route_length ( route r );
extern void print_route ( route r );
extern void insert_city ( route *r, int id, int x, int y );
extern void remove_city ( route *r, const int id );


#endif
