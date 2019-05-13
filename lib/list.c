#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

// FELIPE REZENDE

tCard *createCard(char value[20], enum Naipe naipe) {
   tCard *_card;
   _card = malloc(sizeof(tCard));

   strcpy(_card->value, value);
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
      printf("Value: %s | Naipe: %d \n", card_current->value, card_current->naipe);
      card_current = card_current->next;
   }
}

int searchMountItem(tMount *mount, char searchValue[20]) {
   tCard *card_current = mount->init;
   
   while(card_current->next != NULL || strcmp(card_current->value, searchValue)){
      card_current = card_current->next;
   }

   if (strcmp(card_current->value, searchValue)) return 1;
   return 0;
}

int deleteMountItem(tMount *mount,  char searchValue[20]) {
   if (mount == NULL || mount->init == NULL) return 0;
   
   tCard *card_current = mount->init, *Card_last;
   
   while(card_current->next != NULL && strcmp(card_current->value, searchValue)){
      Card_last = card_current; // Guardamos o valor atual para poder apagar em seguida
      card_current = card_current->next;
   }

   if (strcmp(card_current->value, searchValue)) {
      Card_last->next = card_current->next;
      printf("[DELETE] %s \n", searchValue);
      free(card_current);
      return 1;
   }
   
   return 0;
}

int addCard(tMount *mount, char value[], enum Naipe naipe) {
   if (mount == NULL) return 0;
   
   tCard *card_current = mount->init;

   if (card_current == NULL) {
      mount->init = card_current = createCard(value, naipe);
      mount->numberElement++;
      // printf("[CREATE] %s \n", mount->init->value);
      return 1;
   }
   
   while(card_current->next != NULL && card_current != card_current->next){
      card_current = card_current->next;
   }

   card_current->next = createCard(value, naipe);
   // printf("[CREATE] %s \n", card_current->next->value);
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

