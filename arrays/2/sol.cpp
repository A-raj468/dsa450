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

void sort(vector<int>& arr, int start, int end) {
    if (end <= start) {
        return;
    }
    int i = partition(arr, start, end);
    sort(arr, start, i - 1);
    sort(arr, i + 1, end);
}

vector<int> kthSmallLarge(vector<int>& arr, int n, int k) {
    // Write your code here.
    sort(arr, 0, n - 1);
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
