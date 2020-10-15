
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
	double total_cost = 0.0;
	
	city *cities = read_input_file ( argv[1], &dim );

	double **dmatrix = distance_matrix ( dim, cities );

	route r = greed ( dmatrix, dim, cities );
	
	total_cost = route_total_cost ( r, dmatrix );
	
	//printf("%lf\n", total_cost);
	
	int n = 3;
	vnd ( &r, dim, &total_cost, dmatrix, n );

	return 0;
}

