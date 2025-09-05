#include <iostream>
using namespace std;

int firstElementKTimes(int arr[], int n, int k) {
    
    const int SIZE = 100000; 
    int freqPos[SIZE] = {0};
    int freqNeg[SIZE] = {0};

    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0 && arr[i] < SIZE) {
            freqPos[arr[i]]++;
        } else if (arr[i] < 0 && -arr[i] < SIZE) {
            freqNeg[-arr[i]]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0 && arr[i] < SIZE) {
            if (freqPos[arr[i]] == k) return arr[i];
        } else if (arr[i] < 0 && -arr[i] < SIZE) {
            if (freqNeg[-arr[i]] == k) return arr[i];
        }
    }

    return -1;
}

int main() {
    int arr1[] = {3, 1, 4, 4, 5, 2, 6, 1, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << firstElementKTimes(arr1, n1, 2) << endl; 
    return 0;
}
