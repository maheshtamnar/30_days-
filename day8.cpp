#include <iostream>
#include <algorithm>
using namespace std;

string reverseWords(string s) {
    
    string word, result;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') word += s[i];
        else {
            if (!word.empty()) {
                if (!result.empty()) result = word + " " + result;
                else result = word;
                word.clear();
            }
        }
    }
    if (!word.empty()) {
        if (!result.empty()) result = word + " " + result;
        else result = word;
    }
    return result;
}

int main() {
    string s;
    getline(cin, s);
    cout << reverseWords(s) << endl;
    return 0;
}
