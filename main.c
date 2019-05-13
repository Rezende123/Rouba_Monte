#include <stdio.h>
#include <stdlib.h>
#include "lib/stack.c"
#include "lib/simulator.c"

int main()
{
   tMount *pack = generatePack();
   printf("\n\n=====MONTE INICIAL=======\n");
   showMount(pack);

   createCenaOfGame(pack);
   
   printf("\n\n=====MONTE FINAL=======\n");
   showMount(pack);

   free(pack);
}