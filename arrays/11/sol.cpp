#include <bits/stdc++.h>

using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m) {
    // code here
    int lstart = 0, rstart = 0, lend = n - 1;
    while (lstart <= lend && rstart < m) {
        if (arr1[lstart] < arr2[rstart]) {
            lstart++;
        } else {
            swap(arr1[lend], arr2[rstart]);
            lend--;
            rstart++;
        }
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

void testcase() {
    int n, m;
    cin >> n >> m;
    long long arr1[n];
    long long arr2[m];
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    merge(arr1, arr2, n, m);

    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    int t;
    cin >> t;
    while (t--) {
        testcase();
    }

    return 0;
}
