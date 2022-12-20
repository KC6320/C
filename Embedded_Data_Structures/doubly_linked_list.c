/*
	operations for doubly linked list and circular linked list
	Considered 0 indexing for nodes
*/
#include <stdlib.h>
#include <stdio.h>

/* 
	Node defintion
*/ 
struct DNode
{
	struct DNode *prev;
	int value;
	struct DNode *next;
};

/* 
	Func - Create doubly linked list 
	params: 
	 array for node values
	 size of linked list
	return:
	 head pointer/ pointer to first node
*/
struct DNode* create_doubly_linked_list(int array[], int n)
{
	struct DNode *head, *temp, *last;
	head = (struct DNode *)malloc(sizeof(struct DNode));
	head->value=array[0];
	head->prev=NULL;
	head->next=NULL;
	last=head;

	for(int i=1; i<n; i++)
    {
        temp=(struct DNode *)malloc(sizeof(struct DNode));
        temp->value=array[i];
        temp->next=last->next;
        temp->prev=last;
        last->next=temp;
        last=temp;
    }

    return head;
}

/*
	Func - count number of linked list elements
	param-
	 current head pointer
	return
	 total count
*/

int count_elements_doubly_linked_list(struct DNode *head)
{
	int count = 0;
	while (head != 0)
	{
		count++;
		head=head->next;
	}
	return count;
}

/*
	Func - display linked list elements
	param-
	 current head pointer
	return
	 None

*/
void display_doubly_linked_list(struct DNode *head)
{
	struct DNode *tail;
	while( head != NULL)
	{
		printf("%d ",head->value);
		head = head->next;
		if(head && head->next==NULL)
		{
			tail=head;
		}
	}
	printf("\n");
	while(tail)
	{
		printf("%d ",tail->value);
		tail = tail->prev;
	}
	printf("\n");
	printf("\n");
}

/*
	Func - insert new head node with given val
	param-
	 current head pointer
	 new val
	return
	 modified head pointer
*/
struct DNode* insert_head_node_doubly_linked_list(struct DNode* head, int val)
{
	struct DNode* temp = (struct DNode *)malloc(sizeof(struct DNode));
	temp->value = val;
	temp->prev = NULL;
	temp->next = head;
	head->prev = temp;
	head=temp;
	return head;
}

/*
	Func - insert a node with given val at given position
	param-
	 position to be inserted except head i.e except 0
	 val of new node
	 current head pointer
	return
	 None
*/
void insert_node_doubly_linked_list(struct DNode *head, int pos, int val)
{
	if (pos <= 0 || pos > count_elements_doubly_linked_list(head))
		return;

	struct DNode *temp, *temp1;
	temp1 = head;
	temp = (struct DNode *)malloc(sizeof(struct DNode));
	temp->value = val;

	for (int i=0;i < pos-1;i++)
	{
		temp1 = temp1->next;
	}
	temp->next = temp1->next;
	temp->prev = temp1;
	if(temp1->next)
	{
		temp1->next->prev = temp;		
	}
	
	temp1->next=temp;
}

/*
	Func - delete a node at given position
	param-
	 current head pointer
	 position to be deleted
	return
	 None
*/
void delete_node_doubly_linked_list(struct DNode* head, int pos)
{
	struct DNode* temp;
	temp = head;

	// if pos is invalid we need to check using &&
	for ( int i = 0 ; i < pos-1 && temp; i++)
	{
		temp = temp->next;
	}

	// now temp will be pointing on node to be deleted and prev on prev Node
	if(temp)
	{
		temp->prev->next = temp->next;	
	}
	

	// only change link if valid node 
	if (temp->next)
	{	
		temp->next->prev = temp->prev;
	}
	free(temp);
}

/*
	Func - delete head node
	param-
	 current head pointer
	return
	 new head pointer
*/
struct DNode* delete_head_node_doubly_linked_list(struct DNode* head)
{
	if (head)
	{
		struct DNode* temp = head;
		head = head->next;
		free(temp);
		if(head)
		{
			head->prev=NULL;
		}
	}
	return head;
}

/*
	Func - reverse given doubly linked list
	param-
	 current head pointer
	return
	 new head pointer
*/
struct DNode* reverse_doubly_linked_list(struct DNode* head)
{
	struct DNode *temp, *p;
	p=head;

	while(p)
	{
		temp = p->next;
		p->next = p->prev;
		p->prev=temp;
		p=p->prev;   // since link is already changed we need to use prev to go to next node

		// to detect if we reached last node
		if(p && p->next==NULL)
		{
			head=p;
		}
	}
	return head;
}

 /************ Doubly and Circular Linked List *****************/
/*
Circular linked list generally dont have first and last node since
all are in circular fashion. We have ref to any one of node which can
be called as head.
*/

/*
	Func - display doubly circular linked list
	param-
	 current head pointer
	return
	 None
*/
void display_circular_doubly_linked_list(struct DNode *head)
{
    struct DNode *p=head,*tail;
    do
    {
        printf("%d ", p->value);
        if(p->next==head)
        {
        	tail=p;
        }
        p=p->next;
        

    }while(p!=head);
    printf("\n");
}

