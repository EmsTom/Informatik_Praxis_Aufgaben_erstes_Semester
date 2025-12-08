#include <stdio.h>



int x=1, y=2;


int main(void)
{
    y -= (x++)+2;
    x -= --y;
    x = ++x+y--;
    printf("x: %d und y: %d\n", x, y);
    return 0;
}