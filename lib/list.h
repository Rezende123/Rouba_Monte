#ifndef LIST_H   // guardas de cabeçalho, impedem inclusões cíclicas
#define LIST_H

enum Naipe {
    gold,
    swords,
    cups, 
    wands
};

enum TypeCard {
    A,K,Q,J,_10,_9,_8,_7,_6,_5,_4,_3
};

typedef struct card
{
    enum TypeCard typeCard;
    enum Naipe naipe;
    struct card *next;
} tCard;

typedef struct Mount
{
   tCard *init;
   int numberElement;
} tMount;

tCard *createCard(enum TypeCard typeCard, enum Naipe naipe);
tMount *createMount();
void showMount(tMount *mount);
int searchMountItem(tMount *mount, enum TypeCard searchValue);
int deleteMountItem(tMount *mount, enum TypeCard searchValue);
int addCard(tMount *mount, enum TypeCard typeCard, enum Naipe naipe);
tCard *getCardForIndex(tCard *card_current, int index);

#endif