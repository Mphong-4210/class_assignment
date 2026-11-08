#include <iostream>
#include <set>
#include <fstream>

using namespace std;

int main() {
    // Tối ưu hóa tốc độ nhập/xuất file
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("SEQ.INP", "r", stdin);
    freopen("SEQ.OUT", "w", stdout);

    int n;
    if (!(cin >> n)) return 0;

    multiset<int> s;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        s.insert(val);
    }

    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            s.insert(x);
        } 
        else if (type == 2) {
            int x;
            cin >> x;
            s.erase(x); // Xóa tất cả các phần tử có giá trị bằng x trong multiset
        } 
        else if (type == 3) {
            int x;
            cin >> x;
            auto it = s.upper_bound(x); // Tìm số nhỏ nhất lớn hơn x
            if (it == s.end()) {
                cout << "No\n";
            } else {
                cout << *it << "\n";
            }
        } 
        else if (type == 4) {
            int x;
            cin >> x;
            auto it = s.lower_bound(x); // Tìm vị trí đầu tiên >= x
            if (it == s.begin()) {
                cout << "No\n"; // Không có số nào nhỏ hơn x
            } else {
                --it; // Lùi lại để lấy số lớn nhất nhỏ hơn x
                cout << *it << "\n";
            }
        } 
        else if (type == 5) {
            if (s.empty()) {
                cout << "No\n";
            } else {
                int min_val = *s.begin();
                int max_val = *s.rbegin();
                cout << min_val << " " << max_val << "\n";
            }
        }
    }

    return 0;
}
