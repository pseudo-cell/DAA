#include <iostream>
using namespace std;

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = 8;

    int maxsum = arr[0];
    int currsum = 0;

    for(int i = 0; i < n; i++) {
        currsum += arr[i];
        if(currsum > maxsum)
            maxsum = currsum;
        if(currsum < 0)
            currsum = 0;
    }

    cout << "Maximum Subarray Sum = " << maxsum;
    return 0;
}
