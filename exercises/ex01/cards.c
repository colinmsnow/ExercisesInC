/*
Card counting program
Colin Snow
Adapted from Head First C

Keeps a running count of the value based on 
cards which have been played and advises 
the player when to bet
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    char card_name[3];
    int count = 0;
    int val;
    int check_value(char card[]);
    int change_count(int val, int count);
    int read_number(char card[]);

    while(card_name[0] != 'X'){
        puts("Enter the card name: ");
        scanf("%2s", card_name);
        val = check_value(card_name);
        count = change_count(val, count);
    }

    return 0;
}

/*
converts the card value to an integer and then checks if
it is in the range of allowed cards.

card: the user-input card as a char array
returns: the value of the card if it is allowed else 0
*/
int read_number(char card[]){

    int value = atoi(card);
    if ((value < 1) || (value > 10)){
        puts("I don't understand that value!");
        value = 0;
    }

    return value;
}

/*
finds the value of a card by checking for face cards
and for numbers.

card: the user-input card as a char array
returns: the value of the card if it is valid else 0
*/
int check_value(char card[]){
    int val = 0;

    switch(card[0]){
        case 'K':
        case 'Q':
        case 'J':
            val = 10;
            break;
        case 'A':
            val = 11;
            break;
        case 'X':
            break;
        default:
            val = read_number(card);
    }

    return val;
}

/*
Updates the count based on the value of the last card.

value: the value of the last card that was played
count: the count as of the turn before that card
returns: the new count
*/
int change_count(int value, int count){
    if ((value > 2) && (value< 7)){
        count++;
    } else if (value == 10){
        count--;
    }
     printf("Current count: %i\n", count);
    return count;
}