#include <bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int>& arr) {
    // Write your code here
    int slow = arr[0];
    int fast = arr[arr[0]];
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[arr[fast]];
    }
    fast = 0;
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

void testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int res = findDuplicate(arr);
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
