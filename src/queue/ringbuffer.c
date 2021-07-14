#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef long ELEM; /* 要素の型 */

#define QUEUE_SIZE 100 /* リングバッファの大きさ */

ELEM queue[QUEUE_SIZE];
int front; // 先頭
int rear; // 末尾

#define next(a) (((a) + 1) % QUEUE_SIZE) // 次の要素のインデックスを求める

void printError(char *s) {
  fprintf(stderr, s);
  exit(1);
}

void init() {
  front = 0;
  rear = 0;
}

void enqueue(ELEM x) {
  if (next(rear) == front) {
    printError("full!\n");
  }

  queue[rear] = x;
  rear = next(rear);
}

ELEM dequeue() {
  ELEM x;

  if (front == rear) {
    printError("empty...\n");
  }

  x = queue[front];
  front = next(front);
  return x;
}

int empty() {
  return front == rear;
}

void main() {
  long num1, num2, num3, num4, num5, num6, num7, num8, num9;

  init();
  enqueue(5);
  enqueue(8);
  enqueue(3);
  enqueue(10);
  enqueue(8);
  enqueue(6);
  enqueue(7);
  enqueue(24);
  enqueue(11);
  num1 = dequeue();
  num2 = dequeue();
  num3 = dequeue();
  num4 = dequeue();
  num5 = dequeue();
  num6 = dequeue();
  num7 = dequeue();
  num8 = dequeue();
  num9 = dequeue();
  printf("num1: %ld\n", num1);
  printf("num2: %ld\n", num2);
  printf("num3: %ld\n", num3);
  printf("num4: %ld\n", num4);
  printf("num5: %ld\n", num5);
  printf("num6: %ld\n", num6);
  printf("num7: %ld\n", num7);
  printf("num8: %ld\n", num8);
  printf("num9: %ld\n", num9);
}
