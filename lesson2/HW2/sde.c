#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
    float a, b, c, delta;

    if (argc != 4){
        printf("Wrong number of argument!\n");
        printf("The correct syntax is: sde a b c\n");
    } else {
        printf("Solving the equation: %sx^2 + %sx + %s = 0\n", argv[1], argv[2], argv[3]);

        // Convert string arguments to numbers
        a = atof(argv[1]);
        b = atof(argv[2]);
        c = atof(argv[3]);

        // Solve the equation
        if (a == 0){
            // Linear equation
            if (b == 0){
                if (c == 0){
                    printf("Equation has infinite many solutions.\n");
                } else {
                    printf("Equation has no solution.\n");
                }
            } else {
                printf("Equation has 1 root: x = %.2f\n", -c/b);
            }
        } else {
            // Quadratic equation
            delta = b*b - 4*a*c;

            if (delta < 0){
                printf("Equation has no solution.\n");
            } else if (delta == 0){
                printf("Equation has a double root: x1 = x2 = %.2f\n", -b/(2*a));
            } else {
                float x1 = (-b - sqrt(delta)) / (2*a);
                float x2 = (-b + sqrt(delta)) / (2*a);
                printf("Equation has 2 distinct root: x1 = %.2f,\tx2 = %.2f\n", x1, x2);
            }
        }
    }
    return 0;
}
