#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int val) {
    if (st.empty()) {
        st.push(val);
        return;
    }

    int top = st.top();
    st.pop();

    insertAtBottom(st, val);

    st.push(top);
}

void reverseStack(stack<int> &st) {
    if (st.empty()) return;

    int top = st.top();
    st.pop();

    reverseStack(st);

    insertAtBottom(st, top);
}

void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}


int main() {
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Original Stack (top to bottom): ";
    printStack(st);

    
    reverseStack(st);

    cout << "Reversed Stack (top to bottom): ";
    printStack(st);

    return 0;
}
