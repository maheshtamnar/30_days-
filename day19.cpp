#include <bits/stdc++.h>
using namespace std;

long long evaluatePostfix(const string &expr) {
    stack<long long> st;
    stringstream ss(expr);
    string token;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
            long long b = st.top(); st.pop();
            long long a = st.top(); st.pop();

            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else if (token == "/") {
                if (b == 0) throw runtime_error("Division by zero");
                st.push(a / b); 
            }
            else if (token == "^") {
                
                st.push((long long)pow(a, b));
            }
        }
        else {
            
            st.push(stoll(token));
        }
    }

    return (st.empty() ? 0 : st.top());
}

int main() {
    string expr;
    getline(cin, expr); 
    cout << evaluatePostfix(expr) << endl;
    return 0;
}
