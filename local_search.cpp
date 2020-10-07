
#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "util.h"

/******************** Heurístic Rules ********************

1. First, the affiliation of the chosen node changes
2. The chosen node's father becomes father of his previous son
3. The previous father of his new son becomes his father

**********************************************************/

void vnd ( int *route, int dim, double *total_cost  )
{
	int chosen_father = 0;
	int chosen_son = 0;
	
	
} 
