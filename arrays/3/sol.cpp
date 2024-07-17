#include <bits/stdc++.h>

using namespace std;

void sort012(int* arr, int n) {
    //   Write your code here
    int count[3] = {0, 0, 0};
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    int till = 0;
    for (int j = 0; j < 3; j++) {
        for (int i = till; i < till + count[j]; i++) {
            arr[i] = j;
        }
        till += count[j];
    }
}

void testcase() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

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
