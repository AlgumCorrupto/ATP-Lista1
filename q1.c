#include <stdio.h>
#include <stdlib.h>

float celsiusToFahrenheint(float celsius) {
   return (9 * celsius + 160)/5;
}

float celsiusToKelvin(float celsius) {
   return (celsius + 273);
}

int main(int argc, char* argv[]) {
   if(argc != 2) {
      printf("Uso: <programa> <grau-em-celsius>");
      return 1;
   }
   int celsius = atof(argv[1]);

   printf("Fahrenheint: %f\n", celsiusToFahrenheint(celsius));
   printf("Kelvin: %f\n", celsiusToKelvin(celsius));
   return 0;
}
