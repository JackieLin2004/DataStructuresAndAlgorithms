#include <bits/stdc++.h>

using namespace std;

#define pi 3.14

int fun(float r, float &s, float &l, float &v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    float r, area, length, volume;
    int flag;
    cout << "������һ���뾶��\n";
    cin >> r;
    flag = fun(r, area, length, volume);
    if (flag == 0) {
        cout << "����İ뾶���Ϸ�\n";
    } else {
        cout << "Բ���Ϊ��" << area << endl;
        cout << "Բ�ܳ�Ϊ��" << length << endl;
        cout << "�����Ϊ��" << volume << endl;
    }
    return 0;
}

int fun(float r, float &s, float &l, float &v) {
    if (r <= 0) return 0;
    s = 4 * pi * pow(r, 2);
    l = 2 * pi * r;
    v = 4 * pi * pow(r, 3) / 3;
    return 1;
}

// 2