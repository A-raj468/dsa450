#include <bits/stdc++.h>

using namespace std;

long long maxSubarraySum(vector<int>& arr) {
    // code here...
    long long currSum = INT32_MIN;
    long long endSum = INT32_MIN;
    for (long long x : arr) {
        endSum = max(endSum + x, x);
        currSum = max(currSum, endSum);
    }
    return currSum;
}

void testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long res = maxSubarraySum(arr);
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
