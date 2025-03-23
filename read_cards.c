/*

TO DO:

Deal with how strings are handled in these function calls, particularly in the get_card_string() function.
But even just overall, you don't fully understand how these strings are working.
You don't understand what the static keyword is doing here.
You suspect there should be some const keywords thrown around here and there, but none are currently present.
Learn how to clean up this code so that it works as intended and so that you understand everything that is happening.

After that, use these functions to build and troubleshoot the functionality for the score_hand() function.
And then, you can move on to the make_best_hand() function

*/


#include "read_cards.h"

#include <stdio.h>
#include <string.h>

/* Simple arithmetic functions to determine if a given card is of a specified rank. */
bool is_2(int card) {
    return ((card / 4) == 2);
}

bool is_3(int card) {
    return ((card / 4) == 3);
}

bool is_4(int card) {
    return ((card / 4) == 4);
}

bool is_5(int card) {
    return ((card / 4) == 5);
}

bool is_6(int card) {
    return ((card / 4) == 6);
}

bool is_7(int card) {
    return ((card / 4) == 7);
}

bool is_8(int card) {
    return ((card / 4) == 8);
}

bool is_9(int card) {
    return ((card / 4) == 9);
}

bool is_10(int card) {
    return ((card / 4) == 10);
}

bool is_jack(int card) {
    return ((card / 4) == 11);
}

bool is_queen(int card) {
    return ((card / 4) == 12);
}

bool is_king(int card) {
    return ((card / 4) == 13);
}

bool is_ace(int card) {
    return ((card / 4) == 14);
}


/* Simple arithmetic functions to determine if a given card is of a specified suit. */
bool is_club(int card) {
    return ((card % 4) == 0);
}

bool is_diamond(int card) {
    return ((card % 4) == 1);
}

bool is_heart(int card) {
    return ((card % 4) == 2);
}

bool is_spade(int card) {
    return ((card % 4) == 3);
}


/* Functions for converting card values into a char format or into a char-array format */
/* 
Note: 
I included break statements after the return statements in each of the cases for this switch statement and for all others in this file 
so that if I change the format in a way that removes the return statements from inside of each individual case,
it would not cause an error.
Also, as the code is currently written, I expect the compiler will optimize those break statements away anyway.
*/
char get_rank_char(int card) {
    switch (card / 4) {
        case (2) :
            return '2';
            break;
        case (3) :
            return '3';
            break;
        case (4) :
            return '4';
            break;
        case (5) :
            return '5';
            break;
        case (6) :
            return '6';
            break;
        case (7) :
            return '7';
            break;
        case (8) :
            return '8';
            break;
        case (9) :
            return '9';
            break;
        case (10) :
            return 'T';
            break;
        case (11) :
            return 'J';
            break;
        case (12) :
            return 'Q';
            break;
        case (13) :
            return 'K';
            break;
        case (14) :
            return 'A';
            break;
        default :
            return '?';
    }
}

char get_suit_char(int card) {
    switch (card % 4) {
        case (0) :
            return 'C';
            break;
        case (1) :
            return 'D';
            break;
        case (2) :
            return 'H';
            break;
        case (3) :
            return 'S';
            break;
        default :
            return '?';
    }
}

char *get_card_code(int card) {
    static char card_code[2];
    /*
    I debated using a switch statement with 52 non-default cases 
    to initialize both of the values of the array based on the int value of the card itself.
    But if the only benefit of code so ugly is avoiding two simple arithmetic calculations, it doesn't seem worth it.
    I suppose it could potentially lead to some maintainability issues in the future as well.
    */
    card_code[0] = get_rank_char(card);
    card_code[1] = get_suit_char(card);
}

char *get_hand_code(int* hand) {
    static char hand_code[10];
    char *card_code;
    for (int i = 0, j = 0; i < 5; i++) {
        card_code = get_card_code(hand[i]);
        hand_code[j++] = card_code[0];
        hand_code[j++] = card_code[1];
    }
    return hand_code;
}

/* Functions for converting card values into string format */

