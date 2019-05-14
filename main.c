#include <stdio.h>
#include <stdlib.h>
#include "lib/stack.c"
#include "lib/simulator.c"

int main()
{
   tMount *pack = generatePack();
   // printf("\n\n=====MONTE INICIAL=======\n");
   // showMount(pack);

   // printf("\n\n=====JOGADORES=======\n");
   tPlayer *players = agroupPlayersAndCards(pack);
   // showPlayers(players);

   printf("\n\n=====MONTE MESA=======\n");
   tMount *mount = generateMount(pack, 6);
   showMount(mount);

   game(pack, mount, players);

   free(pack);
}