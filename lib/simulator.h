#ifndef SIMULATOR_H   // guardas de cabeçalho, impedem inclusões cíclicas
#define SIMULATOR_H
#include "list.c"

// Mount se refere a uma lista de cartas

typedef struct Player
{
   char name[20];
   tMount *deck;
} tPlayer;

tCard *lotteryCards(tMount *mount);
tPlayer *createPlayer(char name[20]);
tMount *generatePack();
tMount *generateDeck(tMount *pack);
void createCenaOfGame(tMount *pack);


#endif