// ENUNCIADO
// Leia o salario mensal atual de um funcionario e o 
// percentual de reajuste. Calcular e escrever o valor
// do novo salario 

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
   if(argc != 3) {
      printf("Uso: <salario-atual> <reajuste>\n");
      return 1;
   }
   int salario = atoi(argv[1]);
   float reajuste = atoi(argv[2]) * 0.01;
   printf("Salario reajustado: %f\n", salario * reajuste);
   return 0;
}
