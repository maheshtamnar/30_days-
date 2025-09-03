#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int>& st, int x) {
    if (st.empty() || st.top() <= x) {
        st.push(x);
        return;
    }

    int temp = st.top();
    st.pop();
    insertSorted(st, x);

    st.push(temp);
}

void sortStack(stack<int>& st) {
    if (!st.empty()) {
        int x = st.top();
        st.pop();

        sortStack(st);

        insertSorted(st, x);
    }
}

void printStack(stack<int> st) {
    stack<int> temp;
    while (!st.empty()) {
        temp.push(st.top());
        st.pop();
    }
    
    cout << "[";
    while (!temp.empty()) {
        cout << temp.top();
        temp.pop();
        if (!temp.empty()) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    stack<int> st;

    int arr[] = {3, 1, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        st.push(arr[i]);
    }

    cout << "Original Stack: ";
    printStack(st);

    sortStack(st);

    cout << "Sorted Stack: ";
    printStack(st);

    return 0;
}
