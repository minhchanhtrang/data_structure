/* cai dat thu vien bang mang */

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef int Position;
typedef int ElementType;
typedef struct{
  ElementType Elements[MAXSIZE];
  Position size;
}List;
List L;
/*
Initialize an empty list
*/
void makeNull(List *L){
	L->size=0;
}

/*
return Number of Elements
*/
int len(List L){
	return L.size;
}

/*
Check whether the list is empty?
*/
int empty(List L){
	return (L.size==0);
}

/*
Check whether the list is full?
*/
int fullList(List L){
	return (L.size==MAXSIZE);
	
}

/*
Traverse the list to print out all Elements
*/
void print(List L){
	Position i;
	for(i=1; i<=L.size;++i) printf("%d ", L.Elements[i-1]);
	printf("\n");
}

/*
Return the element at position p
*/
ElementType getAt(Position p, List L){
	if(p>=1 && p<=L.size)
		return L.Elements[p-1];
	else{ 
		printf("getAt(): Position Error at %d! Exit....\n", p);
		exit(EXIT_FAILURE);
	}
}

/*
Return the first position in L
*/
Position first(List L){
		return 1;
}

/*
Return the end position in L
*/
Position endList(List L){
	return L.size+1;
}

/*
Update the element at position p by a new value
*/
void setAt(Position p, ElementType x,List *L){
	if(p>=1 && p<=L->size)
		 L->Elements[p-1]=x;
	else{ 
		printf("setAt(): Position Error! Exit....\n");
		exit(EXIT_FAILURE);
	}	
}

/*
Insert x at position p
*/
void insertAt(Position p, ElementType x, List *L){
	if (fullList(*L))   //(L->Last==MaxLength)
		printf("List is full");
	else if ((p<first(*L)) || (p>endList(*L))) 
		printf("insertAt(): The position %d is illegal", p);
	else{
		Position q;	
		for(q=endList(*L);q>p-1;q--)
			L->Elements[q]=L->Elements[q-1];	
		L->Elements[p-1]=x;
		L->size++;
	}	
}
/*
Remove and return the element at position p
*/
ElementType popAt(Position p, List *L){
	ElementType x;
	if(p>=1 && p<=L->size){
		x= L->Elements[p-1];
		Position q;	
		for(q=p;q<endList(*L);q++)
			L->Elements[q-1]=L->Elements[q];	
		L->size--;
		return x;
	}
	else{ 
		printf("Position Error! Exit....\n");
		exit(EXIT_FAILURE);
	}	
	
	
}

/*
Insert x to the first position
*/
void insertFirst(ElementType x, List *L){
	insertAt(1, x, L);
}

/*
Remove and return the first element
*/
ElementType popFirst(List *L){
	return popAt(first(*L), L);
	
}
/*
Append a new element to the list
*/
void append(ElementType x,List *L){
	if(fullList(*L)){
		printf("List is full! Exit....\n");
		exit(EXIT_FAILURE);
	}else {
		L->Elements[L->size]=x;
		L->size++;
	}

}

/*
Remove and return the last element
*/
ElementType popLast(List *L){
	return popAt(endList(*L), L);
}

/*
Return the position of the first appearance of x in the list
*/
Position locate(ElementType x, List L){
	Position p;
	int found=0;
	for(p=first(L);p<endList(L) && !found;p++)
			if (L.Elements[p-1]==x) found=1;
		return p;
}

/*
Return the next position of p in L
*/
Position next(Position p,List L){
	if(p>=1 && p<=L.size){
		return p+1;
	}
	else{ 
		printf("Position Error! Exit....\n");
		exit(EXIT_FAILURE);
	}	
	
}

/*
Return the previous position of p in L
*/
Position previous(Position p,List L){
	if(p>=1 && p<=L.size){
		return p-1;
	}
	else{ 
		printf("Position Error! Exit....\n");
		exit(EXIT_FAILURE);
	}	
}
