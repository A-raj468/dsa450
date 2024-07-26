#include <bits/stdc++.h>

using namespace std;

long long mergesort(long long* arr, int n) {
    if (n == 1) {
        return 0;
    }
    long long inversions = 0;
    int mid = n / 2;

    inversions += mergesort(arr, mid);
    inversions += mergesort(arr + mid, n - mid);

    vector<int> sorted;
    int i = 0, j = 0;
    while (i < mid && j < n - mid) {
        if (arr[i] <= arr[mid + j]) {
            sorted.push_back(arr[i]);
            i++;
        } else {
            sorted.push_back(arr[mid + j]);
            j++;
            inversions += (mid - i);
        }
    }
    for (; i < mid; i++) {
        sorted.push_back(arr[i]);
    }
    for (; j < n - mid; j++) {
        sorted.push_back(arr[mid + j]);
    }

    for (int i = 0; i < n; i++) {
        arr[i] = sorted[i];
    }

    return inversions;
}

long long getInversions(long long* arr, int n) {
    long long inversions = mergesort(arr, n);
    return inversions;
}

void testcase() {
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long res = getInversions(arr, n);
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
