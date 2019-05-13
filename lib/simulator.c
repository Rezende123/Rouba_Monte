#include <stdio.h>
#include <stdlib.h>
#include <time.h>//necessário p/ função time()
#include "simulator.h"

tCard *lotteryCards(tMount *mount) {
    int range = mount->numberElement;

    srand(time(0));
    int swiched = rand() % range;

    tCard *card_lottery = mount->init;

    card_lottery = extractCardForIndex(card_lottery, swiched);

    printf("[FINAL] %s\n", card_lottery->value);
    return card_lottery;
};

tMount *distributeCards() {
    tMount *deck = createMount();

    for (int i = 0; i < 12; i++)
    {
        addCard(deck, "A", wands);
    };
    
    showMount(deck);
}

tPlayer *createPlayer(char name[20]) {
    tPlayer *player = malloc(sizeof(tPlayer));

    player->deck = NULL;
    strcpy(player->name, name);

    return player;
}

void playGame(tPlayer *players[4], tMount *mount) {
    
}