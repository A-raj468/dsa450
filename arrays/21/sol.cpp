#include <bits/stdc++.h>

using namespace std;

string calculateFactorial(int n) {
    // Write your code here.
    string res = "1";
    for (int i = 1; i < n + 1; i++) {
        int carry = 0;
        for (char& c : res) {
            int d = c - '0';
            d = d * i + carry;
            carry = d / 10;
            d = d % 10;
            c = d + '0';
        }
        while (carry > 0) {
            res += to_string(carry % 10);
            carry = carry / 10;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

void testcase() {
    int n;
    cin >> n;

    string res = calculateFactorial(n);
    cout << res << endl;
}

int main(int argc, char* argv[]) {
    int t;
    cin >> t;
    while (t--) {
        testcase();
    }

    return 0;
}
