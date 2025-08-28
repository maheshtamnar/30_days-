#include <iostream>
using namespace std;

int countAtMostK(string &s, int k) {
    int n = s.size();
    int left = 0, ans = 0;
    int freq[26] = {0};   
    int distinct = 0;    

    for (int right = 0; right < n; right++) {
        if (freq[s[right] - 'a'] == 0) {
            distinct++;
        }
        freq[s[right] - 'a']++;

        while (distinct > k) {
            freq[s[left] - 'a']--;
            if (freq[s[left] - 'a'] == 0) {
                distinct--;
            }
            left++;
        }

        ans += (right - left + 1);
    }

    return ans;
}

int countExactlyK(string &s, int k) {
    if (k == 0) return 0;
    return countAtMostK(s, k) - countAtMostK(s, k - 1);
}

int main() {
    string s;
    int k;
    cin >> s >> k;

    cout << countExactlyK(s, k) << endl;
    return 0;
}
