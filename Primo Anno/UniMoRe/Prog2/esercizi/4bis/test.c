#include <stdio.h>

int main() {
  FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
  fprintf(gnuplotPipe, "plot '-' with lines\n");
  for (int i = 0; i <= 10; i++) {
    fprintf(gnuplotPipe, "%d %d\n", i, i * i);
  }
  fprintf(gnuplotPipe, "e\n");
  fclose(gnuplotPipe);
  return 0;
}
