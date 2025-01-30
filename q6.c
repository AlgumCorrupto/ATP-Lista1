#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
   if(argc != 2) {
      printf("Uso: <programa> <valor>\n");
      return 1;
   }
   int val = atoi(argv[1]);
   printf("Antecessor: %d\n", val - 1);
   printf("Sucessor: %d\n", val + 1);
   return 0;
}
