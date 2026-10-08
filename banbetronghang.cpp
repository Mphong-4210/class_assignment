#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n + 1);
    vector<long long> kq(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    map<long long, vector<int>> pos;
    for (int i = 1; i <= n; i++)
        pos[a[i]].push_back(i);
    vector<int> st;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && a[st.back()] <= a[i])
            st.pop_back();

        int p = 0;

        if (!st.empty())
            p = st.back();
        auto &v = pos[a[i]];

        int left = lower_bound(v.begin(), v.end(), p + 1) - v.begin();
        int right = lower_bound(v.begin(), v.end(), i) - v.begin();

        kq[i] += right - left;

        st.push_back(i);
    }
    st.clear();
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && a[st.back()] <= a[i])
            st.pop_back();

        int p = 2*n + 1;

        if (!st.empty())
            p = st.back();

        auto &v = pos[a[i]];

        int left = upper_bound(v.begin(), v.end(), i) - v.begin();
        int right = lower_bound(v.begin(), v.end(), p) - v.begin();

        kq[i] += right - left;

        st.push_back(i);
    }

    for (int i = 1; i <= n; i++)
        cout << kq[i] << ' ';

    return 0;
}
