/*
Develop a struct that can store an atomic element, such as Hydrogen -H -at.wt 1.008.

Now create from input at the terminal the first ten elements in the periodic table as a linked list with this struct as data. Then print out this information to the screen in a nicely readable form. The struct should have three members—one stores the name of the element, a second stores it atomic symbol, and a third stores its weight.
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

//Define element type
typedef struct element{
    char* name;
    char* symbol;
    float weight;
} Element;

//Define the list
typedef struct list{ Element data; struct list *next;} list;
int is_empty(const list *l){ return (l == NULL);}
list* create_list(Element d){
    list* head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    return head;
};

//Functions to add elements to the list
list* add_to_front(Element d, list* h){
    list* head = create_list(d);
    head -> next = h;
    return head;
}

//Convert an array to a list
list* array_to_list(Element d[], int size){
    list* head = create_list(d[0]);
    int i;
    for(i = 1; i < size; i++){
        head = add_to_front(d[i], head);
    }
    return head;
}

//Print the list
void print_list(list *h, char *title){
    printf("\n%s\n\n", title);
    while (h != NULL){
        printf ("%9s\t%2s\t%6.3f\n", 
            h -> data.name, h-> data.symbol, h-> data.weight);
        h = h -> next;
    }
}

//Driver function; data for list
int main(){
    
    //Data for individual elements    
    struct element hydrogen;
    hydrogen.name = "Hydrogen";
    hydrogen.symbol = "H";
    hydrogen.weight = 1.008;

    struct element helium;
    helium.name = "Helium";
    helium.symbol = "He";
    helium.weight = 4.003;

    struct element lithium;
    lithium.name = "Lithium";
    lithium.symbol = "Li";
    lithium.weight = 6.941;

    struct element beryllium;
    beryllium.name = "Beryllium";
    beryllium.symbol = "Be";
    beryllium.weight = 9.012;

    struct element boron;
    boron.name = "Boron";
    boron.symbol = "B";
    boron.weight = 10.811;

    struct element carbon;
    carbon.name = "Carbon";
    carbon.symbol = "C";
    carbon.weight = 12.011;

    struct element nitrogen;
    nitrogen.name = "Nitrogen";
    nitrogen.symbol = "N";
    nitrogen.weight = 14.007;

    struct element oxygen;
    oxygen.name = "Oxygen";
    oxygen.symbol = "O";
    oxygen.weight = 15.999;

    struct element fluorine;
    fluorine.name = "Fluorine";
    fluorine.symbol = "F";
    fluorine.weight = 18.998;

    struct element neon;
    neon.name = "Neon";
    neon.symbol = "Ne";
    neon.weight = 20.180;

    //Build the list and print it
    list elements;
    list* head = NULL;
    Element data[10] = {neon, fluorine, oxygen, nitrogen, 
        carbon, boron, beryllium, lithium, helium, hydrogen};
    head = array_to_list(data, 10);
    print_list(head, "The First Ten Elemements in the Periodic Table");
    printf("\n\n");

return 0;
}
