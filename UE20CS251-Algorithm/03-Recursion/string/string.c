#include "1_1.h"

void mystrcpy(char *dst, char *src) {
  if (*src == '\0') {
    *dst = *src;
    return;
  } else {
    *dst = *src;
    mystrcpy(dst + 1, src + 1);
  }
}

int _len(char *str, int n) {
  if (*str == '\0')
    return n;
  return _len(str + 1, n + 1);
}

int mystrlen(char *str) { return _len(str, 1); }

int _cmp(char *str1, char *str2, int n) {
  if (*str1 == '\0' && *str2 == '\0')
    return n;
  else if (*str1 == '\0' && *str2 != '\0') {
    n += *str2 - 0;
    return _cmp(str1, str2 + 1, n);
  } else if (*str2 == '\0' && *str1 != '\0') {
    n += 0 - *str1;
    return _cmp(str1 + 1, str2, n);
  } else {
    n += *str2 - *str1;
    return _cmp(str1 + 1, str2 + 1, n);
  }
}

int mystrcmp(char *str1, char *str2) { return _cmp(str1, str2, 0); }
