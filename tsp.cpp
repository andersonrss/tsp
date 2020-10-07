
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

	int *route = greed ( dmatrix, dim, &total_cost );

	vnd ( route, dim, &total_cost );

	//printf ( "Total Cost: %.2lf\n", total_cost );
	
	print_route ( route, dim );

	return 0;
}

