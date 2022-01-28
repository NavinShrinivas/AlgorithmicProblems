void mystrcpy(char *dst, char *src) {
  if (*src == '\0') {
    *dst = *src;
    return;
  } else {
    *dst = *src;
    mystrcpy(dst + 1, src + 1);
  }
}
