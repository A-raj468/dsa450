#include <bits/stdc++.h>

using namespace std;

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

    unordered_map<int, int> frequency;
    for (int i = 0; i < arr2.size(); i++) {
        frequency[arr2[i]] = 1;
    }

    int countCommon = 0;
    for (int i = 0; i < arr1.size(); i++) {
        if (frequency[arr1[i]] == 1) {
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
