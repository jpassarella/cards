#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* NOTE: Hole cards must be the last 2 given for program logic to work as intended. */

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Error: There must be exactly one command-line argument.\nError code: 11");
        exit(11);
    }

    if (strlen(argv[1]) != 14) {
        printf("Error: The command-line argument must be a string with exactly 14 characters.\nError code: 21");
        exit(21);
    }

    char c;
    for (int i = 0; i < 14; i++) {
        c = argv[1][i];
        if ((c != 'A') && (c != 'K') && (c != 'Q') && (c != 'J') && (c != 'T') && ((c < '2') || (c > '9'))) {
            printf("Error: Invalid character for suit located at position %d of the command-line argument.\nError code: %d", i, 300 + i);
            exit(300 + i);
        }
        c = argv[1][++i];
        if ((c != 'S') && (c != 'H') && (c != 'D') && (c != 'C')) {
            printf("Error: Invalid character for suit located at position %d of the command-line argument.\nError code: %d", i, 300 + i);
            exit(300 + i);
        }
    }

    /* Function to turn char array given as command-line argument into an array of uint8_t of size 7 */

    /* Function to order cards, while still keeping hole cards as the last 2 */

    /* There are 21 possible 5-card hands that can be made with 5 community cards and 2 hole cards */
    uint8_t **possible_hands = (uint8_t **)malloc(21 * sizeof(uint8_t *));

    if (!possible_hands) {
        printf("Error: Memory Allocation for uint8_t **possible_hands has failed.\nError code: 41");
        exit(41);
    }

    for (int i = 0; i < 21; i++) {
        possible_hands[i] = (uint8_t *)malloc(5 * sizeof(uint8_t));
        if (!possible_hands[i]) {
            printf("Error: Memory Allocation for uint8_t *possible_hands[%d] has failed.\nError code: %d", i, 500 + i);
            exit(500 + i);
        }
    }

    /* MORE CODE GOES HERE */

    for (int i = 0; i < 21; i++) {
        free(possible_hands[i]);
    }

    free(possible_hands);

    return 0;
}