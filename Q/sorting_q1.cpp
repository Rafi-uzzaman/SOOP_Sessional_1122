// Quick Sort and Merge Sort Time Analysis

#include <bits/stdc++.h>
using namespace std;

int partitionQS(vector<int>& a, int l, int r) {
    int p = a[r], i = l - 1;
    for (int j = l; j < r; j++)
        if (a[j] <= p)
            swap(a[++i], a[j]);
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quickSort(vector<int>& a, int l, int r) {
    if (l < r) {
        int p = partitionQS(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}

void merge(vector<int>& a, int l, int m, int r) {
    vector<int> L(a.begin() + l, a.begin() + m + 1);
    vector<int> R(a.begin() + m + 1, a.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < L.size() && j < R.size())
        a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < L.size()) a[k++] = L[i++];
    while (j < R.size()) a[k++] = R[j++];
}

void mergeSort(vector<int>& a, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = random() % 1000;

    vector<int> b = a;

    auto s1 = chrono::high_resolution_clock::now();
    quickSort(a, 0, n - 1);
    auto e1 = chrono::high_resolution_clock::now();

    auto s2 = chrono::high_resolution_clock::now();
    mergeSort(b, 0, n - 1);
    auto e2 = chrono::high_resolution_clock::now();

    cout << chrono::duration_cast<chrono::microseconds>(e1 - s1).count() << endl;
    cout << chrono::duration_cast<chrono::microseconds>(e2 - s2).count() << endl;

    return 0;
}
