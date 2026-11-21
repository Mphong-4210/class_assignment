#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<long long> st;
    st.push(0);

    for (int i = 0; i < (int)s.size(); ++i) {
        char c = s[i];

        if (c == '(') {
            st.push(0);
        } else if (c == ')') {
            long long groupMass = st.top();
            st.pop();

            long long multiplier = 0;
            while (i + 1 < (int)s.size() && isdigit(s[i + 1])) {
                multiplier = multiplier * 10 + (s[++i] - '0');
            }
            if (multiplier == 0) multiplier = 1;

            st.top() += groupMass * multiplier;
        } else {
            long long atomMass = (c == 'C' ? 12 : c == 'H' ? 1 : 16);
            long long count = 0;

            while (i + 1 < (int)s.size() && isdigit(s[i + 1])) {
                count = count * 10 + (s[++i] - '0');
            }
            if (count == 0) count = 1;

            st.top() += atomMass * count;
        }
    }

    cout << st.top();
    return 0;
}
