#include <stdio.h>

int main(int argc, char *argv[]) {
  char *s = "\x12\x01\x00^\x00\x00\x01\x00\x00\x00$\x00\x06\x01\x00*\x00\x01\x02\x00+\x00\x01\x03\x00,\x00\x04\x04\x000\x00\x01\x05\x001\x00$\x06\x00U\x00\x01\xFF\x04\x07\x0C\xBC\x00\x00\x00\x00\x00\x00\x15\xD0\x00\x80\xF5\x81\xC3\x03\x00\x00\x00xSj\xB1\xF7\x7F\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFE\xFF\xFF\xFF\x01";
  printf("ab - %s\n", "\x12\x01\x00");
  return 0;
}
