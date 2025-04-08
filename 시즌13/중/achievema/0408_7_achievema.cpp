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

    // ����Ʈ�� �� ���� �� j���� �����̿� ��ġ�� �������� ������ ������ ����
    for (int j = K; j <= M; ++j) {
        // j���� ���ڸ� �����̿� ��ġ�� ���� ���
        // M-j���� ���ڸ� ������ �ܿ��� ���� ���
        win += comb(M, j) * comb(N - M, M - j);
    }

    double prob = (double)win / total;
    cout << fixed << setprecision(15) << prob << endl;

    return 0;
}