char *get_rank_string(int card) {
    switch (card / 4) {
        case (2) :
            return "2";
            break;
        case (3) :
            return "3";
            break;
        case (4) :
            return "4";
            break;
        case (5) :
            return "5";
            break;
        case (6) :
            return "6";
            break;
        case (7) :
            return "7";
            break;
        case (8) :
            return "8";
            break;
        case (9) :
            return "9";
            break;
        case (10) :
            return "10";
            break;
        case (11) :
            return "Jack";
            break;
        case (12) :
            return "Queen";
            break;
        case (13) :
            return "King";
            break;
        case (14) :
            return "Ace";
            break;
        default :
            return "Unknown Rank";
    }
}

char *get_suit_string(int card) {
    switch (card % 4) {
        case (0) :
            return "Club";
            break;
        case (1) :
            return "Diamond";
            break;
        case (2) :
            return "Heart";
            break;
        case (3) :
            return "Spade";
            break;
        default :
            return "Unknown Suit";
    }
}

/*
char *get_card_string(int card) {
*/
    /*
    I may be getting myself in over my head here with regards to string literals and read-only memory,
    but I have to learn at some point so let's see what happens.
    This code must be tested for errors, I am not confident this function will always perform as intended.
    */
    /*
    char *card_string = "";
    */
    /* 
    Using the return value of strcat as a parameter for another call of strcat may be better than the code below.
    */
    /*
    strcat(card_string, get_rank_string(card));
    strcat(card_string, " of ");
    strcat(card_string, get_suit_string(card));
    */
    /*
    Fix later, I want bad card values to produce the card string "Unknown Rank of Unknown Suit", 
    and not the card string "Unknown Rank of Unknown Suits".
    Note that "Suit" should not be made plural.
    However, the way I did it below seems a bit crude.
    */
    /*
    if (((card % 3) >= 0) && ((card % 3) <= 3)) {
        strcat(card_string, "s");
    }
}
*/

/*
char *get_hand_string(int *hand) {
    char *hand_string = "";
    for (int i = 0; i < 4; i++) {
        strcat(hand_string, get_card_string(hand[i]));
        strcat(hand_string, "\n");
    }
    strcat(hand_string, get_card_string(hand[4]));
    return hand_string;
}
*/


/* Function for printing the card integer value (i.e. the int used to store that card) */
/* 
Function is certainly unnecessary and probably even stupid to include, 
but it may improve readability or make error testing easier to implement 
*/
void print_card_value(int card) {
    printf("%d", card);
    return;
}


/* Functions used to print card codes when represented as chars and char arrays */

void print_rank_char(int card) {
    printf("%c", get_rank_char(card));
    return;
}

void print_suit_char(int card) {
    printf("%c", get_suit_char(card));
    return;
}

void print_card_code(int card) {
    printf("%c%c", get_rank_char(card), get_suit_char(card));
    return;
}

void print_hand_code(int *hand) {
    for (int i = 0; i < 5; i++) {
        print_card_code(hand[i]);
    }
    return;
}

/* Functions used to print card strings */
void print_rank_string(int card) {
    printf("%s", get_rank_string(card));
    return;
}

void print_suit_string(int card) {
    printf("%s", get_suit_string(card));
    return;
}

/*
void print_card_string(int card) {
    printf("%s", get_card_string(card));
    return;
}

void print_hand_string(int *hand) {
    for (int i = 0; i < 4; i++) {
        print_card_string(hand[i]);
        printf("\n");
    }
    print_card_string(hand[4]);
    return;
}
*/


/* Functions used to determine what the rank of particular cards in a 5-card-hand are, given the order of cards */
int get_high_card_from_hand(int *hand) {
    return hand[0];
}

int get_second_card_from_hand(int *hand) {
    return hand[1];
}

int get_third_card_from_hand(int *hand) {
    return hand[2];
}

int get_fourth_card_from_hand(int *hand) {
    return hand[3];
}

int get_low_card_from_hand(int *hand) {
    return hand[4];
}