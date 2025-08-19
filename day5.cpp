#include <iostream>
using namespace std;


int* findLeaders(int arr[], int n, int &leaderCount) {
    int* leaders = new int[n]; 
    leaderCount = 0;

    int max_right = arr[n - 1];
    leaders[leaderCount++] = max_right;  

   
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > max_right) {
            leaders[leaderCount++] = arr[i];
            max_right = arr[i];
        }
    }


    for (int i = 0; i < leaderCount / 2; i++) {
        int temp = leaders[i];
        leaders[i] = leaders[leaderCount - 1 - i];
        leaders[leaderCount - 1 - i] = temp;
    }

    return leaders;
}

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int leaderCount;
    int* leaders = findLeaders(arr, n, leaderCount);

    cout << "Leaders: ";
    for (int i = 0; i < leaderCount; i++) {
        cout << leaders[i] << " ";
    }

    return 0;
}
