#include<stdio.h>
#include <time.h> //time function
#include <stdlib.h> //random number generator functions
#include <string.h>
// constant declarations
#define MAX 9
#define MAX_CARDS 52
#define MAX_PIPS 13
#define MAX_SUITS 4
#define COLS 3 //number of columns to display in output

//structure definition
struct card{
  char *pip;
  char suit[MAX];
};
typedef struct card Card;

//array of pointers to strings for pips
char *pips[MAX_PIPS] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
			  "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

//two-dimensional array of strings for suits
char suits[MAX_SUITS][MAX] = {"Clubs", "Diamonds", "Hearts", "Spades"};

void initialize(Card []);
void shuffle(Card []);
void display(const Card[]);

// main function
int main(){
  char newline = '\n'; //to repeat while loop

  //declare an array of 52 cards
  Card deck[MAX_CARDS] = {"",""};
  initialize(deck);
  printf("Display an ordered deck of cards:\n");
  display(deck);
  while('\n' == newline){
    printf("\nshuffling deck ... \n");
    shuffle(deck);
    display(deck);
    printf("Would you like to shuffle again?\nIf so, press \"Enter\" key. If not, press any other key. ");
    newline = getchar();
  }
  return 0;
}


//initialize the deck of cards to string values
void initialize(Card deck[]){
  int i = 0;
  for(i=0;i<MAX_CARDS;i++){
    deck[i].pip = pips[i%MAX_PIPS];
    strncpy(deck[i].suit, suits[i/MAX_PIPS], MAX);
  }
}


//use the random number generator to shuffle the cards
void shuffle(Card deck[]){

  int swapper = 0; //index of card to be swapped
  int i = 0; //counter
  Card temp = {"", ""}; //temp holding place for swap
  srand(time(NULL)); //seed the random numbers with current time

  for(i=0;i<MAX_CARDS;i++){
    //generate a random number from 0 to 51
    swapper = rand() % MAX_CARDS;
    //swap current card with da swapper
    temp = deck[i];
    deck[i] = deck[swapper];
    deck[swapper] = temp;
  }
}


//display the deck of cards
void display(const Card deck[]){
  int i = 0;
  for(i=0;i<MAX_CARDS;i++){
    printf("%5s of %-12s", deck[i].pip, deck[i].suit);
    printf("\n");

  }
}
