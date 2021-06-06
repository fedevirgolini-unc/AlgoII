#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "truco.h"

truco_card ask_card(truco_card card) {
    int num;
    char palo;
    printf("Numero (entre el 1 y 12, diferente a 8 o 9): ");
    scanf("%d", &num);
    printf("Palo ('e', 'o', 'c', 'b'):");
    scanf("%c", &palo);

    card = truco_card_new(num, palo);

    return card;

}

int main(void) {

    truco_card card1 = NULL;
    truco_card card2 = NULL;

    printf("Ingrese los valores para la carta 1:\n");
    card1 = ask_card(card1);

    printf("Ingrese los valores para la carta 2:\n");
    card2 = ask_card(card2);

    if (truco_card_tie(card1, card2)) {
        printf("¡La mano está parda!\n");
        truco_card_dump(card1);
        truco_card_dump(card2);
    } else if (truco_card_win(card1, card2)) {
        printf("Carta ganadora:\n");
        truco_card_dump(card1);
        printf("Carta perdedora:\n");
        truco_card_dump(card2);
    } else {
        printf("Carta ganadora:\n");
        truco_card_dump(card2);
        printf("Carta perdedora:\n");
        truco_card_dump(card1);
    }
    
    free(card1);
    free(card2);
    
    return 0;
}