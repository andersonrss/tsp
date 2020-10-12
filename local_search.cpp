
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

void vnd ( route *r, int dim, double *total_cost  )
{
	route nCurrent = *r;
} 
