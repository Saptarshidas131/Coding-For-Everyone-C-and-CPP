/*
Use the linear linked list code to store a randomly generated set of 100 integers.  Now write a routine that will rearrange the list in sorted order of these values. Note you might want to use bubble sort to do this. Print these values in rows of 5 on the screen.

How will this work? Compare two adjacent list elements and if they are out of order swap them. After a first pass the largest element will have bubbled to the end of the list. Each pass can look at one less element as the end of a list stays sorted.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

 //define list type
typedef struct list{ int data; struct list *next;} list;

// swap function to swap two integers
void swap(int *a, int *b)  
{  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
}  
  
// bubble sort function to sort the linked list 
void bubbleSort(int data[], int how_many)  
{  
    int i, j;

    for (i = 0; i < how_many; i++)
    {
        for (j = how_many-1; j>i; j--)
        {
            if (data[j-1]<data[j])
            {
                swap(&data[j-1], &data[j]);	// calling swap function
            }
        }
    }
      
}  

// is_empty function for checking if linked list is empty
int is_empty(const list *l){ return (l==NULL);}

// creating the linked list
list* create_list(int d)
{
    list* head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    return head;
}

// function to add in the front of the list
list* add_to_front(int d, list* h)
{
    list* head = create_list(d);
    head -> next = h;
    return head;
}

// converting array to linked list
list* array_to_list(int d[], int size)
{
    list* head = create_list(d[0]);
    int i;
    for (i = 1; i < size; i++)
    {
        head = add_to_front(d[i], head);
    }
    return head;
}

// print function to print the sorted linked list
void print_list(list *h, char *title)
{
    printf("%s\n", title);
    while (h !=NULL)
    {

        for (int i=1;i<101;i++)
        {
            printf ("%d\t", h -> data);
            h = h ->next;
            if (i%5==0)
            {
                printf ("\n");
            }
        }
    }
}

// main function
int main()
{
	// generating a set of 100 random integers
    int size=100;
    int randArray[size];
    for (int i=0; i<size;i++)
    {
        randArray[i]=rand();
    }

    bubbleSort(randArray,size);
    
    list list_of_int;
    list* head = NULL;
    head = array_to_list(randArray, size);
    print_list(head, "sorted random 100 numbers");
    printf("\n\n");
  
  	return 0;
}
