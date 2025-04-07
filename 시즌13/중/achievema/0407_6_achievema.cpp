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

    // ù ��° �׷��� ���� 1, ����� �ֱ�
    for (int i = n1 - 1; i >= 0; --i) {
        ants.push_back({ g1[i], 1 });
    }

    // �� ��° �׷��� ���� -1
    for (int i = 0; i < n2; ++i) {
        ants.push_back({ g2[i], -1 });
    }

    // T�� ���� �ùķ��̼�
    while (T--) {
        int i = 0;
        while (i < ants.size() - 1) {
            if (ants[i].second == 1 && ants[i + 1].second == -1) {
                // ���� ������ �ݴ��̸� ����
                swap(ants[i], ants[i + 1]);
                i += 2; // �̹� �ٲ� �κ��� �ǳʶ�
            }
            else {
                i++;
            }
        }
    }

    // ��� ���
    for (auto ant : ants) {
        cout << ant.first;
    }
    cout << '\n';

    return 0;
}
