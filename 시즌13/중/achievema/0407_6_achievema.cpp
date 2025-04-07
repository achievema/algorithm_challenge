#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n1, n2, T;
    string g1, g2;
    cin >> n1 >> n2;
    cin >> g1 >> g2;
    cin >> T;

    vector<pair<char, int>> ants;

    // 첫 번째 그룹은 방향 1, 뒤집어서 넣기
    for (int i = n1 - 1; i >= 0; --i) {
        ants.push_back({ g1[i], 1 });
    }

    // 두 번째 그룹은 방향 -1
    for (int i = 0; i < n2; ++i) {
        ants.push_back({ g2[i], -1 });
    }

    // T초 동안 시뮬레이션
    while (T--) {
        int i = 0;
        while (i < ants.size() - 1) {
            if (ants[i].second == 1 && ants[i + 1].second == -1) {
                // 서로 방향이 반대이면 스왑
                swap(ants[i], ants[i + 1]);
                i += 2; // 이미 바뀐 부분은 건너뜀
            }
            else {
                i++;
            }
        }
    }

    // 결과 출력
    for (auto ant : ants) {
        cout << ant.first;
    }
    cout << '\n';

    return 0;
}
