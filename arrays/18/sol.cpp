#include <bits/stdc++.h>

using namespace std;

vector<int> findCommonElements(vector<int>& a, vector<int>& b, vector<int>& c) {
    // Write your code here
    int n = a.size();
    int m = b.size();
    int l = c.size();

    int i = 0, j = 0, k = 0;

    vector<int> common;
    while (i < n && j < m && k < l) {
        if (a[i] == b[j] && a[i] == c[k]) {
            common.push_back(a[i]);
            i++;
            j++;
            k++;
        } else if (a[i] <= b[j] && a[i] <= c[k]) {
            i++;
        } else if (b[j] <= a[i] && b[j] <= c[k]) {
            j++;
        } else if (c[k] <= a[i] && c[k] <= b[j]) {
            k++;
        }
    }
    set<int> s(common.begin(), common.end());
    common.assign(s.begin(), s.end());
    return common;
}

void testcase() {
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n), b(m), c(l);
    for (int& x : a) {
        cin >> x;
    }
    for (int& x : b) {
        cin >> x;
    }
    for (int& x : c) {
        cin >> x;
    }

    vector<int> res = findCommonElements(a, b, c);
    for (int& x : res) {
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
