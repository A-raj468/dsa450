#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    // Write your code here.
    sort(intervals.begin(), intervals.end(),
         [](vector<int>& a, vector<int>& b) -> bool { return a[0] < b[0]; });
    vector<vector<int>> merged;
    vector<int> prev = intervals[0];
    for (int i = 1; i < intervals.size(); i++) {
        vector<int> x = intervals[i];
        if (prev[1] < x[0]) {
            merged.push_back(prev);
            prev = intervals[i];
        } else {
            if (prev[1] < x[1]) {
                prev[1] = x[1];
            }
        }
    }
    merged.push_back(prev);
    return merged;
}

void testcase() {
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][j];
        }
    }
    vector<vector<int>> res = mergeIntervals(intervals);
    for (auto i : res) {
        cout << i[0] << " " << i[1] << endl;
    }
}

int main(int argc, char* argv[]) {
    int t;
    cin >> t;
    while (t--) {
        testcase();
    }

    return 0;
}
