#include<stdio.h>
#include<string.h>

void towers(int num, char frompeg, char topeg, char auxpeg){
    if (num == 1){
        printf("Move disk 1 from %c to %c\n", frompeg, topeg);
        return;
    }

    // move first (n-1) disks (above) to AUX
    towers(num-1, frompeg, auxpeg, topeg);

    // move the nth disk to TO
    printf("Move disk %d from %c to %c\n", num, frompeg, topeg);

    // move (n-1) disks from AUX to TO
    towers(num-1, auxpeg, topeg, frompeg);
}

int main(){
    int num;

    printf("Enter the number of disks: "); scanf("%d", &num);
    printf("The sequence of moves involved in the Tower of Hanoi are:\n");

    // idea: disk number 1, 2, 3... n from top to bottom
    // each function call will do 3 steps:
    // - move first (n-1) disks to AUX
    // - move last disk number n to TO
    // - move (n-1) disks from AUX to TO
    towers(num, 'A', 'B', 'C');

    return 0;
}
