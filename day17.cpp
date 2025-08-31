#include <iostream>
#include <vector>
using namespace std;

vector<int> primeFactorization(long long N) {
    vector<int> factors;
    while (N % 2 == 0) {
        factors.push_back(2);
        N /= 2;
    }

    for (long long i = 3; i * i <= N; i += 2) {
        while (N % i == 0) {
            factors.push_back((int)i);
            N /= i;
        }
    }

    if (N > 2) {
        factors.push_back((int)N);
    }

    return factors;
}

int main() {
    long long N;
    cin >> N;

    vector<int> result = primeFactorization(N);

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
