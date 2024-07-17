#include <bits/stdc++.h>

using namespace std;

void reverseArray(vector<int>& arr, int m) {
    // Write your code here
    int n = arr.size() - 1;
    m = m + 1;
    while (m < n) {
        int temp = arr[m];
        arr[m] = arr[n];
        arr[n] = temp;
        m++;
        n--;
    }
}

void testcase() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    reverseArray(arr, m);
    for (auto x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main(int argc, char const* argv[]) {
    int t;
    cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}
