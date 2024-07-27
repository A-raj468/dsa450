#include <bits/stdc++.h>

using namespace std;

bool subsetSumToK(int n, int k, vector<int>& arr) {
    // Write your code here.
    vector<bool> prev(k, false), curr(k);
    prev[0] = true;

    for (int& x : arr) {
        for (int i = 0; i <= k; i++) {
            curr[i] = curr[i] || prev[i];
            if (prev[i]) {
                if (i + x == k) {
                    return true;
                }
                if (i + x < k) {
                    curr[i + x] = true;
                }
            }
        }
        prev = curr;
    }
    return false;
}

void testcase() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int& x : arr) {
        cin >> x;
    }
    bool res = subsetSumToK(n, k, arr);
    cout << (res ? "YES" : "NO") << endl;
}

int main(int argc, char* argv[]) {
    int t;
    cin >> t;
    while (t--) {
        testcase();
    }

    return 0;
}
