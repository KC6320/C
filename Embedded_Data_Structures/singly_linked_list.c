/*
	operations for singly linked list and circular linked list
	Considered 0 indexing for nodes
*/
#include <stdlib.h>
#include <stdio.h>

/* 
	Node defintion
*/ 
struct Node
{
	int value;
	struct Node *next;
};

/* 
	Func - Create singly linked list 
	params: 
	 array for node values
	 size of linked list
	return:
	 head pointer/ pointer to first node
*/
struct Node * create_singly_linked_list(int arr[], int size)
{
	struct Node *head, *temp, *last;
	head = (struct Node *)malloc(sizeof(struct Node));
	head->value = arr[0];
	head->next = NULL;
	last = head;
	for ( int i = 1; i < size; i++)
	{
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->value = arr[i];
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}

	return head;
}

/*
	Func - insert new head node with given val
	param-
	 current head pointer
	 new val
	return
	 modified head pointer
*/
struct Node* insert_head_node_singly_linked_list(struct Node* head, int val)
{
	struct Node* temp = (struct Node *)malloc(sizeof(struct Node));
	temp->value = val;
	temp->next = head;
	head = temp;
	return head;
}

/*
	Func - display linked list elements
	param-
	 current head pointer
	return
	 None

*/
void display_singly_linked_list(struct Node *head)
{
	while( head != NULL)
	{
		printf("%d ",head->value);
		head = head->next;
	}
	printf("\n");
}

/*
	Func - count number of linked list elements
	param-
	 current head pointer
	return
	 total count
*/

int count_elements_singly_linked_list(struct Node *p)
{
	int count = 0;
	while (p != 0)
	{
		count++;
		p=p->next;
	}
	return count;
}

/*
	Func - insert a node with given val at given position
	param-
	 position at to be inserted except head i.e except 0
	 val of new node
	 current head pointer
	return
	 None
*/
void insert_node_singly_linked_list(int pos, int val, struct Node *p)
{
	if (pos <= 0 || pos > count_elements_singly_linked_list(p))
		return;

	struct Node *temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->value = val;

	for (int i=0;i < pos-1;i++)
	{
		p = p->next;
	}
	temp->next = p->next;
	p->next=temp;
}


/*
	Func - delete a node at given position
	param-
	 current head pointer
	 position to be deleted
	return
	 None
*/
void delete_node_singly_linked_list(struct Node* head, int pos)
{
	struct Node* temp, *prev;
	temp = head;
	prev = NULL;

	// if pos is invalid we need to check using &&
	for ( int i = 0 ; i < pos-1 && temp; i++)
	{
		prev = temp;
		temp = temp->next;
	}

	// only change link if valid node 
	if (temp)
	{
		// now temp will be pointing on node to be deleted and prev on prev Node
		prev->next = temp->next;
		free(temp); 
	}

}

/*
	Func - delete head node
	param-
	 current head pointer
	return
	 new head pointer
*/
struct Node* delete_head_node_singly_linked_list(struct Node* head)
{
	if (head)
	{
		struct Node* temp = head;
		head = head->next;
		free(temp);
	}
	return head;
}

/*
	Func - remove all duplicates from sorted linked list
	param-
	 current head pointer
	return
	 None
*/
void remove_duplicates_from_sorted_singly_linked_list(struct Node* head)
{
	if (!head)
	{
		return;
	}

	struct Node *tail, *temp;
	tail = head;
	temp = head->next;

	while(temp != NULL)
	{
		if (tail->value != temp->value)
		{
			tail=temp;
			temp=temp->next;
		}
		else
		{
			tail->next = temp->next;
			free(temp);
			temp = tail->next;
		}
	}
}

/*
	Func - reverse given linked list
	param-
	 current head pointer
	return
	 new head pointer
*/
struct Node* reverse_singly_linked_list(struct Node* head)
{
	struct Node *one, *two, *three;
	one=NULL;
	two=NULL;
	three = head;

	while(three != NULL)
	{
		one = two;
		two = three;
		three = three->next;
		two->next = one;
	}

	head = two;
	return head;
}

/*
	Func - merge two sorted linked list
	param-
	 current head pointer for both sorted lists
	return
	 new head pointer
*/
struct Node* merge_sorted_singly_linked_list(struct Node* p, struct Node* q)
{
	struct Node *first, *last;
	if (p->value < q->value)
	{
		first=last=p;
		p = p->next;
		last->next = NULL;
	}
	else
	{
		first=last=q;
		q=q->next;
		last->next = NULL;
	}
	while ((p != NULL) && (q != NULL))
	{
		if (p->value < q->value)
		{ 
			last->next = p;
			last = p;
			p = p->next;
			last->next = NULL;
		}
		else if (p->value > q->value)
		{
			last->next = q;
			last = q;
			q = q->next;
			last->next = NULL;
		}
		else
		{
			last->next = p;
			last = p;
			p = p->next;
			last->next = q;
			last = q;
			q=q->next;
			last->next=NULL;
		}
	}
	if (p)
	{
		last->next = p;
	}
	else
	{
		last->next = q;
	}

