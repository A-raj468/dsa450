#include <bits/stdc++.h>

using namespace std;

pair<int, int> minMax(int arr[], int start, int end) {
    if (end - start + 1 <= 0) {
        return pair<int, int>(-1, -1);
    }
    if (end - start + 1 == 1) {
        return pair<int, int>(arr[start], arr[start]);
    }
    if (end - start + 1 == 2) {
        int minVal = arr[start] < arr[end] ? arr[start] : arr[end];
        int maxVal = arr[start] < arr[end] ? arr[end] : arr[start];
        return pair<int, int>(minVal, maxVal);
    }

    int mid = start + (end - start) / 2;
    pair<int, int> left = minMax(arr, start, mid);
    pair<int, int> right = minMax(arr, mid + 1, end);
    int minVal = left.first < right.first ? left.first : right.first;
    int maxVal = left.second > right.second ? left.second : right.second;
    return pair<int, int>(minVal, maxVal);
}

int sumOfMaxMin(int arr[], int n) {
    // Write your code here.
    pair<int, int> minMaxVal = minMax(arr, 0, n - 1);

    return minMaxVal.first + minMaxVal.second;
}

void testcase() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int res = sumOfMaxMin(arr, n);
    cout << res << endl;
}

int main(int argc, char const* argv[]) {
    int t;
    cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}
