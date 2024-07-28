#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int>& arr, int n) {
    // Write your code here.
    unordered_set<int> s(arr.begin(), arr.end());
    int len = INT32_MIN;
    for (int& x : arr) {
        if (s.find(x - 1) == s.end()) {
            int j = x;
            while (s.find(j) != s.end()) {
                j++;
            }
            len = max(len, j - x);
        }
    }
    return len;
}

void testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) {
        cin >> x;
    }
    int res = lengthOfLongestConsecutiveSequence(arr, n);
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
