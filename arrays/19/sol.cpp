#include <bits/stdc++.h>

using namespace std;

void rearrange(vector<int>& arr) {
    // Write your code here.
    vector<int> pos;
    vector<int> neg;

    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            neg.push_back(arr[i]);
        } else {
            pos.push_back(arr[i]);
        }
    }
    vector<int> rearr;
    int i = 0, j = 0;
    while (i < pos.size() && j < neg.size()) {
        rearr.push_back(neg[j++]);
        rearr.push_back(pos[i++]);
    }
    while (i < pos.size()) {
        rearr.push_back(pos[i++]);
    }
    while (j < neg.size()) {
        rearr.push_back(neg[j++]);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = rearr[i];
    }
}

void testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) {
        cin >> x;
    }
    rearrange(arr);
    for (int& x : arr) {
        cout << x << " ";
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
