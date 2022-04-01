#include<stdio.h>

void split(double num, int *integer, double *fraction){
    *integer = (int) num;
    *fraction = num - *integer;
}

int main(){
    double num, fraction;
    int integer;

    // get input
    printf("Please enter a real number: ");
    scanf("%lf", &num);

    split(num, &integer, &fraction);
    printf("The integer part is %d\n", integer);
    printf("The remaining fraction part is %lf\n", fraction);

    return 0;
}
