#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
   if(argc != 2) {
      printf("Uso: <programa> <medida-em-metros>\n");
      return 1;
   }

   printf("Em centimetros: %f\n", atof(argv[1])*100);
   return 0;
}
