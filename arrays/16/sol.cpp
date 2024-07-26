#include <bits/stdc++.h>

using namespace std;

int maximumProfit(vector<int>& prices) {
    // Write your code here.
    int profit = 0;
    int n = prices.size();
    if (n <= 1) {
        return 0;
    }
    int minTillNow = prices[0];
    for (int i = 1; i < n; i++) {
        profit = max(profit, prices[i] - minTillNow);
        minTillNow = min(minTillNow, prices[i]);
    }

    return profit;
}

void testcase() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int& x : prices) {
        cin >> x;
    }
    int res = maximumProfit(prices);
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
