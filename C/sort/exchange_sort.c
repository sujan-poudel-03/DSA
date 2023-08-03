#include <stdio.h>


void exchange_sort(int num[], int n) {
    // outer loop
    for (int i = 0; i < n - 1; i++) {
        // inner loop
        for (int j = i + 1; j < n; j++) {
            if (num[i] > num[j]) {
                // swap num[i] and num[j]
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
}
int main() {
    int num[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(num) / sizeof(num[0]);
    printf("Before Sorting");
    for(int i=0; i<n; i++){
        printf("%d ", num[i]);
    }
    printf("\n");
    exchange_sort(num, n);
    // print the sorted array
    printf("\n");
    printf("After Sorting");
    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");

    return 0;
}


