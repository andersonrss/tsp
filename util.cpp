
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "types.h"


//read data like coordenates and num. of cities from file
city * read_input_file ( char *fileName, int *dim )
{
	FILE *input;
	input = fopen( fileName, "r" );
	
	fscanf ( input, "%d", dim );
	
	city *cities = ( city* ) malloc ( *dim * sizeof ( city ) ); 
	
	for ( int i = 0 ; i < *dim ; i++ ){
		fscanf ( input, "%d %d %d", &cities[i].id, &cities[i].x, &cities[i].y );
	}
	
	return cities;
}

//Calculate the euclidean distance between two points
double euclidean_distance ( int x0, int x1, int y0, int y1 )
{
	return sqrt ( ( ( x1 - x0 ) * ( x1 - x0 ) ) + ( ( y1 - y0 ) * ( y1 - y0 ) ) );
}

//fill the distance matrix
double ** distance_matrix( int dim, city *cities )
{
	double **dmatrix = ( double** ) malloc ( dim * sizeof ( double* ) );
	
	for ( int i = 0 ; i < dim ; i++ )
		dmatrix[i] = ( double* ) malloc ( dim * sizeof ( double ) );

	for ( int i = 0 ; i < dim ; i++ ){
		for ( int j = 0 ; j < dim ; j++ ){
			if ( i == j )
				dmatrix[i][j] = 0;

			dmatrix[i][j] = euclidean_distance ( cities[i].x, cities[j].x, cities[i].y, cities[j].y );
		}
	}
	
	return dmatrix;
}

//copy a vector
void vector_copier ( int *to_copy, int *result, int size )
{
	for ( int i = 0 ; i < size ; i++ ){
		result[i] = to_copy[i];
	}
}

