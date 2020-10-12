
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "util.h"
#include "heuristics.h"
#include "types.h"
#include "local_search.h"
#include "route_functions.h"

int main ( int argc, char **argv )
{
	srand ( time(NULL) );

	int dim;
	double total_cost;
	
	city *cities = read_input_file ( argv[1], &dim );

	double **dmatrix = distance_matrix ( dim, cities );

	route r = greed ( dmatrix, dim, &total_cost, cities );
	
	//printf ( "Total Cost: %.2lf\n", total_cost );
	//print_route ( r );
	
	vnd ( &r, dim, &total_cost );

	return 0;
}

