#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int comb(int n, int r) {
    if (r > n) return 0;
    int res = 1;
    for (int i = 0; i < r; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    int total = comb(N, M);
    int win = 0;

    // 리조트가 고른 숫자 중 j개는 지민이와 겹치고 나머지는 나머지 수에서 선택
    for (int j = K; j <= M; ++j) {
        // j개의 숫자를 지민이와 겹치게 고르는 경우
        // M-j개의 숫자를 지민이 외에서 고르는 경우
        win += comb(M, j) * comb(N - M, M - j);
    }

    double prob = (double)win / total;
    cout << fixed << setprecision(15) << prob << endl;

    return 0;
}
