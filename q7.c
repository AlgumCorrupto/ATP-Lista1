// ENUNCIADO: 
// Implemente um programa que le tres valores e calcule 
// a media ponderada para pesos 1, 2 e 3, respectivamente 

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
   if(argc != 4) {
      printf("Uso: <programa> <val1> <val2> <val3>\n");
      return 1;
   }
   float vals[3] = {
      atof(argv[1]),
      atof(argv[2]),
      atof(argv[3])
   };
   float pesos[3] = {1,2,3};
   float media = ((vals[0]*pesos[0])
               +(vals[1]*pesos[1])
               +(vals[2]*pesos[2]))
               /(pesos[0]+pesos[1]+pesos[2]);
   printf("Media ponderada: %f\n", media);
   return 0;
}
