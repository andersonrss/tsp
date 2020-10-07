
#include <stdio.h>
#include <stdlib.h>

#include "route_functions.h"


void create_route ( route *r )
{
     *r = NULL;
}

int empty_route ( route r )
{
    return !r;
}

int route_length ( route r )
{
    int size = 0;

	while ( r ){
		size++;
		r = r->next;
	}

    return size;
}

void print_route ( route r )
{
	printf ( "Route: " );
	while ( r ){
		printf ( "%d ", r->id);
		r = r->next;
	}
	
	printf ( "\n" );
}

void insert_city ( route *r, int id, int x, int y )
{
	route new_city;

	new_city = ( route ) malloc ( sizeof(city) );

	new_city->id = id;
	new_city->x  = x;
	new_city->y  = y;

	if ( empty_route(*r) ) {
		*r = new_city; 
		(*r)->next = NULL; 
		return; 
	}

	route aux = *r;

	while ( aux->next )
		aux = aux->next;
	
	aux->next = new_city;
	new_city->next = NULL;

	//insert at beginning
		//new_city->next = *r; 
		//*r = new_city; 
}

void remove_city ( route *r, const int id )
{
	route current = *r;
	route previous = NULL;
          
	while ( current && current->id != id ){                               
		previous = current;
		current = current->next;
	}
          
	if(!current)
		printf("Coudn't find element or empty list");

	if(!previous)
		(*r) = current->next;
	else
		previous->next = current->next;

	free( current );
}
     
     
