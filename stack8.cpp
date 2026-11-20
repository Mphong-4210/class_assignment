#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int n;
    string s;

    cin >> n >> s;

    stack<char> st;
    bool valid = true;

    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } else {
            if (st.empty()) {
                valid = false;
                break;
            }
            st.pop();
        }
    }

    if (!st.empty()) {
        valid = false;
    }

    cout << (valid ? "YES" : "NO");
    return 0;
}
