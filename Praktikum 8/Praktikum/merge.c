#include <stdio.h>
#include "listlinier.h"
#include "merge.h"

void splitList(List source, List* front, List* back)
/* Fungsi untuk memecah sebuah list dengan head source menjadi dua buah 
   list baru, yaitu front dan back. Apabila panjang list ganjil, maka
   list front akan lebih panjang dibandingkan list back.
   Sebagai contoh untuk list dengan panjang 5, maka list front memiliki
   3 elemen dan list back memiliki 2 elemen.
*/
{
    int len = length(source)/2;
    int ctr = 0;
    if (length(source) % 2 != 0)
    {
        len++;
    }
    Address p = FIRST(source);
    while (p != NULL)
    {
        if(ctr < len)
        {
            insertLast(front,INFO(p));
        } else
        {
            insertLast(back,INFO(p));
        }
        ctr++;
        p = NEXT(p);
    }
    
}
List merge(List a, List b)
/* Fungsi untuk melakukan merge sort list a dan b secara rekursif.
   Sort dilakukan secara ascending berdasarkan nilai elemen.
   Apabila List a = NULL, maka kembalikan List b
   Apabila List b = NULL, maka kembalikan List a
   Selain itu, lakukan perbandingan antara INFO(a) dengan 
   INFO(b) untuk mendapatkan urutannya
*/
{   List res;
    CreateList(&res);
    Address p,q;
    p = FIRST(a);
    q= FIRST(b);
    while (p != NULL && q != NULL)
    {
        if (INFO(p) <= INFO(q))
        {
            insertLast(&res,INFO(p));
            p = NEXT(p);
        } else
        {
            insertLast(&res,INFO(q));
            q = NEXT(q);
        }
    }
    while (p != NULL)
    {
        
        insertLast(&res,INFO(p));
        p = NEXT(p);
    }
    while ( q != NULL)
    {
        insertLast(&res,INFO(q));
        q = NEXT(q);
    }
    
    return res;
}
void mergeSort(List* list)
/* Fungsi untuk melakukan inisialisasi merge sort secara rekursif.
   Setiap kali fungsi dipanggil, maka tampilkan list yang sekarang
   sedang diproses.
   Apabila head atau NEXT(head) kosong, maka lakukan return
   Fungsi akan membagi list menjadi dua terlebih dahulu, kemudian 
   secara rekursif melakukan merge untuk mengurutkan
*/
{
    displayList(*list);
    printf("\n");
    if (isEmpty(*list) || NEXT(FIRST(*list))== NULL)
    {
        return;
    }

    List front,back;
    CreateList(&front);
    CreateList(&back);
    splitList(*list,&front,&back);

    mergeSort(&front);
    mergeSort(&back);

    *list = merge(front,back);
    
}