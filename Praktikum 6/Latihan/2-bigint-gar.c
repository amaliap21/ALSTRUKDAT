/* File : bigint.c */
/* Definisi ADT Stack dengan representasi array secara eksplisit dan alokasi statik */
/* TOP adalah alamat elemen puncak */
// Muhammad Garebaldhie ER Rahman
// 13520029
// 16 Oktober 2021
// praktikum 8
// Stack

#include <stdio.h>
#include "stack.c"
#include <string.h>

int main()
{
  int n1, n2;
  char s1[105];
  char s2[105];
  scanf("%s", s1);
  scanf("%s", s2);
  Stack a1, a2, a3;
  CreateEmpty(&a1);
  CreateEmpty(&a2);
  CreateEmpty(&a3);
  for (int i = 0; i < strlen(s1); i++)
  {
    Push(&a1, s1[i]);
  }
  for (int i = 0; i < strlen(s2); i++)
  {
    Push(&a2, s2[i]);
  }
  int sisa = 0;

  if (strlen(s1) <= strlen(s2))
  {
    while (!IsEmpty(a1))
    {
      Pop(&a1, &n1);
      Pop(&a2, &n2);
      n1 -= 48;
      n2 -= 48;
      if (n1 < 0 || n2 < 0)
        continue;
      int total = n1 + n2 + sisa;
      sisa = total / 10;
      total = total % 10;
      Push(&a3, total);
    }
    n2 = 0;
    while (!IsEmpty(a2))
    {
      int total = 0;
      Pop(&a2, &n2);
      n2 -= 48;
      n2 += sisa;
      total = n2 % 10;
      sisa = n2 / 10;
      Push(&a3, total);
    }
    if (sisa != 0 && strlen(s1) == strlen(s2))
    {
      printf("%d", sisa);
    }
    while (!IsEmpty(a3))
    {
      Pop(&a3, &n1);
      printf("%d", n1);
    }
    printf("\n");
  }
  else
  {
    int sisa = 0;
    while (!IsEmpty(a2))
    {
      Pop(&a1, &n1);
      Pop(&a2, &n2);
      n1 -= 48;
      n2 -= 48;
      if (n1 < 0 || n2 < 0)
        continue;
      int total = n1 + n2 + sisa;
      sisa = total / 10;
      total = total % 10;
      Push(&a3, total);
    }
    n2 = 0;
    while (!IsEmpty(a1))
    {
      int total = 0;
      Pop(&a1, &n2);
      n2 -= 48;
      n2 += sisa;
      total = n2 % 10;
      sisa = n2 / 10;
      Push(&a3, total);
    }
    while (!IsEmpty(a3))
    {
      Pop(&a3, &n1);
      printf("%d", n1);
    }
    printf("\n");
  }
}