/*
	Func - create circular linked list
	param-
	 array of values, required length
	return
	 new head pointer
*/
struct DNode* create_circular_doubly_linked_list(int arr[], int n)
{
	struct DNode *head, *last,*t;
    
    head=(struct DNode *)malloc(sizeof(struct DNode));
    head->value=arr[0];
    head->next=head;
    head->prev=head;
    last=head;
    for(int i=1;i<n;i++)
    {
        t=(struct DNode *)malloc(sizeof(struct DNode));
        t->value=arr[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }

    head->prev=last;
    return head;
}

/*
	Func - length of circular doubly linked list
	param-
	 current head pointer
	return
	 length of list
*/
int length_of_circular_doubly_linked_list(struct DNode *head)
{
	struct DNode *p=head;
    int length=0;

    if(!head)
    {
    	return 0;
    }

    do
    {
        length++;
        p=p->next;
    }while(p!=head);

    return length;
}


/*
	Func - insert node after a position. head is considered as 0 index
	param-
	 current head pointer
	 new value
	 positon to be inserted
	return
	 head pointer
*/
struct DNode* insert_node_circular_doubly_linked_list(struct DNode *head, int val, int pos)
{
	if(pos < 0 || pos > length_of_circular_doubly_linked_list(head))
	{
		return head;
	}
	if(pos == 0)
	{
		// insert before current head
		struct DNode *temp, *p;
		temp = (struct DNode *)malloc(sizeof(struct DNode));
		temp->value = val;
		p = head;

		if(head == NULL)
		{
			temp->next=temp->prev=temp;
			head=temp;
		}
		else
		{
			temp->next=head;
			temp->prev=head->prev;
			head->prev=temp;
			temp->prev->next = temp;
		}	
	}
	else
	{
		//insert at some non zero pos similar
		struct DNode *temp, *p;
		p=head;

		for (int i = 0; i < pos-1; i++) p = p->next;

		temp = (struct DNode *)malloc(sizeof(struct DNode));
		temp->value = val;

		temp->next = p->next;
		temp->prev = p;
		if(p->next)p->next->prev = temp;
		p->next = temp;
	}

	return head;
}

/*
	Func - delete head of circular double linked list
	param-
	 current head pointer
	return
	 new head
*/
struct DNode* delete_head_node_circular_doubly_linked_list(struct DNode *head)
{
	struct DNode *temp = head;

	if(temp->next == head)
	{
		// this means only 1 node in current linked list
		free(temp);
		head=NULL;
	}

	head->prev->next=head->next;
	head=head->next;
	head->prev=temp->prev;
	free(temp);
	return head;
}

/*
	Func - delete a node at given position from circular doubly linked list
	param-
	 current head pointer
	 position to be deleted
	return
	 None
*/
void delete_node_circular_doubly_linked_list(struct DNode* head, int pos)
{
	struct DNode* temp;
	temp = head;

	// if pos is invalid we need to check using &&
	for ( int i = 0 ; i < pos-1 && temp; i++)
	{
		temp = temp->next;
	}

	// now temp will be pointing on node to be deleted and prev on prev Node
	if(temp)
	{
		temp->prev->next = temp->next;
	}
	

	// only change link if valid node 
	if (temp->next)
	{	
		temp->next->prev = temp->prev;
	}
	free(temp);
}


int main()
{
	struct DNode *HEAD, *CHEAD;
	int c[] = {11,22,33,44,55,66};
	int l = 6, t;

	HEAD = create_doubly_linked_list(c,l);
	display_doubly_linked_list(HEAD);

	t = count_elements_doubly_linked_list(HEAD);
	printf("%d\n",t);

	HEAD = insert_head_node_doubly_linked_list(HEAD,77);
	display_doubly_linked_list(HEAD);

	insert_node_doubly_linked_list(HEAD, 7 , 88);
	display_doubly_linked_list(HEAD);

	delete_node_doubly_linked_list(HEAD, 8);
	display_doubly_linked_list(HEAD);

	HEAD = delete_head_node_doubly_linked_list(HEAD);
	display_doubly_linked_list(HEAD);

	HEAD = reverse_doubly_linked_list(HEAD);
	display_doubly_linked_list(HEAD);

	CHEAD = create_circular_doubly_linked_list(c,l);
	display_circular_doubly_linked_list(CHEAD);

	t=length_of_circular_doubly_linked_list(CHEAD);
	printf("%d\n", t);

	CHEAD = insert_node_circular_doubly_linked_list(CHEAD, 99, 3);
	display_circular_doubly_linked_list(CHEAD);

	CHEAD = insert_node_circular_doubly_linked_list(CHEAD, 199, 0);
	display_circular_doubly_linked_list(CHEAD);

	CHEAD = delete_head_node_circular_doubly_linked_list(CHEAD);
	display_circular_doubly_linked_list(CHEAD);

	delete_node_circular_doubly_linked_list(CHEAD, 4);
	display_circular_doubly_linked_list(CHEAD);
	return 0;
}