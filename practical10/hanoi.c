/*******************************************************
 *                 Week 10 practical
 *                   Tower of hanoi
********************************************************/

#include <stdio.h>
#include <stdlib.h>

// define hanoi fucntion that recusively solves the hanoi puzzle
void hanoi(int n, int source , int dest, int midd) {
    if (n == 1) {
        printf("Moved disk %d from %d to %d\n", n, source, dest);
    }
    else{
        hanoi(n-1, source, midd, dest);
        printf("Moved disk %d from %d to %d\n", n, source, dest);
        hanoi(n-1, midd, dest, source);
    }
}

void main() {
    int h;
    printf("Enter number of disks: \n");
    scanf("%d", &h);
    printf("Tower of Hanoi soulution for %d disks: \n", h);
    hanoi(h, 1, 3, 2);
}