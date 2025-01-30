// ENUNCIADO:
// Dado o peso e a altura do usuario imprima seu 
// Indice de Massa Corporal.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]) {
   if(argc != 3) {
      printf("Uso: <programa> <peso> <altura>\n");
      return 1;
   }
   float peso = atof(argv[1]);
   float altura = atof(argv[2]);
   float imc = peso/(pow(altura, 2.0f));
   printf("Seu IMC: %f\n", imc);
   if(imc < 18.5) {
      printf("SEU MAGRELO!!!!!\n");
   } else if(imc > 25) {
      printf("Usuario de Arch Linux detectado!\n");
   }
   return 0;
}
