#include <stdio.h>
#include <stdlib.h>

#define MAX_GAKUSEI 2000
#define MAX_KAMOKU 400

/* データの定義 */

struct SEISEKI {
  struct SEISEKI *glink;
  struct SEISEKI *klink;
  struct GAKUSEI *gakusei;
  struct KAMOKU *kamoku;
  short seiseki;
};

struct GAKUSEI {
  struct SEISEKI *glink;
  char *name;
} gakusei[MAX_GAKUSEI];

struct KAMOKU {
  struct SEISEKI *klink;
  char *name;
} kamoku[MAX_KAMOKU];

/* 初期化 */
void initialize() {
  int i;

  for(i = 0; i < MAX_GAKUSEI; i++) {
    gakusei[i].glink = NULL;
  }
  for (i = 0; i < MAX_KAMOKU; i++) {
    kamoku[i].klink = NULL;
  }
}

/* 成績を設定 */

void add(int x, int y, short data) {
  struct SEISEKI *p;

  if ((p = malloc(sizeof(struct SEISEKI))) == NULL) {
    printf("メモリが足りません");
    exit(1);
  }

  p->glink = gakusei[x].glink;
  gakusei[x].glink = p;
  p->klink = kamoku[y].klink;
  kamoku[y].klink = p;
  p->gakusei = &gakusei[x];
  p->kamoku = &kamoku[y];
  p->seiseki = data;
}

/* 成績を取得 */

short get_seiseki(int x, int y) {
  struct SEISEKI *p;
  for(p = gakusei[x].glink; p != NULL; p = p->glink) {
    if (p->kamoku == &kamoku[y]) {
      return (p->seiseki);
    }
  }
  return -1;
}

/* 成績の情報をプリント */

void print_gakusei(int x) {
  struct SEISEKI *p;

  for (p = kamoku[x].klink; p != NULL; p = p->klink) {
    printf("%s %d\n", p->gakusei->name, p->seiseki);
  }
}

void set_kamoku(int n, char *s) {
  kamoku[n].name = s;
}

void set_gakusei(int n, char *s) {
  gakusei[n].name = s;
}

void main() {
  int x = 0;
  int y = 0;
  short data = 100;

  initialize();
  set_kamoku(0, "kokugo");
  set_kamoku(1, "sansu");
  set_kamoku(2, "rika");
  set_kamoku(3, "syakai");
  set_kamoku(4, "dotoku");
  set_kamoku(5, "hokkaido");

  set_gakusei(0, "tanaka taro");
  set_gakusei(1, "tanaka taroko");
  set_gakusei(2, "yamada taro");
  set_gakusei(3, "yamada taroko");
  set_gakusei(4, "yokozawa taro");
  set_gakusei(5, "yokozawa natsuko");

  // tanaka taro seiseki
  add(0, 0, 100);
  add(0, 1, 100);
  add(0, 2, 100);
  add(0, 3, 100);
  add(0, 4, 100);
  add(0, 5, 100);

  add(1, 0, 100);
  add(1, 1, 80);
  add(1, 2, 92);
  add(1, 3, 44);
  add(1, 4, 13);
  add(1, 5, 66);

  add(2, 0, 66);
  add(2, 1, 33);
  add(2, 2, 55);
  add(2, 3, 24);
  add(2, 4, 55);
  add(2, 5, 22);

  short num = get_seiseki(0, 0);
  printf("%ld \n", num);

  print_gakusei(0);
  /* print_gakusei(1); */
  /* print_gakusei(2); */
}
