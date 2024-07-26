#include <bits/stdc++.h>

using namespace std;

int pairSum(vector<int>& arr, int n, int target) {
    // Write your code here.
    int count = 0;
    int i = 0, j = n - 1;
    while (i < j) {
        if (arr[i] + arr[j] < target) {
            i++;
        } else if (arr[i] + arr[j] > target) {
            j--;
        } else {
            count++;
            i++;
            j--;
        }
    }
    return count > 0 ? count : -1;
}

void testcase() {
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int& x : arr) {
        cin >> x;
    }
    int res = pairSum(arr, n, target);
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
