#include <stdio.h>
#include <stdlib.h>

int main() {
   int a, b, c;
   printf("informe 2 inteiros separados por espaco\n");
   scanf("%d %d", &a, &b);
   // Eu sei sobre o metodo que envolve apenas 2 variaveis
   // problema que ele e extremamente mal otimizado
   // Keep It Simple, Stupid
   c = a;
   a = b;
   b = c;

   printf("a = %d, b = %d\n", a, b);
   return 0;
}
