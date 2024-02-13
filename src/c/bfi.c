/*
 * REFERENCE:
 * A Brainfuck program has a pointer that moves within an array
 * of 30000 bytes, initially all set to zero.  The pointer
 * initially points to the beginning of this array.  The language
 * has eight commands, each of which is represented as a single
 * character, and which can be expressed in terms of {C} as
 * follows:
 *
 * >   ==>    ++p;
 * <   ==>    --p;
 * +   ==>    ++*p;
 * -   ==>    --*p;
 * .   ==>    putchar(*p);
 * ,   ==>    *p = getchar();
 * [   ==>    while (*p) {
 * ]   ==>    }
 *
 * {Brian Raiter's Brainfuck page
 * (http://muppetlabs.com/~breadbox/bf/)}.
 */

#include <stdio.h>
#include <stdlib.h>

#define SLC "// "
#define RESERVED "><+-.,[]"
#define WHITESPACE " \t\r\n"
#define MEMSIZE 30000

int cpos(char c, const char *s) {
  for (int i = 0; s[i] != '\0'; i++)
    if (s[i] == c)
      return i;
  return -1;
}

void iterate(char c, char *p) {
switch (c) {
    case '>':
    fputs("++p;", ofile);
    break;
  case '<':
    fputs("--p;", ofile);
    break;
  case '+':
    fputs("++*p;", ofile);
    break;
  case '-':
    fputs("--*p;", ofile);
    break;
  case '.':
    fputs("putchar(*p);", ofile);
    break;
  case ',':
    fputs("*p = getchar();", ofile);
    break;
  case '[':
    fputs("while (*p) {", ofile);
    break;
  case ']':
    putc('}', ofile);
    break;
}

int bfinterpret(FILE *f) {
  char *p = (char*) malloc(MEMSIZE);
  char c;
  while ((c=getc(f)) != EOF) {
     iterate(c, p);
  }
  free(p);
  return 0;
}


void bf2c() {
  int c, ilevel = 1, iscom = 0;
  fputs(BOILERPLATE, ofile);
  while ((c = getc(ifile)) != EOF) {
    if (c == ']')
      ilevel--;
    switch (c) {
    case '>':
    fputs("++p;", ofile);
    break;
  case '<':
    fputs("--p;", ofile);
    break;
  case '+':
    fputs("++*p;", ofile);
    break;
  case '-':
    fputs("--*p;", ofile);
    break;
  case '.':
    fputs("putchar(*p);", ofile);
    break;
  case ',':
    fputs("*p = getchar();", ofile);
    break;
  case '[':
    fputs("while (*p) {", ofile);
    ilevel++;
    break;
  case ']':
    putc('}', ofile);
    break;

  int ostreams(const char *src, const char *target) {
    if (!strcmp(src, "-")) {
      ifile = stdin;
    } else if (!(ifile = fopen(src, "r"))) {
      fputs("Cannot read input file\n", stderr);
      return 1;
    }
    if (!strcmp(target, "-")) {
      ofile = stdout;
    } else if (!(ofile = fopen(target, "w+"))) {
      fputs("Cannot write to output file\n", stderr);
      return 1;
    }
    return 0;
  }

  int main(int argc, char **argv) {
    FILE *ifile;
    switch (argc) {
    case 1:
      ostreams("-", "-");
      break;
    case 2:
      if (ostreams(argv[1], "-"))
        return 1;
      break;
    default:
      fputs("Too many arguments", stderr);
      return 1;
    }
    return bfinterpret(f);
    return 0;
  }

