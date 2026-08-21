#include <iostream>
using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapsack(W, wt, val, n - 1);

    int include = val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1);
    int exclude = knapsack(W, wt, val, n - 1);

    return max(include, exclude);
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int wt[100], val[100];

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
        cin >> val[i];

    cout << "Enter capacity: ";
    cin >> W;

    cout << "Maximum value: " << knapsack(W, wt, val, n);

    return 0;
}
