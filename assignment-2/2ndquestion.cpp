#include <iostream>
using namespace std;

int main() {
    int at[] = {900, 910, 920, 1100, 1120};
    int dt[] = {940, 1200, 950, 1130, 1140};
    int n = 5;

    int platforms = 0, maxPlatforms = 0;

    for (int i = 0; i < n; i++) {
        platforms = 1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (at[j] <= dt[i] && at[j] >= at[i])
                    platforms++;
            }
        }
        if (platforms > maxPlatforms)
            maxPlatforms = platforms;
    }

    cout << maxPlatforms;
    return 0;
}
