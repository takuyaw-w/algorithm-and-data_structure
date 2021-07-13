/*
 * stack.c 配列でスタックを実現する
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef long ELEM; /* スタックの要素の型 */

#define STACK_SIZE 100

ELEM stack[STACK_SIZE]; /* スタックの定義 */
int n; /* スタックのポインタ */

void printError(char *s) {
  fprintf(stderr, s);
  exit(1);
}

void initialize() {
  n = 0;
}

void push(ELEM x) {
  if (n >= STACK_SIZE) {
    printError("stack overflow\n");
  }
  stack[n++] = x;
}

ELEM pop() {
  if (n <= 0) {
    printError("stack underflow\n");
  }
  return stack[--n];
}

int empty() {
  return n == 0;
}

/**************** 逆ポーランド計算機 *************/

void main() {
  int c;
  long x, a, b;

  initialize();

  while ((c = getchar()) != EOF) {
    if (isdigit(c)) {
      ungetc(c, stdin);
      scanf("%ld", &x);
      push(x);
    } else {
      switch (c) {
        case '+':
          b = pop();
          a = pop();
          push(a + b);
          break;
        case '-':
          b = pop();
          a = pop();
          push(a - b);
          break;
        case '*':
          b = pop();
          a = pop();
          push(a * b);
          break;
        case '/':
          b = pop();
          a = pop();
          push(a / b);
          break;
        case '\n':
          if (!empty()) {
            printf("result: %ld\n", pop());
          }
          initialize();
          break;
        case ' ':
        case '\t':
          break;
        default:
          printf("invalid data.");
          while ((c = getchar()) != EOF && c != '\n');
          break;
      }
    }
  }
}
