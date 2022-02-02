#include "1_1.h"
#include <stdio.h>

int main() {
  char str1[10000];
  printf("Enter a string to do operations on : ");
  scanf("%[^\n]c", str1);
  printf("String entered : %s \n", str1);
  while (true) {
    printf("1.Copy string \n");
    printf("2.Length of string \n");
    printf("3.Compare strings \n");
    printf("Enter choice : ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
      char str2[10000];
      mystrcpy(str2, str1);
      printf("\n Copied string : %s \n \n", str2);
    } else if (choice == 2) {
      printf("\n Length of entered string : %d \n \n", mystrlen(str1));
    } else if (choice == 3) {
      // from man pages :
      printf("\nstrcmp returns an integer indicating the result of the "
             "comparison, as follows:\n");
      printf("• 0, if the s1 and s2 are equal;\n");
      printf("• a negative value if s1 is less than s2;\n");
      printf("• a positive value if s1 is greater than s2.\n");
      char str2[10000];
      printf("Enter string to cpmpare with : ");
      scanf("\t%[^\n]c", str2);
      printf("Difference : %d \n \n", mystrcmp(str1, str2));
    }
  }
}
