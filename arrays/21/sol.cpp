#include <bits/stdc++.h>

using namespace std;

string add(string a, string b) {
    int n = a.length();
    int m = b.length();
    int i = n - 1, j = m - 1;
    string res = "";
    int carry = 0;
    while (i >= 0 && j >= 0) {
        int add = carry + a[i--] - '0' + b[j--] - '0';
        carry = add / 10;
        add = add % 10;
        res = to_string(add) + res;
    }
    while (i >= 0) {
        int add = carry + a[i--] - '0';
        carry = add / 10;
        add = add % 10;
        res = to_string(add) + res;
    }
    while (j >= 0) {
        int add = carry + b[j--] - '0';
        carry = add / 10;
        add = add % 10;
        res = to_string(add) + res;
    }
    while (carry > 0) {
        int add = carry;
        carry = add / 10;
        add = add % 10;
        res = to_string(add) + res;
    }
    return res;
}

string multiply(string a, string b) {
    if (b.length() == 0) {
        return "";
    }

    if (b.length() == 1) {
        string res = "";
        int d = b[0] - '0';
        int carry = 0;
        for (int i = a.length() - 1; i >= 0; i--) {
            char c = a[i];
            int k = c - '0';
            int mul = k * d + carry;
            carry = mul / 10;
            mul = mul % 10;
            res = to_string(mul) + res;
        }
        if (carry > 0) {
            res = to_string(carry) + res;
        }

        return res;
    }

    string res = "";
    int d = b[b.length() - 1] - '0';
    int carry = 0;
    for (int i = a.length() - 1; i >= 0; i--) {
        char c = a[i];
        int k = c - '0';
        int mul = k * d + carry;
        carry = mul / 10;
        mul = mul % 10;
        res = to_string(mul) + res;
    }
    if (carry > 0) {
        res = to_string(carry) + res;
    }

    string left = multiply(a, b.substr(0, b.length() - 1));

    res = add(res, left + "0");

    return res;
}

string calculateFactorial(int n) {
    //    Write your code here.
    string res = "1";
    for (int i = 1; i < n + 1; i++) {
        res = multiply(res, to_string(i));
    }
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
