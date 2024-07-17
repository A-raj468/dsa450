#include <iostream>
#include <vector>

using namespace std;

void swap(int& i, int& j) {
    int temp = i;
    i = j;
    j = temp;
}

void sort(vector<int>& arr, int start, int end) {
    if (end <= start) {
        return;
    }
    int pivot = arr[end];
    int i = start, j = end;
    while (i <= j) {
        if (arr[i] >= pivot) {
            swap(arr[i], arr[j]);
            j--;
        } else {
            i++;
        }
    }

    sort(arr, start, i - 1);
    sort(arr, i, end);
}

vector<int> kthSmallLarge(vector<int>& arr, int n, int k) {
    // Write your code here.
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    sort(arr, 0, n - 1);
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    vector<int> ret = {arr[k - 1], arr[n - k]};
    return ret;
}

void testcase() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> res = kthSmallLarge(arr, n, k);
    cout << res[0] << " " << res[1] << endl;
}

int main(int argc, char* argv[]) {
    int t;
    cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}
