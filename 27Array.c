//Siguiendo el programa anterior, volver a recorrer el array para llenar los casilleros sin minas con el numero de minas vecinas. Consideren usar un array de (n + 2) × (n + 2) para representar el tablero.

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
  //ponemos 0 en los bordes
  int board[n+2][n+2];
  for (int i = 0; i < n+2; i++) {
    board[0][i] = 0;
    board[n+1][i] = 0;
    board[i][0] = 0;
    board[i][n+1] = 0;
  }
  //poner minas en el tablero
  for (int i = 1; i < n+1; i++) {
    for (int j = 0; j < n+1; j++) {
      int r = rand() % 100;
      double hay_mina = r/100.0;
      if (hay_mina < p) {
        board[i][j] = 9;
      } else {
        board[i][j] = 0;
      }
    }
  }
  //poner la cantidad de minas alrededor de cada casilero
  for (int i = 0; i < n+2; i++) {
    for (int j = 0; j < n+2; j++) {
      if (board[i][j] == 0){
        int count = 0;
        if (board[i-1][j-1] == 9) count++;
        if (board[i][j-1] == 9) count++;
        if (board[i+1][j-1] == 9) count++;
        if (board[i+1][j] == 9) count++;
        if (board[i+1][j+1] == 9) count++;
        if (board[i][j+1] == 9) count++;
        if (board[i-1][j+1] == 9) count++;
        if (board[i-1][j] == 9) count++;
        board[i][j] = count;
      }
    }
  }
  //imprimir el tablero
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      if (board[i][j] == 9) printf("* ");
      else printf("%d ", board[i][j]);
    }
    printf("\n");
  }
  return 0;
}
