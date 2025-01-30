#include <stdio.h>
#include <stdlib.h>

int main() {
   int t, v, s0;
   printf("Informe a posicao inicial(S0), velocidade do objeto(V) e tempo elapsado(T) respectivamente e separado por espaços\n");
   printf("Ex: 10 2 3\n");
   scanf("%d %d %d", &s0, &v, &t);

   printf("Sua posicao final(S): %d\n", s0 + v * t);
   return 0;
}
