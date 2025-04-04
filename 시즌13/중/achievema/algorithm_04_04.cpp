#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> numbers;
int operators[4]; // + - * /
int max_result = -1e9;
int min_result = 1e9;

void dfs(int idx, int current) {
    if (idx == N) {
        max_result = max(max_result, current);
        min_result = min(min_result, current);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (operators[i] > 0) {
            operators[i]--;

            int next = current;
            int num = numbers[idx];

            if (i == 0) next += num;
            else if (i == 1) next -= num;
            else if (i == 2) next *= num;
            else if (i == 3) {
                if (current < 0)
                    next = -(-current / num);
                else
                    next = current / num;
            }

            dfs(idx + 1, next);
            operators[i]++; // backtrack
        }
    }
}

int main() {
    cin >> N;
    numbers.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    for (int i = 0; i < 4; ++i) {
        cin >> operators[i];
    }

    dfs(1, numbers[0]);

    cout << max_result << '\n';
    cout << min_result << '\n';

    return 0;
}
