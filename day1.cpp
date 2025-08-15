#include <iostream>
#include <vector>
using namespace std;

void sort012(vector<int> &arr) {
    int low = 0, mid = 0;
    int high = arr.size() - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    vector<int> arr = {2, 0, 1, 2, 1, 0, 0, 2};
    sort012(arr);

    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}
