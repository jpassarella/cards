#ifndef READ_CARDS_H
#define READ_CARDS_H

#include <stdbool.h>

/* Simple arithmetic functions to determine if a given card is of a specified rank. */
bool is_2(int card);
bool is_3(int card);
bool is_4(int card);
bool is_5(int card);
bool is_6(int card);
bool is_7(int card);
bool is_8(int card);
bool is_9(int card);
bool is_10(int card);
bool is_jack(int card);
bool is_queen(int card);
bool is_king(int card);
bool is_ace(int card);

/* Simple arithmetic functions to determine if a given card is of a specified suit. */
bool is_club(int card);
bool is_diamond(int card);
bool is_heart(int card);
bool is_spade(int card);

/* Functions for converting card values into a char format or into a char-array format */
char get_rank_char(int card);
char get_suit_char(int card);
char *get_card_code(int card);
char *get_hand_code(int* hand);

/* Functions for converting card values into string format */
char *get_rank_string(int card);
char *get_suit_string(int card);
char *get_card_string(int card);
char *get_hand_string(int *hand);

/* Function for printing the card integer value (i.e. the int used to store that card)*/
void print_card_value(int card);

/* Functions used to print card codes when represented as chars and char arrays */
void print_rank_char(int card);
void print_suit_char(int card);
void print_card_code(int card);
void print_hand_code(int *hand);

/* Functions used to print card strings */
void print_rank_string(int card);
void print_suit_string(int card);
void print_card_string(int card);
void print_hand_string(int *hand);

/* Functions used to determine what the rank of particular cards in a 5-card-hand are, given the order of cards */
int get_high_card_from_hand(int *hand);
int get_second_card_from_hand(int *hand);
int get_third_card_from_hand(int *hand);
int get_fourth_card_from_hand(int *hand);
int get_low_card_from_hand(int *hand);

#endif