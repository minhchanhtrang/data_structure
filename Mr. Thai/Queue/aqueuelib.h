/* cai dat hang doi bang mang tinh tien */

#include <stdio.h>
#include <conio.h>


#ifndef MaxLength
	#define MaxLength 500
#endif
#ifndef ElementType
	typedef int ElementType;  // define type of elements
#endif

typedef struct {
	ElementType Elements[MaxLength];  //store elements of queue
	int Front, Rear;  //index of front and rear of queue 
} Queue;

// initialization of queue
void makeNullQueue(Queue *pQ)
	{
		pQ->Front=-1;
		pQ->Rear=-1;
 	 } 
// Check queue ? empty or not
int emptyQueue(Queue Q)
{	
		return (Q.Front ==-1);
}	

// check queue is full or not
int fullQueue(Queue Q)
{	 
	return ((Q.Rear-Q.Front+1)==MaxLength);
} 

// return the first element of queue
ElementType front(Queue Q){
 	if (emptyQueue (Q))       
	 	printf ("Hang rong");
    else  
       return Q.Elements[Q.Front];
} 

// delete the first element of queue
void deQueue(Queue *pQ){	
	if (!emptyQueue(*pQ)){	
		pQ->Front=pQ->Front+1;
	   	if (pQ->Front>pQ->Rear)              				
		   makeNullQueue(pQ); //Dat lai hang rong
	}else printf("Loi: Hang rong!");
} 

// add value x to queue
void enQueue(ElementType X,Queue *pQ)
{	if (!fullQueue(*pQ)){ 
		if (emptyQueue(*pQ)) pQ->Front=0;
	  	if (pQ->Rear==MaxLength-1){
		  	//Di chuyen tinh tien ra truoc Front -1 vi tri
		  	int i;
		  	for(i=pQ->Front;i<=pQ->Rear;i++)
			 	pQ->Elements[i-pQ->Front]=pQ->Elements[i];
			 //Xac dinh vi tri Rear moi
		 	pQ->Rear=MaxLength - pQ->Front-1;
		  	pQ->Front=0;
		 }
		//Tang Rear de luu noi dung moi
		pQ->Rear=pQ->Rear+1;
		pQ->Elements[pQ->Rear]=X;
	}
	else printf("Loi: Hang day!");
} 

void printQueue(Queue Q){
	while (!emptyQueue(Q)){
		printf("%d ", front(Q));
		deQueue(&Q);
	}
	printf("\n");
}

