#include <stdio.h>
#include "queue.h"

int main()
{
    int menu, time, val;
    int terlayani = 0;
    int maxtime = -999, mintime = 999;
    float sumTime = 0;
    int flag = 1;

    Queue q;
    CreateQueue(&q);

    while (flag)
    {
        scanf("%d", &menu);
        if (menu == 1)
        {
            scanf("%d", &time);
            // kalo penuh -> print queue penuh

            // kalo ga penuh
            enqueue(&q, time);
        }
        else if (menu == 2)
        {
            sumTime += HEAD(q);
            if (HEAD(q) > maxtime)
            {
                maxtime = HEAD(q);
            }
            if (HEAD(q) < mintime)
            {
                mintime = HEAD(q);
            }
            terlayani++;
            dequeue(&q, &val);
        }
        else if (menu == 0)
        {
            flag = 0;
        }
    }
    printf("%d\n", terlayani);

    if (terlayani > 0)
    {
        printf("%d\n", mintime);
        printf("%d\n", maxtime);
        printf("%.2f\n", sumTime / terlayani);
    }
    else
    {
        printf("Tidak bisa dihitung\n");
        printf("Tidak bisa dihitung\n");
        printf("Tidak bisa dihitung\n");
    }
    return 0;
}