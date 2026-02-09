#include <iostream>
using namespace std;

int main() {
    int n = 5;
    char jobs[] = {'1','2','3','4','5'};
    int deadline[] = {2,1,2,1,3};
    int profit[] = {100,19,27,25,15};

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (profit[j] > profit[i]) {
                int tp = profit[i];
                profit[i] = profit[j];
                profit[j] = tp;

                int td = deadline[i];
                deadline[i] = deadline[j];
                deadline[j] = td;

                char tj = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = tj;
            }
        }
    }

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        if (deadline[i] > maxDeadline)
            maxDeadline = deadline[i];

    char slot[10];
    for (int i = 0; i < maxDeadline; i++)
        slot[i] = '0';

    int count = 0, totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = deadline[i] - 1; j >= 0; j--) {
            if (slot[j] == '0') {
                slot[j] = jobs[i];
                count++;
                totalProfit += profit[i];
                break;
            }
        }
    }

    cout << "Selected Jobs: [";
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i] != '0')
            cout << "J" << slot[i] << " ";
    }
    cout << "]\n";

    cout << "Maximum Profit = " << totalProfit;
    return 0;
}
