#include <stdio.h>

int main (){
    int a;
    int b;
    int yildiz=1;
    int bos =10;

    for(a=0;a<6;a++){

        for (b=0;b < bos;b++)
            printf(" ");
        for (b=0;b< yildiz;b++)
            printf("*");

        printf("\n");
        yildiz +=2;
        bos--;
    }
    return 0;
}


