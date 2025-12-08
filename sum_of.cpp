#include <iostream>
using namespace std;

int target = 10;
int n;
int arr[50];
int x[50];

void sumOfSubset(int s, int k, int r) {
    x[k] = 1;

    if (s + arr[k] == target) {
        cout << "Subset: ";
        for (int i = 0; i <= k; i++)
            if (x[i] == 1) cout << arr[i] << " ";
        cout << endl;
    }

    if (s + arr[k] + arr[k + 1] <= target && k + 1 < n)
        sumOfSubset(s + arr[k], k + 1, r - arr[k]);

    if (s + arr[k + 1] <= target && k + 1 < n) {
        x[k] = 0;
        sumOfSubset(s, k + 1, r - arr[k]);
    }
}

void runAscending() {
    cout << "\n--- Ascending Order Input ---\n";
    n = 5;
    int temp[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < n; i++) arr[i] = temp[i];
    sumOfSubset(0, 0, 15);
}

void runDescending() {
    cout << "\n--- Descending Order Input ---\n";
    n = 5;
    int temp[5] = {5, 4, 3, 2, 1};

    for (int i = 0; i < n; i++) arr[i] = temp[i];
    sumOfSubset(0, 0, 15);
}

void runRandom() {
    cout << "\n--- Random Order Input ---\n";
    n = 5;
    int temp[5] = {4, 1, 5, 2, 3};

    for (int i = 0; i < n; i++) arr[i] = temp[i];
    sumOfSubset(0, 0, 15);
}

int main() {
    runAscending();
    runDescending();
    runRandom();
}
