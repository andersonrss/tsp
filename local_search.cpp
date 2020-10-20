
#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "util.h"
#include "route_functions.h"

/*********************** Heurístic Rules ***********************

1. First, the affiliation of the chosen node changes
2. The chosen node's father becomes father of his previous son
3. The previous father of his new son becomes his father

****************************************************************/

void vnd ( route *r, int dim, double *total_cost, double **dmatrix, int n  )
{
	//print_route(*r);

	//k cities nearest to current city
	int *knearest = ( int* ) malloc ( n * sizeof ( int ) );

	route current = *r;
	
	double shortest_distance = 10000.0;
	int nearest_city;
	int contain;

	//iterating over route
	int m;
	while ( current->next ){
		if ( current->next == *r )
			break;

		m = 0;
		//searching 'n' nearest cities
		for ( int i = 0 ; i < n ; i++ ){
			shortest_distance = 10000.0;
			
			//searching the nearest city
			for ( int j = 1 ; j <= dim ; j++ ){
				if ( j == current->id )
					continue;

				//check redundant cities
				for ( int k = 0 ; k < n ; k++ ){
					if ( knearest[k] == j ){
						contain = 1;
						break;
					}
				}
				
				if ( contain == 1 ){
					contain = 0;
					continue;
				}

				if ( dmatrix[current->id-1][j-1] < shortest_distance ){
					shortest_distance = dmatrix[current->id-1][j-1];
					nearest_city = j;
				}
			}
			
			knearest[m] = nearest_city;
			m++;
		}
		
		route target = *r;
		
		while ( target->next ){
			if ( target->next == *r )
				break;

			//TO DO: I have to implement some rule to choose a target
			if ( target->next->id == knearest[0] ){
				target = target->next;	
				continue;
			}

			if ( target->id == knearest[0] ){
				
				//linking current-1 and current+1
				current->previous->next = current->next;
				current->next->previous = current->previous;
				
				//changing current's son
				current->next = target;
				current->previous = target->previous;
				
				//the old father of current's new son, now is his father
				target->previous->next = current;
				target->previous = current;
				
				break;
			}
			
			target = target->next;
		}
		
		//print_route(*r);
		
		//until here, the code is functional
		exit(0);
		current = current->next;
	}
}


