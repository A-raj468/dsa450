#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

vector<int> nextPermutation(vector<int>& permutation, int n) {
    //  Write your code here.
    auto it = is_sorted_until(permutation.rbegin(), permutation.rend());
    if (permutation.rend() == it) {
        reverse(permutation.rbegin(), permutation.rend());
    } else {
        auto next = upper_bound(permutation.rbegin(), it, *it);
        swap(*it, *next);
        reverse(permutation.rbegin(), it);
    }
    return permutation;
}

void testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> res = nextPermutation(arr, n);
    for (int x : res) {
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
