#include <bits/stdc++.h>

using namespace std;

vector<int> rotateArray(vector<int> arr, int k) {
    // Write your code here.
    vector<int> ret(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        ret[i] = arr[(i + k) % arr.size()];
    }
    return ret;
}

void testcase() {
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> k;

    vector<int> res = rotateArray(arr, k);
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
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
