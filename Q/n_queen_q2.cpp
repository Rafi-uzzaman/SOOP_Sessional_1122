// N Queens Problem Using Backtracking

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> col;
int cnt = 0;

bool safe(int r, int c) {
    for (int i = 0; i < r; i++)
        if (col[i] == c || abs(col[i] - c) == abs(i - r))
            return false;
    return true;
}

void solve(int r) {
    if (r == n) {
        cnt++;
        return;
    }
    for (int c = 0; c < n; c++) {
        if (safe(r, c)) {
            col[r] = c;
            solve(r + 1);
        }
    }
}

int main() {
    cin >> n;
    col.resize(n);
    solve(0);
    cout << cnt << endl;
    return 0;
}
