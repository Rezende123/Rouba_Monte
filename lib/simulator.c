#include <stdio.h>
#include <stdlib.h>
#include <time.h>//necessário p/ função time()
#include "simulator.h"

tCard *lotteryCards(tMount *mount) {
    int range = mount->numberElement;

    srand(time(0));
    int swiched = rand() % range;

    if (mount->init == NULL) {
        return NULL;
    }
    tCard *card_lottery = mount->init;

    card_lottery = extractCardForIndex(card_lottery, swiched);

    // printf("[FINAL] %d\n", card_lottery->typeCard);
    return card_lottery;
};

tMount *generatePack() {
    tMount *pack = createMount();

    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 12; i++)
        {
            addCard(pack, i, j);
        };
    }
    
    printf("[Baralho inicializado]\n");
    return pack;
}

tMount *generateDeck(tMount *pack) {
    tMount *deck = createMount();

    for (int i = 0; i < 4; i++)
    {
        tCard *card = lotteryCards(pack);
        addCard(deck, card->typeCard, card->naipe);    
    }
    showMount(deck);

    return deck;
}

tPlayer *createPlayer(char name[20]) {
    tPlayer *player = malloc(sizeof(tPlayer));

    player->deck = NULL;
    strcpy(player->name, name);

    return player;
}

void playGame(tPlayer *players[4], tMount *mount) {
    
}