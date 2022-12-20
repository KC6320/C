/*
    stack implementation and operations using array
*/
#include <stdlib.h>
#include <stdio.h>

/*
    stack defintion
*/
struct Stack{
    int size;  
    int top;
    int *S;
};

/* 
    Func - display stack elements. 0 index -> top element.
    params: 
     stack struct
    return:
     None
*/
void display(struct Stack st)
{
    if(st.top == -1)
        printf("%s\n","Stack is empty");
    else
    {
        int i;
        for(i=st.top; i>=0; i--)
        {
            printf("%d\n",st.S[i]);
        }
    }
}

/* 
    Func - push to top of stack.
    params: 
     ref stack struct
     value to be added
    return:
     None
*/
void push(struct Stack *st, int x)
{
    if(st->top == st->size - 1)
    {
        printf("%s\n","stack overflow");
    }
    else
    {
        st->top++;
        st->S[st->top]=x;
    }
}

/* 
    Func - remove top element from stack.
    params: 
      ref stack struct
    return:
     value at top
*/
int pop(struct Stack *st)
{
    int x=-1;
    if(st->top == -1)
    {
        printf("%s\n","Stack underflow");
    }
    else
    {
        x=st->S[st->top];
        st->top--;
    }
    return x;
}

/* 
    Func - peek a value at certain index. 0 index -> top element.
    params: 
     stack struct
     index
    return:
     value at index
*/
int peek(struct Stack st, int index)
{
    int x=-1;
    if(index < 0 || index > st.top)
    {
        printf("%s\n","Invalid Index");
    }
    else
    {
        x=st.S[st.top-index];
    }
    return x;
}

/* 
    Func - check if stack is empty
    params: 
     stack struct
    return:
     True or False
*/
int is_empty(struct Stack st)
{
    if(st.top == -1)
    {
        return 1;
    }
   
    return 0;
}

/* 
    Func - check if stack is full
    params: 
     stack struct
    return:
     True or False
*/
int is_full(struct Stack st)
{
    return st.top == st.size - 1;
}

/* 
    Func - get the value at top of stack
    params: 
     stack struct
    return:
     value at top
*/
int get_top_element(struct Stack st)
{
    if(!is_empty(st))
    {
        return st.S[st.top];
    }
    return -1;
}

int main()
{
    struct Stack stack;

    //set stack size as 10 elements
    stack.size = 10;
    stack.top = -1;
    stack.S = (int *)malloc(sizeof(int)*stack.size);
    display(stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    display(stack);

    pop(&stack);
    printf("%s\n", "After popping top element");
    display(stack);

    printf("%d\n", peek(stack,2));
    return 0;
}