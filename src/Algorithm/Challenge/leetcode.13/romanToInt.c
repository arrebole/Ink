// 'I': 1   x
// 'V': 5   x
// 'X': 10
// 'L': 50
// 'C': 100
// 'D': 500
// 'M': 1000
// 'IV': 4  x
// 'IX': 9  x
// 'XL': 40
// 'XC': 90
// 'CD': 400
// 'CM': 900

#include <string.h>

int romanToInt(char* s) {
  int result = 0;
  int len = (int)strlen(s);
  for (int i = 0; i < len; i++) {
    switch (s[i]) {
      case 'I':
        if (i + 1 < len) {
          if (s[i + 1] == 'V') {
            result += 4;
            i++;
            break;
          }
          if (s[i + 1] == 'X') {
            result += 9;
            i++;
            break;
          }
        }
        result += 1;
        break;
      case 'V':
        result += 5;
        break;
      case 'X':
        if (i + 1 < len) {
          if (s[i + 1] == 'L') {
            result += 40;
            i++;
            break;
          }
          if (s[i + 1] == 'C') {
            result += 90;
            i++;
            break;
          }
        }
        result += 10;
        break;
      case 'L':
        result += 50;
        break;
      case 'C':
        if (i + 1 < len) {
          if (s[i + 1] == 'D') {
            result += 400;
            i++;
            break;
          }
          if (s[i + 1] == 'M') {
            result += 900;
            i++;
            break;
          }
        }
        result += 100;
        break;
      case 'D':
        result += 500;
        break;
      case 'M':
        result += 1000;
        break;
    }
  }
  return result;
}