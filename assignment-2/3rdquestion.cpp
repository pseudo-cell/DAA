#include <iostream>
using namespace std;

int main() {
    int N = 3;
    int value[]  = {100, 60, 120};
    int weight[] = {20, 10, 40};
    int W = 50;

    float ratio[3];
    for (int i = 0; i < N; i++) {
        ratio[i] = (float)value[i] / weight[i];
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (ratio[i] < ratio[j]) {
                float t = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = t;
                int tv = value[i];
                value[i] = value[j];
                value[j] = tv;
                int tw = weight[i];
                weight[i] = weight[j];
                weight[j] = tw;
            }
        }
    }
    float maxValue = 0.0;

    for (int i = 0; i < N; i++) {
        if (W >= weight[i]) {
            maxValue += value[i];
            W -= weight[i];
        } else {
            maxValue += ratio[i] * W;
            break;
        }
    }

    cout << "Maximum value = " << maxValue << endl;

    return 0;
}