#include <iostream>
#include <stack>
using namespace std;

int main() {
    unsigned long long n;
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    stack<int> digits;
    while (n > 0) {
        digits.push(n % 8);
        n /= 8;
    }

    while (!digits.empty()) {
        cout << digits.top();
        digits.pop();
    }

    return 0;
}
