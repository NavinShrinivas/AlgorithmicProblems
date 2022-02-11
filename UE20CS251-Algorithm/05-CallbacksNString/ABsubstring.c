#include <stdio.h>

int count(char *str) {
  int i = 0;
  int count = 0;
  while (str[i]) {
    if (str[i] == 'A') {
      int j = i;
      while (str[j]) {
        if (str[j] == 'B')
          count++;
        j++;
      }
    }
    i++;
  }
  return count;
}

int efficient_count(char *str, char start, char end) {
  int count_a = 0;
  int i = 0;
  int count = 0;
  while (str[i]) {
    if (str[i] == start)
      count_a++;
    if (str[i] == end)
      count += count_a;
    i++;
  }
  return count;
}

int main() {
  char str[1000];
  printf("Enter string : ");
  scanf("%[^\n]c", str);
  printf("Substings : %d \n", count(str));
  printf("Efficient Substring count : %d", efficient_count(str, 'A', 'B'));
}
