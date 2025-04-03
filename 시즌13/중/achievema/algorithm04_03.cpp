#include <iostream>
#include <vector>
using namespace std;

// 손가락 번호: 1부터 5까지 (index를 맞추기 위해 0번 index는 사용하지 않음)
int main() {
    int injured_finger, max_use;
    cin >> injured_finger >> max_use;

    if (max_use == 0 && injured_finger == 1) {
        // 시작도 못하는 경우
        cout << 0 << endl;
        return 0;
    }

    // 손가락 사용 패턴 (1 ~ 5까지 갔다가 다시 1로 오는 왕복 패턴)
    vector<int> pattern = { 1, 2, 3, 4, 5, 4, 3, 2 };

    // 손가락별 사용 횟수를 카운트
    vector<int> count(6, 0); // 1~5번 손가락 사용 횟수 저장용

    int total_count = 0;
    int idx = 0;
    int dir = 1; // 방향 (1: 정방향, -1: 역방향)

    while (true) {
        int finger = pattern[idx];
        if (finger == injured_finger) {
            if (count[finger] >= max_use)
                break;
            count[finger]++;
        }
        total_count++;

        idx += dir;
        if (idx == pattern.size()) {
            idx -= 2; // 방향 바꿔서 되돌아가기
            dir = -1;
        }
        else if (idx == -1) {
            idx = 1;
            dir = 1;
        }
    }

    cout << total_count << endl;
    return 0;
}
