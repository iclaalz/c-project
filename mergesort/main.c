#include <stdio.h>
/*
 *            79862453
 *           / divide \           divide -> d
 *       7986          2453        merge -> m
 *      /  d \        /  d \
 *     79    86      24     53
 *    /d\   /d\     /d\     /d\
 *   7  9   8 6     2  4    5 3
 *   \m/    \m/     \m/     \m/
 *    79    68       24      35
 *     \ m  /         \   m  /
 *      6789            2345
 *         \    merge   /
 *            23456789
 */




int buf[100];

int merge(int* a,int first,int mid,int last ) {

    printf("merge [%d:%d:%d]\n",first,mid,last);

    printf("unsorted: \n");        //sırasız bölünmüş hali
    for (int b=first; b <= last; ++b)
    {
        printf("%d",a[b]);
    }
printf("\n");
    int first1 =first; //ilk yarımın birincisi first1
    int last1 = mid;  //ilk yarımın sonuncusu mid
    int first2 = mid+1;  //ikinci yarımın birincisi
    int last2 = last; //ikinci yarımın son
    int index ;

   for(index =0; first1 <= last1 && first2 <= last2;) { //kural olarak sıralı olması için
       //küçük olanı bulmaya çalışıyorum
       if (a[first1] < a[first2])

           buf[index++] = a[first1++];

       else                                   //küçük olanları bulmaya çalışarak ilerliyor
           buf[index++] = a[first2++];

   }
       for(int b=first1; b<= last1 ; b++)  buf[index++] = a[b];   /* ilk fordan çıkınca  kaldığı yeri f1 sayıyo
 *                                                            oradan sonra kalanları kopyalıyor kısmı */

       for (int b=first2 ; b <=last2 ; b++) buf [index++]= a[b];

       for (int b=0 ; b <index; b++) {
           a[first + b] = buf[b];
       }
       printf("sorted :  \n");    //sıralı hali
       for (int b=first ; b <=last ; ++b) {
           printf("%d",a[b]);
       }
       printf("\n****************************");
       printf("\n");

       return 0;
}


int mergesort (int* a, int first, int last){

    for (int b=first; b <= last; b++)  printf("%d", a[b]);
        printf("\n");

    if(first >= last){  //base case
        return 0; }

   int mid = (first+last)/2;  //mid ı bulmak için
   mergesort(a, first,mid);  // ikiye ayrılan da ilk kısım
   mergesort(a,mid+1,last);   //ikiye ayrılanda ikinci kısı

   //mergesort(a,first,last);
   return merge(a ,first ,mid,last );
}

int main() {

    int array[] = {7,9,8,6,2,4,5,3};

    mergesort(array ,0,7);

    for(int b=0 ;b<8 ;b++)
    {
        printf("%d",array[b]);
    }

    printf("\n");
    return 0;
}

