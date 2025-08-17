#include <iostream>
#include <vector>
using namespace std;

int findMissing(vector<int>& arr, int n) {
    int xor1 = 0, xor2 = 0;
    for (int i = 1; i <= n; i++) {
        xor1 ^= i;
    }
    for (int num : arr) {
        xor2 ^= num;
    }
    return xor1 ^ xor2;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> arr(n - 1);
    cout << "Enter " << n - 1 << " numbers: ";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    cout << "Missing number is: " << findMissing(arr, n) << endl;
    return 0;
}
