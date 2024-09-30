#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct course {
    char name[20];    // �γ���
    float score;      // �γ̳ɼ�
};

struct stu {
    int num;          // ѧ��
    char name[20];    // ����
    course score[4];  // �γ̳ɼ�
};

// ����������
// ���ѧ������
void addStudent();

// ��ʾѧ������
void showStudent();

// �޸�ѧ������
void modifyStudent();

// ͳ�Ʋ���ʾ�ɼ�
void calculateScore();

int main() {
    int choice;     // ѡ����Ӧ�Ĳ���
    do {
        cout << "=========================" << endl;
        cout << "0. �˳�" << endl;
        cout << "1. ¼��ѧ������" << endl;
        cout << "2. ��ʾѧ������" << endl;
        cout << "3. �޸�ѧ������" << endl;
        cout << "4. ͳ�Ʋ���ʾ�ɼ�" << endl;
        cout << "��ѡ����Ҫ�Ĳ�����";
        cin >> choice;
        cout << "=========================" << endl;

        switch (choice) {
            case 0:
                cout << "��лʹ�ã���ӭ�´�������" << endl;
                break;
            case 1:
                addStudent();
                break;
            case 2:
                showStudent();
                break;
            case 3:
                modifyStudent();
                break;
            case 4:
                calculateScore();
                break;
            default:
                cout << "����ѡ����Ч������������!" << endl;
        }
    } while (choice != 0);

    return 0;
}

void addStudent() {
    ofstream outfile("student.dat", ios::binary | ios::app);
    if (!outfile) {
        cerr << "�޷����ļ���" << endl;
        return;
    }

    int n;      // ��ʾ��Ҫ¼���ѧ��������
    cout << "��������Ҫ¼��ѧ����������";
    cin >> n;

    for (int i = 0; i < n; i++) {
        stu student{};
        cout << "�������" << i + 1 << "��ѧ����ѧ�ţ�";
        cin >> student.num;
        cout << "�������" << i + 1 << "��ѧ����������";
        cin >> student.name;
        for (int j = 0; j < 4; j++) {
            cout << "������γ�" << j + 1 << "���ƣ�";
            cin >> student.score[j].name;
            cout << "������γ�" << j + 1 << "�ɼ���";
            cin >> student.score[j].score;
        }
        outfile.write(reinterpret_cast<char *>(&student), sizeof(stu));
    }
    outfile.close();
    cout << "ѧ������¼����ɣ�" << endl;
}

void showStudent() {
    ifstream infile("student.dat", ios::binary);
    if (!infile) {
        cerr << "�޷����ļ���" << endl;
        return;
    }

    stu student{};
    while (infile.read(reinterpret_cast<char *>(&student), sizeof(stu))) {
        cout << "ѧ�ţ� " << student.num << endl;
        cout << "������" << student.name << endl;
        for (int j = 0; j < 4; ++j) {
            cout << "�γ�" << j + 1 << "���ƣ�" << student.score[j].name << endl;
            cout << "�γ�" << j + 1 << "�ɼ���" << student.score[j].score << endl;
        }
        cout << "-----------------------------" << endl;
    }
    infile.close();
}

void modifyStudent() {
    fstream file("student.dat", ios::binary | ios::in | ios::out);
    if (!file) {
        cerr << "�޷����ļ���" << endl;
        return;
    }

    int num;
    cout << "����Ҫ�޸ĵ�ѧ��ѧ�ţ�";
    cin >> num;

    stu student{};
    bool isFound = false;
    streampos position;
    while (file.read(reinterpret_cast<char *>(&student), sizeof(stu))) {
        if (student.num == num) {
            isFound = true;
            position = file.tellg() - static_cast<streampos>(sizeof(stu));
            break;
        }
    }

    if (isFound) {
        cout << "������ѧ���µ�������";
        cin >> student.name;
        for (int j = 0; j < 4; j++) {
            cout << "�������µĿγ�" << j + 1 << "���ƣ�";
            cin >> student.score[j].name;
            cout << "�������µĿγ�" << j + 1 << "�ɼ���";
            cin >> student.score[j].score;
        }
        file.seekp(position);
        file.write(reinterpret_cast<char *>(&student), sizeof(stu));
        cout << "ѧ�������޸���ɣ�" << endl;
    } else {
        cout << "δ�ҵ���ѧ�������������Ƿ���ȷ��" << endl;
    }
    file.close();
}

void calculateScore() {
    ifstream infile("student.dat", ios::binary);
    if (!infile) {
        cerr << "�޷����ļ���" << endl;
        return;
    }

    vector<stu> students;
    stu s{};
    while (infile.read(reinterpret_cast<char *>(&s), sizeof(stu))) {
        students.push_back(s);
    }

    infile.close();

    if (students.empty()) {
        cout << "û��ѧ������" << endl;
        return;
    }

    // ÿ��ѧ����ƽ���֡���ͷֺ���߷�
    for (const auto &student: students) {
        float total = 0, minScore = student.score[0].score, maxScore = student.score[0].score;
        for (const auto &course: student.score) {
            total += course.score;
            if (course.score < minScore) minScore = course.score;
            if (course.score > maxScore) maxScore = course.score;
        }
        float avg = total / 4;
        cout << "ѧ�ţ�" << student.num << ", ������" << student.name << endl;
        cout << "ƽ���֣�" << avg << ", ��ͷ֣�" << minScore << ", ��߷֣�" << maxScore << endl;
        cout << "-----------------------------" << endl;
    }

    // ÿ�ſγ̵�ƽ���֡���ͷֺ���߷�
    float totalScores[4] = {0}, minScores[4], maxScores[4];
    for (int i = 0; i < 4; ++i) {
        minScores[i] = students[0].score[i].score;
        maxScores[i] = students[0].score[i].score;
    }

    for (const auto &student: students) {
        for (int i = 0; i < 4; ++i) {
            totalScores[i] += student.score[i].score;
            if (student.score[i].score < minScores[i]) minScores[i] = student.score[i].score;
            if (student.score[i].score > maxScores[i]) maxScores[i] = student.score[i].score;
        }
    }

    cout << "�γ�ͳ�ƣ�" << endl;
    for (int i = 0; i < 4; ++i) {
        float avg = totalScores[i] / students.size();
        cout << "�γ�" << i + 1 << " ƽ����: " << avg << ", ��ͷ�: " << minScores[i] << ", ��߷�: " << maxScores[i]
             << endl;
    }
}