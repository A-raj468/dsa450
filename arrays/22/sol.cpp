#include <bits/stdc++.h>

using namespace std;

int maximumProduct(vector<int>& arr, int n) {
    // Write your code here
    int maxProd = arr[0];
    int maxEnd = arr[0];
    int minEnd = arr[0];

    for (int i = 1; i < n; i++) {
        int temp = max({arr[i], arr[i] * maxEnd, arr[i] * minEnd});
        minEnd = min({arr[i], arr[i] * maxEnd, arr[i] * minEnd});
        maxEnd = temp;
        maxProd = max(maxProd, maxEnd);
    }

    return maxProd;
}

void testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) {
        cin >> x;
    }

    int res = maximumProduct(arr, n);
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
