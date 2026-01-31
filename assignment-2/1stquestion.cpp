#include <iostream>
using namespace std;

int main() {
    int N = 6;
    int start[]  = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};

    int count = 1;                 
    int lastFinish = finish[0];    
     cout << "Selected activities: ";
    cout << "(" << start[0] << ", " << finish[0] << ") ";
    for (int i = 1; i < N; i++) {
        if (start[i] >= lastFinish) {
            cout << "(" << start[i] << ", " << finish[i] << ") ";
            lastFinish = finish[i];
            count++;
        }
    }

    cout << "\nMaximum number of activities = " << count << endl;

    return 0;
}