
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "route_functions.h"
#include "util.h"


int * greed ( double **dmatrix, int dim, double *final_route_total_cost )
{
	//control the route that cost less
	double best_route_cost = 100000.0;
	
	//used to identify cities that have already been visited
	int *inserted_cities = (int*) malloc ( dim * sizeof (int) );
	
	//final vector that will store the best route found
	int *best_route = (int*) malloc (dim * sizeof (int) );
	memset ( best_route, -1, dim * sizeof (int) );
	
	//testing which city is the best to begin a route 
	for ( int start_city = 0 ; start_city < dim ; start_city++ ){
		memset ( inserted_cities, -1, dim * sizeof (int) );

		double shortest_distance;
		int closest_city;
		double route_total_cost = 0.0;

		int current_city = start_city;
		int k = 0;
		while ( k < dim ){
			if ( k == (dim-1) )
				break;
				
			shortest_distance = 10000.0;
			for ( int i = 0 ; i < dim ; i++ ){
				if ( current_city == i )
					continue;

				if ( inserted_cities[i] != -1 )
					continue;

				if ( dmatrix[current_city][i] < shortest_distance ){
					shortest_distance = dmatrix[current_city][i];
					closest_city = i;
				}
			}
			
			inserted_cities[current_city] = closest_city;
			route_total_cost = route_total_cost + shortest_distance;
			current_city = closest_city;
			k++;
		}

		if ( route_total_cost < best_route_cost ){
			best_route_cost = route_total_cost;
			vector_copier ( inserted_cities, best_route, dim );
		}
	}
	
	*(final_route_total_cost) = best_route_cost;
	return best_route;
}


