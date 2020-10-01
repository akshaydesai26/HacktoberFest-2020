#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *nxt, *prev;
};

struct node* head = NULL;

void insert_beg()
{
	int data;
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the value: \n");
	scanf("%d", &data);
	newNode->data = data;
	newNode->nxt = head;
	newNode->prev = NULL;
	if(head!=NULL)
	head->prev = newNode;
	head = newNode; 
}

void insert_end()
{
	int data;
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data: ");
	scanf("%d", &data);
	newNode->data = data;
	newNode->nxt = NULL;
	newNode->prev = head;
	struct node* temp = head;
	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		while(temp->nxt != NULL)
			temp = temp->nxt;
		newNode->prev = temp;
		temp->nxt = newNode;
	}
}

void insert_after()
{
	int val, data;
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the value after which you want to add: ");
	scanf("%d", &val);
	printf("Enter the value: ");
	scanf("%d", &data);
	newNode->data = data;
	newNode->prev = NULL;
	newNode->nxt = NULL;
	struct node* temp = head;
	while(temp->data!= val)
		temp = temp->nxt;
	temp->nxt->prev = newNode;
	newNode->nxt = temp->nxt;
	temp->nxt = newNode;
	newNode->prev = temp; 
	
}

void insert_before()
{
	int val, data;
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the value after which you want to add: ");
	scanf("%d", &val);
	printf("Enter the value: ");
	scanf("%d", &data);
	newNode->data = data;
	newNode->prev = NULL;
	newNode->nxt = NULL;
	struct node* temp1 = head; 
	struct node* temp2;
	while(temp1->data != val)
	{
		temp2 = temp1;
		temp1 = temp1->nxt;
	}
	temp2->nxt = newNode;
	newNode->prev = temp2;
	temp1->prev = newNode;
	newNode->nxt = temp1;
}
void delete_beg()
{
	struct node* temp = head;
	if(head == NULL)
	{
		printf("\nList is empty!!\n");
	}
	else
	{
		head = temp->nxt;
		head->prev = NULL;
		free(temp);
	}
}

void delete_end()
{
	struct node* temp1 = head;
	struct node* temp2;
	if(head == NULL)
	printf("\nList is empty!!!\n");
	else if(head->nxt == NULL)
	{
		head = NULL;
		free(temp1);
	}
	else
	{
		while(temp1->nxt!=NULL)
		{
			temp2 = temp1;
			temp1 = temp1->nxt;
		}
		temp2->nxt = temp1->nxt;
		free(temp1);
	}
}

void delete_after()
{
	int val;
	struct node* temp1 = head;
	struct node* temp2;
	printf("Enter the node after which you want to delete: ");
	scanf("%d", &val);
	if(head == NULL)
		printf("List is empty!!!");
	else
	{	
		while(temp1->data != val)
			temp1 = temp1->nxt;
		if(temp1->nxt == NULL)
			printf("\nNo nodes after the node you entered!!!\n");
		else
		{
			temp2 = temp1->nxt;
			if(temp2->nxt == NULL)
			{
				temp1->nxt = NULL;
				free(temp2);
			}
			else
			{
				temp1->nxt = temp2->nxt;
				temp2->nxt->prev = temp1;
				free(temp2);
			}
		}
	}
}

void delete_node()
{
	int val;
	struct node* temp = head;
	printf("Enter the node you want to delete: ");
	scanf("%d", &val);
	if(head == NULL)
	printf("List is empty!!!\n");
	else if(temp->data == val)
	{
		head = temp->nxt;
		temp->nxt->prev = NULL;
		free(temp);
	}
	else
	{
		while(temp->data != val)
		{
			temp = temp->nxt;
		}
		if(temp->nxt == NULL && temp->prev == NULL)
		{
			temp = NULL;
			free(temp);
		}
		if(temp->nxt == NULL)
		{
			temp->prev->nxt = temp->nxt;
			free(temp);
		}
		else
		{
		temp->prev->nxt = temp->nxt;
		temp->nxt->prev = temp->prev;
		free(temp);
		}
	}
}
void delete_before()
{
	int val;
	struct node* temp1 = head;
	struct node* temp2;
	printf("Enter the node before you want to delete: ");
	scanf("%d", &val);
	if(head == NULL)
		printf("List is empty!!");
	else
	{
		while(temp1->data != val)
		{
			temp2 = temp1;
			temp1 = temp1->nxt;
		}
		if(temp1->nxt == NULL)
			printf("\nNO nodes before the node you entered!!\n");
		else if(temp2->prev == NULL)
		{
			head = temp1;
			free(temp2);
		}
		else
		{
		temp2->prev->nxt = temp1;
		temp1->prev = temp2->prev;
		free(temp2);
		}
	}
}
void display()
{
	struct node* temp = head;
	if(temp == NULL)
	{
		printf("\nList is empty!!!\n");
	}
	else
	{
		printf("List: \n");
		do
		{
			printf("%p %p| %d | %p\n", temp, temp->prev, temp->data, temp->nxt);
			temp = temp->nxt;
		}while(temp!=NULL);
	}
}

int main()
{
	int n;
	do
	{
		printf("\n0.EXIT");
		printf("\n1.INSERT AT BEGINING");
		printf("\n2.DELETE AT BEGINING");
		printf("\n3.INSERT AT END");
		printf("\n4.DELETE AT END");
		printf("\n5.INSERT AFTER NODE");
		printf("\n6.INSERT BEFORE NODE");
		printf("\n7.DELETE AFTER NODE");
		printf("\n8.DELETE BEFORE NODE");
		printf("\nEnter your choice: ");
		scanf("%d", &n);
		switch(n)
		{
			case 1:
				insert_beg();
				display();
				break;
			case 2:
				delete_beg();
				display();
				break;
			case 3:
				insert_end();
				display();
				break;
			case 4:
				delete_end();
				display();
				break;
			case 5:
				insert_after();
				display();
				break;
			case 6:
				insert_before();
				display();
				break;
			case 7:
				delete_after();
				display();
				break;
			case 8:
				delete_before();
				display();
				break;
			case 9:
				delete_node();
				display();
				break;
		}
	}while(n!=0);
	return 0;
}
