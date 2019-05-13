#include <stdio.h>
#include <stdlib.h>
#include "lib/stack.c"
#include "lib/simulator.c"

int main()
{
   tMount *pack = generatePack();
   generateDeck(pack);

   free(pack);
}