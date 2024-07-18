#include <bits/stdc++.h>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

vector<int> separateNegativeAndPositive(vector<int>& nums) {
    // Write your code here.
    int pivot = 0;
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        if (nums[left] > pivot) {
            swap(nums[left], nums[right]);
            right--;
        } else if (nums[right] < pivot) {
            swap(nums[left], nums[right]);
            left++;
        } else {
            left++;
            right--;
        }
    }
    return nums;
}

void testcase() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> res = separateNegativeAndPositive(nums);

    for (auto x : nums) {
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
