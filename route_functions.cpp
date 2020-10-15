
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

	route rAux = r;
	while ( rAux ){
		size++;
		rAux = rAux->next;
		if ( rAux == r )
			break;
	}

    return size;
}

void print_route ( route r )
{
	printf ( "Route: " );
	
	route rAux = r;
	while ( rAux ){
		printf ( "%d -> ", rAux->id );
		rAux = rAux->next;
		if ( rAux == r ){
			printf ( "%d", rAux->id );
			break;
		}
	}
	
	printf ( "\n" );
}

double route_total_cost ( route r, double **dmatrix )
{
	if ( empty_route(r) || route_length(r) == 1 ){
		printf("Route is empty or contains one element only. Aborting...\n");
		exit(0);
	}
	
	route aux = r;
	double total_cost = 0.0;
	
	while ( aux->next ){
		total_cost = dmatrix[aux->id-1][aux->next->id-1] + total_cost;
		aux = aux->next;
		if ( aux == r )
			break;
	}
	
	return total_cost;
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
		(*r)->previous = NULL;
		return; 
	}

	route aux = *r;

	while ( aux->next ){
		if ( aux->next == *r )
			break;
		aux = aux->next;
	}

	aux->next = new_city;
	new_city->next = *r;
	new_city->previous = aux;
	(*r)->previous = new_city;

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
     
     
