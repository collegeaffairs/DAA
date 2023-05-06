#include <iostream>
using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];
    for(int i = 0; i <= W; i++) {
        dp[0][i] = 0;
    }
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= W; j++) {
            if(wt[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    int wt[n], val[n];
    cout << "Enter the weights of the items:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> wt[i] ;
    }
    cout << "\nEnter the values of the items:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> val[i] ;
    }
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;
    cout << "maximum value obtained: " << knapsack(W, wt, val, n) << endl;
    return 0;
}
