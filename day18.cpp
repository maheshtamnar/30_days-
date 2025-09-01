#include <iostream>
using namespace std;

int countDivisors(long long n) {
    int count = 0;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i == n / i)
                count++;
            else
                count += 2;
        }
    }
    return count;
}

int main() {
    long long N;
    cin >> N;
    cout << countDivisors(N) << endl;
    return 0;
}
