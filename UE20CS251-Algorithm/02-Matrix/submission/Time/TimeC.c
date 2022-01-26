#include "TimeH.h"

int main() {
  struct timespec start;
  struct timespec end;
  clock_gettime(CLOCK_REALTIME, &start);

  clock_gettime(CLOCK_REALTIME, &end);
  long long int s = long_loop();
  printf("time %lf \n", time_elapsed(start, end));
  printf("s : %lld\n", s);
  return 0;
}