	return first;
}

/************ Singly and Circular Linked List *****************/
/*
Circular linked list generally dont have first and last node since
all are in circular fashion. We have ref to any one of node which can
be called as head.
*/

/*
	Func - display circular linked list
	param-
	 current head pointer
	return
	 None
*/
void display_circular_singly_linked_list(struct Node *head)
{
    struct Node *p=head;
    do
    {
        printf("%d ", p->value);
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
struct Node* create_circular_singly_linked_list(int arr[], int n)
{
	struct Node *head, *last,*t;
    
    head=(struct Node *)malloc(sizeof(struct Node));
    head->value=arr[0];
    head->next=head;
    last=head;
    for(int i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->value=arr[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }

    return head;
}

/*
	Func - length of circular linked list
	param-
	 current head pointer
	return
	 length of list
*/
int length_of_circular_singly_linked_list(struct Node *head)
{
	struct Node *p=head;
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
	Func - insert node at a position. head is considered as 0 index
	param-
	 current head pointer
	 new value
	 positon to be inserted
	return
	 head pointer
*/
struct Node* insert_node_circular_singly_linked_list(struct Node *head, int val, int pos)
{
	if(pos < 0 || pos > length_of_circular_singly_linked_list(head))
	{
		return head;
	}

	if(pos == 0)
	{
		// insert before current head
		struct Node *temp, *p;
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->value = val;
		p = head;

		if(head == NULL)
		{
			head = temp;
			head->next=head;
		}
		else
		{
			while(p->next != head)
			{
				p = p->next;
			}	

			// now p is pointing at last node
			p->next= temp;
			temp->next=head;	

			// no need to move head to temp since circular linked list is fine
		}
		
	}
	else
	{
		//insert at some non zero pos similar to linear linked list
		struct Node *temp, *p;
		p=head;
		for (int i = 0; i < pos-1; i++) 
		{
			p = p->next;
		}
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->value = val;
		temp->next = p->next;
		p->next = temp;
	}

	return head;
}

/*
	Func - delete node at a position. head is considered as 0 index
	param-
	 current head pointer
	 positon to be deleted
	return
	 None

	This is similar to delete_node for linear linked list
*/

/*
	Func - delete head
	param-
	 current head pointer
	return
	 new head
*/
struct Node* delete_head_node_circular_singly_linked_list(struct Node *head)
{
	struct Node *temp = head;

	while(temp->next != head)
	{
		temp=temp->next;
	}
	if(temp==head)
	{
		// this means only 1 node in current linked list
		free(temp);
		head=NULL;
	}

	temp->next = head->next;
	free(head);
	head = temp->next;

	return head;
}

int main()
{
	struct Node *HEAD,*CHEAD;
	int a[] = {1,2,3,4,5};
	int i = 5, j;

	//create
	HEAD = create_singly_linked_list(a,i);
	display_singly_linked_list(HEAD);

	//insert new head
	HEAD = insert_head_node_singly_linked_list(HEAD,10);
	display_singly_linked_list(HEAD);

	//count linked list elements
	j = count_elements_singly_linked_list(HEAD);
	printf("%d\n",j);

	//insert node
	insert_node_singly_linked_list(3,99,HEAD);
	display_singly_linked_list(HEAD);

	//delete node
	delete_node_singly_linked_list(HEAD,3);
	display_singly_linked_list(HEAD);

	//delete head
	HEAD= delete_head_node_singly_linked_list(HEAD);
	display_singly_linked_list(HEAD);

	// reverse
	HEAD = reverse_singly_linked_list(HEAD);
	display_singly_linked_list(HEAD);

	//create circular linked list
	int c[] = {10,20,30,40,50,60};
	int l = 6, t;
	CHEAD = create_circular_singly_linked_list(c,l);

	//display
	display_circular_singly_linked_list(CHEAD);

	//length
	t = length_of_circular_singly_linked_list(CHEAD);
	printf("%d\n",t);

	//insert node
	CHEAD = insert_node_circular_singly_linked_list(CHEAD, 99, 4);
	display_circular_singly_linked_list(CHEAD);

	//insert head node
	CHEAD = insert_node_circular_singly_linked_list(CHEAD, 11, 0);
	display_circular_singly_linked_list(CHEAD);

	//delete head node
	CHEAD = delete_head_node_circular_singly_linked_list(CHEAD);
	display_circular_singly_linked_list(CHEAD);

	return 0;
}