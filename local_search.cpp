
#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "util.h"
#include "route_functions.h"

/******************** Heurístic Rules ********************

1. First, the affiliation of the chosen node changes
2. The chosen node's father becomes father of his previous son
3. The previous father of his new son becomes his father

**********************************************************/

void vnd ( route *r, int dim, double *total_cost, double **dmatrix, int n  )
{
	int *knearest = ( int* ) malloc ( n * sizeof ( int ) );

	route aux = *r;
	
	double shortest_distance = 10000.0;
	int nearest_city;
	int contain;

	//iterating over route
	int m;
	while ( aux->next ){
		if ( aux->next == *r )
			break;

		m = 0;

		//searching 'n' nearest cities
		for ( int i = 0 ; i < n ; i++ ){
			shortest_distance = 10000.0;
			
			//searching the nearest city
			for ( int j = 0 ; j < dim ; j++ ){
				if ( j == aux->id-1 )
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

				if ( dmatrix[aux->id-1][j] < shortest_distance ){
					shortest_distance = dmatrix[aux->id-1][j];
					nearest_city = j;
				}
			}
			
			knearest[m] = nearest_city;
			m++;
		}
		
		//until here, the code is functional
		for ( int i = 0 ; i < n ; i++ ){
			printf("%d ", knearest[i]);
		}
		exit(0);
		aux = aux->next;
	}
}
