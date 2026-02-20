#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Comparator: Sort by profit in descending order
bool compare(pair<int,int> p1, pair<int,int> p2) {
    return p1.second > p2.second;
}

int main() {

    // (deadline, profit)
    vector<pair<int,int>> job = {
        {4,10},
        {1,10},
        {2,40},
        {3,30}
    };

    // Step 1: Sort jobs by profit (descending)
    sort(job.begin(), job.end(), compare);

    int n = job.size();

    // Step 2: Find maximum deadline
    int maxDeadline = 0;
    for(int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, job[i].first);
    }

    // Step 3: Create time slots
    vector<int> slot(maxDeadline + 1, -1);

    int totalProfit = 0;

    // Step 4: Assign jobs to slots
    for(int i = 0; i < n; i++) {

        int deadline = job[i].first;
        int profit = job[i].second;

        // Try to place job in latest possible free slot
        for(int t = deadline; t > 0; t--) {
            if(slot[t] == -1) {
                slot[t] = i;   // assign job
                totalProfit += profit;
                break;
            }
        }
    }

    cout << "Maximum Profit = " << totalProfit << endl;

    return 0;
}
