#include <iostream>
using namespace std;

void mergeArrays(int arr1[], int arr2[], int m, int n) {
    for (int i = 0; i < m; i++) {
        if (arr1[i] > arr2[0]) {
            int temp = arr1[i];
            arr1[i] = arr2[0];
            arr2[0] = temp;

            
            int first = arr2[0];
            int j = 1;
            while (j < n && arr2[j] < first) {
                arr2[j - 1] = arr2[j];
                j++;
            }
            arr2[j - 1] = first;
        }
    }
}

int main() {
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    mergeArrays(arr1, arr2, m, n);

    cout << "arr1 = ";
    for (int i = 0; i < m; i++) cout << arr1[i] << " ";
    cout << "\narr2 = ";
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";
    cout << endl;

    return 0;
}
