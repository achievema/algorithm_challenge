#include <iostream>
#include <vector>
using namespace std;

// �հ��� ��ȣ: 1���� 5���� (index�� ���߱� ���� 0�� index�� ������� ����)
int main() {
    int injured_finger, max_use;
    cin >> injured_finger >> max_use;

    if (max_use == 0 && injured_finger == 1) {
        // ���۵� ���ϴ� ���
        cout << 0 << endl;
        return 0;
    }

    // �հ��� ��� ���� (1 ~ 5���� ���ٰ� �ٽ� 1�� ���� �պ� ����)
    vector<int> pattern = { 1, 2, 3, 4, 5, 4, 3, 2 };

    // �հ����� ��� Ƚ���� ī��Ʈ
    vector<int> count(6, 0); // 1~5�� �հ��� ��� Ƚ�� �����

    int total_count = 0;
    int idx = 0;
    int dir = 1; // ���� (1: ������, -1: ������)

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
            idx -= 2; // ���� �ٲ㼭 �ǵ��ư���
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
