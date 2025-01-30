#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
   if(argc != 4) {
      printf("Uso: <programa> <largura> <altura> <comprimento>\n");
      return 1;
   }

   int width   = atoi(argv[1]);
   int height  = atoi(argv[2]);
   int depth   = atoi(argv[3]);
   printf("Area da caixa d'agua: %d\n", width * height * depth);
   return 0;
}
