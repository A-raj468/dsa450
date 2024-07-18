#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int>& arr, int value) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == value) {
            return mid;
        }
        if (arr[mid] > value) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

pair<int, int> findSimilarity(vector<int> arr1,
                              vector<int> arr2,
                              int n,
                              int m) {
    // Write Your Code here.
    if (n < m) {
        vector<int> temp = arr1;
        arr1 = arr2;
        arr2 = temp;
    }
    sort(arr2.begin(), arr2.end());
    int countCommon = 0;
    for (int i = 0; i < arr1.size(); i++) {
        if (binarySearch(arr2, arr1[i]) != -1) {
            countCommon++;
        }
    }
    return pair<int, int>(countCommon, n + m - countCommon);
}

void testcase() {
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n), arr2(m);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    pair<int, int> res = findSimilarity(arr1, arr2, n, m);

    cout << res.first << " " << res.second << endl;
}

int main(int argc, char* argv[]) {
    int t;
    cin >> t;
    while (t--) {
        testcase();
    }

    return 0;
}
