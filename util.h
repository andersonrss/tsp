
#ifndef UTIL_H
#define UTIL_H


#include "types.h"


extern city * read_input_file ( char *fileName, int *dim );
extern double euclidean_distance ( int x0, int x1, int y0, int y1 );
extern double ** distance_matrix ( int dim, city *cities );
extern void vector_copier ( int *to_copy, int *result, int size );


#endif
