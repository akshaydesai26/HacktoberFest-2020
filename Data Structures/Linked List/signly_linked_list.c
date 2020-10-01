#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* nxt;
};
struct node* head = NULL;
void insert_beg()
{
		int val;
		printf("\nEnter the value: ");
		scanf("%d", &val);
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp->data = val;
		temp->nxt = head;
		head = temp;
}

void insert_end()
{
    int data;
    printf("\nEnter the number: ");
    scanf("%d", &data);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->nxt = NULL;
    struct node* temp = head;
    if(head==NULL)
        head = newNode;
    else
    {
        while(temp->nxt!=NULL)
            temp = temp->nxt;
        temp->nxt = newNode;
    }
}

void insert_before()
{
	int val, data;
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the value before which you want to add node: \n");
    scanf("%d", &val);
    printf("Enter the data: \n");
    scanf("%d", &data);
    newNode->data = data;
    newNode->nxt = NULL;
	struct node* temp1 = head;
	struct node* temp2;
    if(head == NULL)
        printf("List is empty!!!\n");
    else if(val == head->data)
    {
        newNode->nxt = head;
        head = newNode;
    }
    else
    {
    	while(temp1->data != val)
    	{
    		temp2 = temp1;
    		temp1 = temp1->nxt;
    	}
    	temp2->nxt = newNode;
    	newNode->nxt = temp1;    
    }
}

void insert_after()
{
    int data, val;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value before which you want to add node: \n");
    scanf("%d", &val);
    printf("Enter the data: \n");
    scanf("%d", &data);
    newNode->data = data;
    newNode->nxt = NULL;
    struct node* temp1 = head;
    struct node* temp2;
    if(head == NULL)
        printf("List is empty!!!\n");
    else
    {
        while(temp2->data != val)
        {
            temp2 = temp1;
            temp1 = temp1->nxt;
        }
        temp2->nxt = newNode;
        newNode->nxt = temp1;
    }
}
void Delete_beg()
{
    struct node* temp = head;
    if(head == NULL)
        printf("List is empty!!!\n");
    // else if(head->nxt == NULL)
    // {
    //     head = NULL;
    //     free(head);
    // }
    else
   {
       temp = head;
       head = temp->nxt;
       free(temp);
   }
}

void Delete_end()
{
    struct node* temp = head;
    struct node* temp1;
    if(head == NULL)
        printf("List is empty!!!\n");
    // else if(head->nxt == NULL)
    // {
    //     head = NULL;
    //     free(head);
    // }
    else
    {
	    while(temp->nxt!=NULL)
	    {
	       temp1 = temp;
	       temp = temp->nxt;
	    }
	    temp1->nxt = temp->nxt;
	    free(temp);
	}
}

void Delete_after()
{
	int val;
	struct node* temp1 = head;
	struct node* temp2;
	printf("Enter the value after which you want to delete: \n");
	scanf("%d", &val);
	while(temp2->data != val)
	{
		temp2 = temp1;
		temp1 = temp1->nxt;
	}
	temp2->nxt = temp1->nxt;
	free(temp1);
}

void Delete_before()
{
    int val;
    struct node* temp1 = head;
    struct node* temp2;
    printf("Enter the value after which you want to delete: \n");
    scanf("%d", &val);
    while(temp1->data != val)
    {
        temp2 = temp1;
        temp1 = temp1->nxt;
    }
    temp2->nxt = temp1->nxt;
    free(temp1);
}
void delete_node()
{
	int val;
	struct node* temp1 = head;
	struct node* temp2;
	printf("Enter the node: \n");
	scanf("%d", &val);
	while(temp1->data != val)
	{
		temp2 = temp1;
		temp1 = temp1->nxt;
	}
	temp2->nxt = temp1->nxt;
	free(temp1);
}

void display()
{
    struct node* temp = head;
    if(head)
    {
    printf("\n\t\t\t   Curr. Adress |Data| Next Adress\n");
    do{
    printf("\t\t\t\t%p | %d | %p", temp, temp->data, temp->nxt);
    temp = temp->nxt;
    printf("\n"); 
    }while(temp!=NULL);
}
}
void main()
{
	int a, m;
	do{
		printf("\n\t\t---------------------------------------------------");
        printf("\n\t\t\t\t     LINKED LIST");
        printf("\n\t\t---------------------------------------------------");
        printf("\n\t\t\t\t0.EXIT");
        printf("\n\t\t\t\t1.INSERT");
        printf("\n\t\t\t\t2.DELETE");
        printf("\n\n\t\tEnter your choice: ");
		scanf("%d", &m);
		switch(m){
			case 1:
				do{
                    printf("\n---------------------------------------------------");
                    printf("\n\t\t    INSERT MENU  ");
                    printf("\n---------------------------------------------------");
                    printf("\n1.INSERT AT BEGINING");
                    printf("\n2.INSERT AT END");
                    printf("\n3.INSERT BEFORE NODE");
                     printf("\n3.INSERT AFTER NODE");
                    printf("\n0.GO TO PREVIOUS MENU");
                    printf("\n\nEnter your choice: ");
                    scanf("%d", &a);
                    switch(a)
                    {
                    case 1:
                        insert_beg();
                        display();
                        break;
                    case 2:
                     insert_end();
                      display();
                        break;
                    case 3:
                    	insert_before();
                    	display();
                    	break;
                    case 4:
                        insert_after();
                        display();
                        break;
                    }
                }while(a!=0);
                   display();
                   break;
             case 2:
             	do{
                    printf("\n---------------------------------------------------");
                    printf("\n\t\t    DELETE MENU  ");
                    printf("\n---------------------------------------------------");
                    printf("\n1.DELETE AT BEGINING");
                    printf("\n2.DELETE AT END");
                    printf("\n3.DELETE AFTER NODE");
                    printf("\n4.DELETE BEFORE NODE");
                    printf("\n5.DELETE ANY NODE");
                    printf("\n0.GO TO PREVIOUS MENU");
                    printf("\n\nEnter your choice: ");
                    scanf("%d", &a);
                    switch(a)
                    {
                    	case 1:
                    		Delete_beg();
                    		display();
                    		break;
                    	case 2:
                    		Delete_end();
                    		display();
                    		break;
                    	case 3:
                    		Delete_after();
                    		display();
                    		break;
                    	case 5:
                    		delete_node();
                    		display();
                    		break;
                    }
                 }while(a!=0);
                 display();
                 break;
		}
	}while(m!=0);
}
