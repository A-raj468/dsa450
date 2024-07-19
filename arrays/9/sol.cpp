#include <bits/stdc++.h>

using namespace std;

int minimumJumps(vector<int>& arr, int n) {
    // write your code here
    int maxReach = 0;
    int remStep = 0;
    int jumps = 0;
    for (int i = 0; i < n; i++) {
        if (i > maxReach) {
            return -1;
        }
        if (i == n - 1) {
            return jumps;
        }
        maxReach = max(maxReach, i + arr[i]);
        if (remStep == 0) {
            jumps++;
            remStep = maxReach - i;
        }
        remStep--;
    }
    return jumps;
}

void testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int res = minimumJumps(arr, n);
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
