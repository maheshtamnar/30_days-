#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char ch : s) {
        
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
       
        else {
            if (st.empty()) return false; 

            char top = st.top();
            st.pop();

            // Check matching pair
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

   
    return st.empty();
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    if (isValid(s))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
