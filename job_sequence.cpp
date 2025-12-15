#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/* Structure to represent a Job */
struct Job {
  int id;       // Job ID
  int deadline; // Deadline of job
  int profit;   // Profit if job is completed
};

/* Comparator function to sort jobs by profit (descending) */
bool compare(Job a, Job b) { return a.profit > b.profit; }

int main() {
  int n;
  cout << "Enter number of jobs: ";
  cin >> n;

  Job jobs[n];

  cout << "Enter Job ID, Deadline, Profit for each job:\n";
  for (int i = 0; i < n; i++) {
    cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
  }

  // Step 1: Sort jobs by profit
  sort(jobs, jobs + n, compare);

  // Step 2: Find maximum deadline
  int maxDeadline = 0;
  for (int i = 0; i < n; i++) {
    maxDeadline = max(maxDeadline, jobs[i].deadline);
  }

  // Step 3: Create slot array
  vector<int> slot(maxDeadline + 1, -1);

  int totalProfit = 0;

  // Step 4: Schedule jobs
  for (int i = 0; i < n; i++) {
    for (int j = jobs[i].deadline; j > 0; j--) {
      if (slot[j] == -1) {
        slot[j] = jobs[i].id;
        totalProfit += jobs[i].profit;
        break;
      }
    }
  }

  // Output result
  cout << "\nJob Sequence: ";
  for (int i = 1; i <= maxDeadline; i++) {
    if (slot[i] != -1)
      cout << "J" << slot[i] << " ";
  }

  cout << "\nTotal Profit: " << totalProfit << endl;

  return 0;
}
