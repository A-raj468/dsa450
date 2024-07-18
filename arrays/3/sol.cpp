#include <bits/stdc++.h>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void sort012(int* arr, int n) {
    //   Write your code here
    int left = 0, current = 0, right = n - 1;
    while (current < n && current <= right) {
        if (arr[current] == 0) {
            if (current >= left) {
                swap(arr[current], arr[left]);
                left++;
            } else {
                current++;
            }
        } else if (arr[current] == 2) {
            swap(arr[current], arr[right]);
            right--;
        } else {
            current++;
        }
    }
}

void testcase() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    sort012(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
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
