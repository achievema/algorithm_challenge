#include <iostream>
using namespace std;

bool paper[100][100]; // 도화지 (최대 크기 100x100)

int main() {
    int n;
    cin >> n;

    while (n--) {
        int x, y;
        cin >> x >> y;

        // 색종이 크기는 10x10
        for (int i = x; i < x + 10; i++) {
            for (int j = y; j < y + 10; j++) {
                paper[i][j] = true;
            }
        }
    }

    int area = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (paper[i][j]) area++;
        }
    }

    cout << area << endl;
    return 0;
}
