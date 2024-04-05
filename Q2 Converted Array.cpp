#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reverseArray(vector<int>& arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

vector<int> circularShift(vector<int>& arr, int n1, int n2, int k) {
    int n = n2 - n1 + 1;
    k %= n; // to handle cases where k is larger than n

    // Step 1: Reverse the entire range
    reverseArray(arr, n1, n2);

    // Step 2: Reverse the first k elements within the range
    reverseArray(arr, n1, n1 + k - 1);

    // Step 3: Reverse the remaining elements within the range
    reverseArray(arr, n1 + k, n2);

    return arr;
}

int main() {
    vector<int> A = {5, 15, 29, 35, 42};
    int n1 = 0; // Start index
    int n2 = A.size() - 1; // End index
    int k1 = 2;
    int k2 = 4;

    cout << "Original Array: ";
    for (int i = n1; i <= n2; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    vector<int> result1 = circularShift(A, n1, n2, k1);
    cout << "Circularly shifted by " << k1 << " positions: ";
    for (int i = n1; i <= n2; ++i) {
        cout << result1[i] << " ";
    }
    cout << endl;

    vector<int> result2 = circularShift(A, n1, n2, k2);
    cout << "Circularly shifted by " << k2 << " positions: ";
    for (int i = n1; i <= n2; ++i) {
        cout << result2[i] << " ";
    }
    cout << endl;
    return 0;
}
