#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];   
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int start[100], end[100];
    int count = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                start[count] = i;
                end[count] = j;
                count++;
            }
        }
    }

    if (count == 0) {
        cout << "No subarray with sum 0 found" << endl;
    } else {
        cout << "Zero sum subarrays:" << endl;
        for (int k = 0; k < count; k++) {
            cout << "(" << start[k] << ", " << end[k] << ")" << endl;
        }
    }

    return 0;
}
