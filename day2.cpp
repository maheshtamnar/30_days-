#include <iostream>
using namespace std;

int findMissingNumber(int arr[], int n) {
    int totalSum = n * (n + 1) / 2;
    int arrSum = 0;
    for (int num =0;num<n;num++) {
        arrSum += num;
    }
    
    return totalSum - arrSum;
}

int main() {
    int arr[]={1,2,3,4};
    int n=sizeof(arr)/sizeof(int) + 1;
    cout << "Missing number is: " << findMissingNumber(arr, n) << endl;
    return 0;
}
