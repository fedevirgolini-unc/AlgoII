#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "truco.h"

struct _s_truco_card {
    unsigned int num;
    char palo;
};

#define ESPADA "ESPADA"
#define BASTO  "BASTO"
#define ORO    "ORO"
#define COPA   "COPA"

static const char *suit_str(char p) {
    const char *str;
    if (p == 'e') {
        str = ESPADA;
    } else if (p=='b') {
        str = BASTO;
    } else if (p=='o') {
        str = ORO;
    } else if (p=='c') {
        str = COPA;
    }
    return str;
}

static void dump(int num, char suit) {
    printf(" ----------------\n"
           " : %2d           :\n"
           " :              :\n"
           " :              :\n"
           " :    ""%-7s""   :\n"
           " :              :\n"
           " :              :\n"
           " :              :\n"
           " :           %2d :\n"
           " ----------------\n",
           num, suit_str(suit), num);
}

static int card_rank(int num, char suit) {
    int rank=0;

    if (4 <= num && num <= 12) { // 4 ~ 12
        rank = num - 4;
    } else { // 1 ~ 3
        rank = 8 + num;
    }
    // 0 <= rank <= 11
    if (num==1 && suit == 'e') {      // Ancho de espadas
        rank = 15;
    } else if (num==1 && suit=='b') { // Ancho de bastos
        rank = 14;
    } else if (num==7 && suit=='e') { // Siete de espadas
        rank = 13;
    } else if (num==7 && suit=='o') { // Siete de oro
        rank = 12;
    }
    return rank;
}

static bool invrep(truco_card c) {
    bool valid_card=false;
    valid_card = c->num >= 4 && 
                 c->num <= 12 &&
                 c->num != 8 &&
                 c->num != 9;
    return valid_card;
}

truco_card truco_card_new(int num, char p) {
    truco_card card;

    assert(num >= 1 && num <= 12 && num != 8 && num != 9);
    assert(p == 'e' || p == 'o' || p == 'c' || p == 'b');

    card = malloc(sizeof(struct _s_truco_card));

    if (card != NULL) {
        card->num = num;
        card->palo = p;
    }

    return card;
}

bool truco_card_win(truco_card a, truco_card b) {
    assert(invrep(a) && invrep(b));
    bool card_a_win=false;
    card_a_win = card_rank(a->num, a->palo) > card_rank(b->num, b->palo);
    return card_a_win;
}

bool truco_card_tie(truco_card a, truco_card b) {
    bool is_a_tie=false;
    is_a_tie = card_rank(a->num, a->palo) == card_rank(b->num, b->palo);
    return is_a_tie;
}

void truco_card_dump(truco_card c) {
    dump(c->num, c->palo);
}

truco_card truco_card_destroy(truco_card c) {
    free(c);
    c = NULL;
    return c;
}
