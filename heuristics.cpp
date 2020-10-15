
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "route_functions.h"
#include "util.h"


route greed ( double **dmatrix, int dim, city *cities )
{
	route r;
	create_route ( &r );
	insert_city( &r, cities[0].id, cities[0].x, cities[0].y );
	cities[0].id = -1;

	double shortest_distance;
	int closest_city = 0;
	int current_city = 0;

	//constructing the route adding city by city, based on the closest city
	int k = 0;
	while ( k < dim-1 ){
		shortest_distance = 10000.0;
		for ( int i = 0 ; i < dim ; i++ ){
			if ( cities[i].id == -1 )
				continue;

			if ( dmatrix[current_city][i] < shortest_distance ){
				shortest_distance = dmatrix[current_city][i];
				closest_city = i;
			}
		}
		insert_city ( &r, cities[closest_city].id, cities[closest_city].x, cities[closest_city].y );
		cities[closest_city].id = -1;
		current_city = closest_city;
		k++;
	}

	return r;
}


