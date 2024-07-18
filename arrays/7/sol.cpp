#include <bits/stdc++.h>

using namespace std;

long long maxSubarraySum(vector<int> arr, int n) {
    // Write your code here.
    long long currMax = max(arr[0], 0);
    long long endSum = arr[0];
    for (int i = 1; i < n; i++) {
        endSum = endSum < 0 ? arr[i] : endSum + arr[i];
        currMax = max(currMax, endSum);
    }
    return currMax;
}

void testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long res = maxSubarraySum(arr, n);
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
