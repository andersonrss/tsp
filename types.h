
#ifndef TYPES_H
#define TYPES_H


typedef struct node{
	int id;
	int x;
	int y;
	struct node *previous;
	struct node *next;
}city, *route;


#endif
