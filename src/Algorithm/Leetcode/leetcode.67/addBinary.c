#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
  int lenA = strlen(a), lenB = strlen(b);
  char* result = NULL;
  if (lenA == 0) return b;
  if (lenB == 0) return a;

  // 将数组对齐
  if (lenA > lenB) {
    int value = lenA - lenB;
    char* nb = (char*)calloc(lenA+2, sizeof(char));
    for (int i = 0; i < value; i++) nb[i] = '0';
    for (int i = value; i < lenA; i++) nb[i] = b[i - value];
    b = nb; result = nb;

  } else if (lenA <= lenB) {
    int value = lenB - lenA;
    char* na = (char*)calloc(lenB+2, sizeof(char));
    for (int i = 0; i < value; i++) na[i] = '0';
    for (int i = value; i < lenB; i++) na[i] = a[i - value];
    a = na; result = na;
  }

  int carry = 0;
  for (int i = strlen(a) - 1; i >= 0; i--) {
    int num = carry + (a[i] - '0') + (b[i] - '0');
    if (num == 2) {
      carry = 1;
      result[i] = '0';
    } else if (num == 3) {
      carry = 1;
      result[i] = '1';
    } else {
      carry = 0;
      result[i] = '0' + num;
    }
  }

  if (carry) {
    int len = lenA > lenB?lenA:lenB;
    for(int i = len; i > 0;i--) result[i] = result[i-1];
    result[0] = '1';
  }
  return result;
}