#include<stdio.h>
#include<math.h>

float average(float a[], int SIZE){
    float sum=0;

    for (int i = 0; i < SIZE; i++){
        sum += a[i];
    }
    return sum / SIZE;
}

float median(float a[], float avg, int SIZE){
    int med_index;
    float diff, mindiff=1000000;

    for (int i = 0; i < SIZE; i++){
        diff = fabs(a[i] - avg);
        if (diff < mindiff){
            mindiff = diff;
            med_index = i;
        }
    }

    return a[med_index];
}

int main(){
    const int SIZE = 15;
	float a[SIZE];

	// Get array from user input
	for (int i = 0; i < SIZE; i++){
        scanf("%f", &a[i]);
    }

    // Print the nearest number to average value
    printf("%f\n", median(a, average(a, SIZE), SIZE));
	return 0;
}
