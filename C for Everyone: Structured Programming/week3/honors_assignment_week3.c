/*
Modify the singly linked list to be a doubly linked list. Now write a routine that removes all duplicate data in the doubly linked list. The data will be integers generated at random from [0,49]. Initially have a list of 200 elements.

Now do this in one of two ways.  Sort the list by its data field. Remove adjacent elements of the sorted list with the same value. Or, take the first element—search the remainder of the list for elements with the same data and remove them. Then take the second element and do the same. Repeat until only one element is left.


*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int ELEMENTS = 200;    // number of items
const int RAND = 49;       // between 0 and RAND (50 elements)
typedef struct item_table { int data; int val;  struct item_table * next;} item_list ;   // info related to atomic elemements
void input_item_table(struct item_table* head);   // function that executes a set of elements
void print_table(struct item_table* head, char s[]);      // function that prints items
void sorted_list(item_list * list);                        // sort the list for convenience
void pop_duplicates(item_list** list, int val);           // function that deletes an item at its index (val)
item_list * get_node(item_list * head, int val);          // function to get at index (next) the following item
int finding_duplicates(struct item_table * head );          // we are looking for duplicates and remove duplicates using the pointer to the pointer
int main(void) {
    int i,j = 0, val_temp;                                   //temporary elements
    char generated[] ={"after removing duplicates"};         //for ease of display
    char sorted[] = {"sorted"};                             //for ease of display
    item_list *head = NULL;
    head = malloc(sizeof(item_list));
    input_item_table(head);                              // call the function and pass the values
    sorted_list(head);                                  // sort the list for convenience
    print_table(head, sorted);                          // function that prints items
    for(i = 0; i <= j ; i++){                   //for no line iterations  j
        val_temp = finding_duplicates(head);           //   get the count value j
        if (val_temp > 0) j++;
    }
    print_table(head, generated);                      // function that prints items
    free(head);                  //free memory
    return 0;
}

int finding_duplicates(struct item_table * head ){     // we are looking for duplicates and remove duplicates using the pointer to the pointer
    item_list * current;
    int i;
    current = head;
    for(i = 1; ((i <= ELEMENTS ) && (current->next != NULL)) ;i++){
        if(current->data == current->next->data){
            pop_duplicates(&head, i);        // function that deletes an item at its index (val)
            return 1;
        }
            current = current->next;
    }
    return 0;
}

item_list * get_node(item_list * head, int val) {   // function to get at index (next) the following item
    int i = 0;
    while (i < val && head) {    // cycle not yet index (next) of next element
        head = head->next;
        i++;
    }
    return head;
}

void pop_duplicates(item_list** list, int val){      // function that deletes an item at its index (val)
    item_list * next_item = NULL;
    item_list * back_item = NULL;
    if(!list){                      // if received NULL
        exit(-1);
    } else if (!(*list)){           // if the list is empty
        exit(-1);
    }
    next_item = get_node(* list, (val - 1));     // function to get at index (next) the following item
    if (next_item != NULL){
        back_item  = next_item->next;
        next_item->next = back_item->next;
        free(back_item);
    }
    *list = next_item;                             // update list

}

void sorted_list(item_list * list){     // sort the list for convenience
    item_list * current;
    int temp_a_data ;
    int i, j;
    for(i = 0;i < ELEMENTS; i++){
        current = list;
        for(j = 1; ((j <= (ELEMENTS - i)) && (current->next != NULL)) ;j++){
            if(current->data > current->next->data){
                temp_a_data = current->data;
                current->data = current->next->data;
                current->next->data = temp_a_data;
            }
            current = current->next;
        }
    }
}

void print_table(struct item_table* head, char s[]) {  // function that prints items val
    item_list * current = head;
    int i = 0, j = 0;

    printf("______________________________________________________________\n");
    while(current != NULL){                    // cycle has not yet typed all the necessary elements
        if(i % 5 == 0) printf("\n");
        printf("%d\t ", current->data);
        current = current->next;
        i++;
        j++;
    }
    printf("\n\ntotal %s numbers %d between 0 and %d\n",s, j, RAND);
}

void input_item_table(struct item_table* head) {   // function that executes a set of elements into an array (dynamic memory)
    item_list * current = head;
    int i;
    srand(time(NULL));
    for (i = 1; i <= ELEMENTS; i++){                              // cycle until we get all the elements
        if(i == 1){   //for the first item
            current->val = i;
            current->data = (rand() % (RAND + 1 )) ;
            current->next = NULL;
        } else {                                                // all other elements
            while(current->next != NULL){                      // the address of the pointer to the following node
                current = current->next;
            }
            current->next = malloc(sizeof(item_list));
            current->next->val = i;
            current->next->data = (rand() % (RAND + 1)) ;
            current->next->next = NULL;
        }
    }
}
