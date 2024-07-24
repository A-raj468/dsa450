#include <bits/stdc++.h>

using namespace std;

vector<int> nextPermutation(vector<int>& permutation, int n) {
    //  Write your code here.
    int prev = permutation[n - 1];
    int pivot = n - 1;
    for (pivot = n - 1; pivot >= 0; pivot--) {
        if (permutation[pivot] < prev) {
            break;
        }
        prev = permutation[pivot];
    }
    if (pivot < 0) {
        for (int i = 0; i < n / 2; i++) {
            swap(permutation[i], permutation[n - 1 - i]);
        }
        return permutation;
    }
    int next;
    prev = INT32_MAX;
    for (int i = pivot + 1; i < n; i++) {
        if (permutation[i] < prev && permutation[i] > permutation[pivot]) {
            next = i;
            prev = permutation[i];
        }
    }
    swap(permutation[next], permutation[pivot]);

    for (int i = 0; i <= pivot; i++) {
        permutation[i] = permutation[i];
    }
    for (int i = n - 1; i > (pivot + n - 1) / 2; i--) {
        swap(permutation[pivot + n - i], permutation[i]);
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
