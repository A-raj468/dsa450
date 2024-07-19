#include <bits/stdc++.h>

using namespace std;

int minimizeIt(vector<int> A, int K) {
    // Write your code here.
    sort(A.begin(), A.end());
    int n = A.size();
    int minDiff = A[n - 1] - A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] - K < 0) {
            continue;
        }
        int minVal = min(A[0] + K, A[i] - K);
        int maxVal = max(A[i - 1] + K, A[n - 1] - K);
        int diff = abs(minVal - maxVal);
        minDiff = min(minDiff, diff);
    }
    return minDiff;
}

void testcase() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int res = minimizeIt(arr, k);
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
