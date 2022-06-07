//Escribir un programa que acepte un argumento p (probabilidad) y un argumento n. Crear una matriz que represente un tablero del juego Buscaminas de n × n marcando con un -1 las casillas con minas o cero de lo contrario. Usar la probabilidad p para determinar si un casillero tiene o no una mina.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {
  //random seed
  srand(time(NULL));
  //los argumentos
  int n = atoi(argv[1]);
  double p = atof(argv[2]);
  //el tablero
  int board[n][n];
  //poner minas en el tablero
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int r = rand() % 100;
      double hay_mina = r/100.0;
      if (hay_mina < p) {
        board[i][j] = 9;
      } else {
        board[i][j] = 0;
      }
    }
  }
  //imprimir el tablero
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
  return 0;
}
