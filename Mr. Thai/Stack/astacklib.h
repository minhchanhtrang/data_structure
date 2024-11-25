/* satck cai dat bang mang */

#include <stdio.h>

#ifndef MaxLength
	#define MaxLength 500
#endif
#ifndef ElementType
	typedef int ElementType;  // define type of elements
#endif

typedef struct {
	ElementType Elements[MaxLength];  //store elements of list
	int  Top_idx; //store the top of stack
} Stack;

void makeNullStack(Stack *S){
	  		S->Top_idx=MaxLength;
} 

int emptyStack(Stack S){ 
			return S.Top_idx==MaxLength; 
}

int fullStack(Stack S){	
		return S.Top_idx==0;
}

// Return the value of the top element = Retrieve(First(S),S)
ElementType top(Stack S){
	if (!emptyStack(S))
		return S.Elements[S.Top_idx];
	else printf("Loi! Ngan xep rong");
} 

// Delete the top element   = Delete_List(First(S),S)
void pop(Stack *S)
{
	if (!emptyStack(*S))
		S->Top_idx=S->Top_idx+1;
	else printf("Loi! Ngan xep rong!");
}

// Add value x to the top = Insert_List(x,First(S),S)
void push(ElementType X, Stack *S){
	if (fullStack(*S))
		printf("Loi! Ngan xep day!");
	else{
		S->Top_idx=S->Top_idx-1;
		S->Elements[S->Top_idx]=X;
	}
}

void printStack(Stack S){
	while (!emptyStack(S)){
		printf("%d ",top(S));
		pop(&S);
	}
	printf("\n");	
}


