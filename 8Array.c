//Escribir un programa que declare el array de enteros 1, 2, 3, 4, 5, 6 e invierta el orden del mismo. Luego imprimirlo.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int array[] = {1, 2, 3, 4, 5, 6};
  int N = 6;
  for (int i = N - 1; i >= 0; i--) {
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}
