#include <iostream>
#include <vector>
#include <string>
using namespace std;


bool isAnagram(string a, string b) {
    if (a.size() != b.size()) return false;
    vector<int> count(26, 0);
    for (char c : a) count[c - 'a']++;
    for (char c : b) {
        count[c - 'a']--;
        if (count[c - 'a'] < 0) return false;
    }
    return true;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size();
    vector<bool> visited(n, false);
    vector<vector<string>> result;

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        vector<string> group;
        group.push_back(strs[i]);
        visited[i] = true;

        for (int j = i + 1; j < n; j++) {
            if (!visited[j] && isAnagram(strs[i], strs[j])) {
                group.push_back(strs[j]);
                visited[j] = true;
            }
        }

        result.push_back(group);
    }
    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> groups = groupAnagrams(strs);


    for (auto& group : groups) {
        cout << "[ ";
        for (auto& word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }

    return 0;
}
