#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void determine_high_card(uint8_t *hand);
void populate_hand(uint8_t *hand, char *input);
void order_hand(uint8_t *hand);

int main(int argc, char **argv) {
    if (argc != 2) {
        exit(11);
    }

    if (strlen(argv[1]) != 10) {
        exit(21);
    }

    char c;
    for (int i = 0; i < 10; i++) {
        c = argv[1][i];
        if ((c != 'A') && (c != 'K') && (c != 'Q') && (c != 'J') && (c != 'T') && ((c < '2') || (c > '9'))) {
            exit(30 + i);
        }
        c = argv[1][++i];
        if ((c != 'S') && (c != 'H') && (c != 'D') && (c != 'C')) {
            exit(30 + i);
        }
    }

    uint8_t *hand = (uint8_t *) malloc(5 * sizeof(uint8_t));

    if (hand == NULL) {
        printf("Memory Allocation for uint8_t *hand[5] failed.");
        exit(41);
    }
    
    populate_hand(hand, argv[1]);

    order_hand(hand);

    determine_high_card(hand);

    free(hand);

    return 0;
}

void determine_high_card(uint8_t *hand) {
    int n = hand[0] / 4;
    if (n == 12) {
        printf("Ace");
    } else if (n == 11) {
        printf("King");
    } else if (n == 10) {
        printf("Queen");
    } else if (n == 9) {
        printf("Jack");
    } else if (n <= 8) {
        printf("%d", n + 2);
    }
    return;
}

void order_hand(uint8_t *hand) {
    for (int i = 1; i < 5; i++) {
        int j = 0;
        while ((j < i) && (hand[j] > hand[i])) {
            j++;
        }
        if (i != j) {
            uint8_t temp = hand[i];
            for (int k = i; k > j; k--) {
                hand[k] = hand[k - 1];
            }
            hand[j] = temp;
        }
    }
    return;
}

void populate_hand(uint8_t *hand, char *input) {
    char c;
    for (int i = 0; i < 5; i++) {
        c = input[2 * i];

        if (c >= '2' && c <= '9') {
            hand[i] = 4 * (c - 50);
        } else if (c == 'T') {
            hand[i] = 32;
        } else if (c == 'J') {
            hand[i] = 36;
        } else if (c == 'Q') {
            hand[i] = 40;
        } else if (c == 'K') {
            hand[i] = 44;
        } else if (c == 'A') {
            hand[i] = 48;
        } else {
            exit(51);
        }

        c = input[(2 * i) + 1];

        if (c == 'C') {
            hand[i] += 3;
        } else if (c == 'D') {
            hand[i] += 2;
        } else if (c == 'H') {
            hand[i]++;
        } else if (c != 'S') {
            exit(52);
        }
    }
    return;
}