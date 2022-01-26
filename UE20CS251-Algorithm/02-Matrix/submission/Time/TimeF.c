#include "TimeH.h"

double time_elapsed(struct timespec start, struct timespec end) {
  double t;
  t = (end.tv_sec - start.tv_sec);
  t += (end.tv_nsec - start.tv_nsec) * 0.000000001;
  return t;
}

long long int long_loop() {
  long int s = 0;
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      s++;
    }
  }
  return s;
}
