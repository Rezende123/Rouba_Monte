#include <stdio.h>
#include <stdlib.h>
#include "lib/stack.c"
#include "lib/simulator.c"

int main()
{
   tMount *mount = createMount();

   addCard(mount, "A", cups);
   addCard(mount, "J", gold);
   addCard(mount, "Q", gold);
   addCard(mount, "K", wands);
   addCard(mount, "CORINGA", gold);
   addCard(mount, "10", gold);

   showMount(mount);
   lotteryCards(mount);

   distributeCards();

   free(mount);
}