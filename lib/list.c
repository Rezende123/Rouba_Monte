#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

// FELIPE REZENDE

tCard *createCard(enum TypeCard typeCard, enum Naipe naipe) {
   tCard *_card;
   _card = malloc(sizeof(tCard));

   _card->typeCard = typeCard;
   _card->naipe = naipe;
   _card->next = NULL;

   return _card;
}

tMount *createMount() {
   tMount *_mount;
   _mount = malloc(sizeof(tMount));

   _mount->init = NULL;
   _mount->numberElement = 0;

   return _mount;
}

void showMount(tMount *mount) {
   tCard *card_current = mount->init;
   
   while(card_current != NULL){
      printf("Value: %d | Naipe: %d \n", card_current->typeCard, card_current->naipe);
      card_current = card_current->next;
   }
}

int searchMountItem(tMount *mount, enum TypeCard searchValue) {
   tCard *card_current = mount->init;
   
   while(card_current->next != NULL || card_current->typeCard == searchValue){
      card_current = card_current->next;
   }

   if (card_current->typeCard == searchValue) return 1;
   return 0;
}

int deleteMountItem(tMount *mount,  enum TypeCard searchValue) {
   if (mount == NULL || mount->init == NULL) return 0;
   
   tCard *card_current = mount->init, *Card_last;
   
   while(card_current->next != NULL && card_current->typeCard == searchValue){
      Card_last = card_current; // Guardamos o valor atual para poder apagar em seguida
      card_current = card_current->next;
   }

   if (card_current->typeCard == searchValue) {
      Card_last->next = card_current->next;
      printf("[DELETE] %s \n", searchValue);
      free(card_current);
      return 1;
   }
   
   return 0;
}

int addCard(tMount *mount, enum TypeCard typeCard, enum Naipe naipe) {
   if (mount == NULL) return 0;
   
   tCard *card_current = mount->init;

   if (card_current == NULL) {
      mount->init = card_current = createCard(typeCard, naipe);
      mount->numberElement++;
      // printf("[CREATE] %d \n", mount->init->typeCard);
      return 1;
   }
   
   while(card_current->next != NULL && card_current != card_current->next){
      card_current = card_current->next;
   }

   card_current->next = createCard(typeCard, naipe);
   // printf("[CREATE] %d \n", card_current->next->typeCard);
   mount->numberElement++;
   
   return 1;
}

tCard *extractCardForIndex(tCard *card_current, int index) {
   tCard *card_last;
   for (int i = 0; i <= index; i++)
   {
      card_last = card_current;
      if (card_current == card_current->next || card_current->next == NULL) {
         break;
      } else {
         card_current = card_current->next;
      }
   }    

   card_last->next = card_current->next;

   return card_current;
}

