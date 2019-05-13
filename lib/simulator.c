#include <stdio.h>
#include <stdlib.h>
#include <time.h>//necessário p/ função time()
#include "simulator.h"

int random(int range) {
    time_t t;

	srand((unsigned)(time(NULL)));
    return rand() % range;
}

tCard *lotteryCards(tMount *mount) {
    int range = mount->numberElement;
    int swiched = random(range);

    printf("[%d]", swiched);

    if (mount->init == NULL) {
        return NULL;
    }
    tCard *card_lottery = mount->init;

    card_lottery = extractCardForIndex(card_lottery, swiched);

    mount->numberElement--;
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

    return deck;
}

tPlayer *createPlayer(char name[20]) {
    tPlayer *player = malloc(sizeof(tPlayer));

    player->deck = NULL;
    strcpy(player->name, name);

    return player;
}

void showPlayers(tPlayer *players) {
    for (int i = 0; i < 4; i++)
    {
        printf("============\n");
        printf("JOGADOR: %s\n", players[i].name);
        printf("DECK: \n");
        showMount(players[i].deck);
        printf("============\n");
    }
}

void createCenaOfGame(tMount *pack) {
    int amountPlayers = 4;
    tPlayer *players = malloc(sizeof(tPlayer) * amountPlayers);

    for (int i = 0; i < amountPlayers; i++)
    {
        snprintf(players[i].name, 10, "Player %d", i);
        players[i].deck = generateDeck(pack);
    }

    showPlayers(players);
}