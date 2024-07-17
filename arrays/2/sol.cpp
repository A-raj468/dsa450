#include <iostream>
#include <vector>

using namespace std;

void swap(int& i, int& j) {
    int temp = i;
    i = j;
    j = temp;
}

int partition(vector<int>& arr, int start, int end) {
    int pivot = arr[end];

    int left = start;
    for (int right = start; right < end; right++) {
        if (arr[right] <= pivot) {
            swap(arr[left], arr[right]);
            left++;
        }
    }
    swap(arr[left], arr[end]);
    return left;
}

int quickselect(vector<int>& arr, int start, int end, int k) {
    if (k < start || k > end) {
        return -1;
    }
    int i = partition(arr, start, end);
    if (i == k) {
        return arr[i];
    }
    if (i > k) {
        return quickselect(arr, start, i - 1, k);
    } else {
        return quickselect(arr, i + 1, end, k);
    }
}

vector<int> kthSmallLarge(vector<int>& arr, int n, int k) {
    // Write your code here.
    vector<int> ret = {quickselect(arr, 0, n - 1, k - 1),
                       quickselect(arr, 0, n - 1, n - k)};
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
