/*
Name: Nabina Khadka
Roll no. 0516
Batch of 2019
WAP to implement linked list
*/
	
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
 	int info;
 	struct node *next;
};
typedef struct node *nodeptr;

nodeptr getnode();
void insertatfirst(nodeptr *, int);
int deletefromfirst(nodeptr *);
void displaylist(nodeptr);
int checkunderflow(nodeptr *);

int main()
{
	nodeptr list;
	list=NULL;
	printf("\nInserted list are:\n");
	insertatfirst(&list,5);
	insertatfirst(&list,6);
	insertatfirst(&list,7);
	insertatfirst(&list,8);
	insertatfirst(&list,9);
	displaylist(list);
	
	printf("\nDeleted list are:\n");
	deletefromfirst(&list);	
	deletefromfirst(&list);
	deletefromfirst(&list);
	displaylist(list);
}

nodeptr getnode(){
	return (nodeptr)malloc(sizeof(struct node));
}

void freenode(nodeptr p){
	free(p);
}

void insertatfirst(nodeptr *p, int x){
	nodeptr q;
	q=getnode();
	q->info=x;
	q->next=*p;
	*p=q;
}

void displaylist(nodeptr p){
	nodeptr ptr=p;
	while(ptr!=NULL){
		printf("%d",ptr->info);
		ptr=ptr->next;
	}
}


int deletefromfirst (nodeptr *p) {
	if (check_underflow(p)) {
		printf ("\n Linked List Underflow \n");
		getch();
		exit(1);
	} else {
		int x;
		nodeptr q;
		q = *p;
		
		*p = q->next;
		x = q->info;
		
		return x;
		
		freenode(q);
	}
}

int check_underflow(nodeptr *p){
	return (*p == NULL);
}



