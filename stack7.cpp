#include <iostream>
#include <stack>
using namespace std;

int main() {
    unsigned long long n;
    cin >> n;

    const char digits[] = "0123456789ABCDEF";
    stack<int> remainders;

    while (n > 0) {
        remainders.push(n % 16);
        n /= 16;
    }

    while (!remainders.empty()) {
        cout << digits[remainders.top()];
        remainders.pop();
    }

    return 0;
}
