#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MakeOne {
public:
    MakeOne(int n) : N(n), dp(n + 1, -1) {}

    int getMinOperations() {
        return solve(N);
    }

private:
    int N;
    vector<int> dp;

    int solve(int x) {
        if (x == 1) return 0;
        if (dp[x] != -1) return dp[x];

        int res = solve(x - 1) + 1;
        if (x % 2 == 0) res = min(res, solve(x / 2) + 1);
        if (x % 3 == 0) res = min(res, solve(x / 3) + 1);

        return dp[x] = res;
    }
};

int main() {
    int N;
    cin >> N;

    MakeOne solver(N);
    cout << solver.getMinOperations() << endl;

    return 0;
}
