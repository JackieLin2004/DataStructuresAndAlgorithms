#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    const int id;       // ѧ��ѧ��
    string name;        // ѧ������
    int age;        // ѧ������
    bool sex;       // ѧ���Ա�trueΪ�У�falseΪŮ
    const string school = "���ϴ�ѧ";   // ѧ������ѧУ��Ĭ��Ϊ���ϴ�ѧ
    static int studentNumber;       // ѧ������
public:
    // Ĭ�Ϲ��캯��������ѧ������Ϊxxx������Ϊ0��ѧ��Ϊѧ�������Լ�1
    Student() : name("xxx"), age(0), sex(true), id(++studentNumber) {
        cout << "������Ĭ�Ϲ��캯����" << endl;
    }

    // ����Ĭ��ֵ�Ĳ��������캯��
    Student(string name, int age = 18, bool sex = true) : name(name), age(age), sex(sex), id(++studentNumber) {
        cout << "�����˾���Ĭ��ֵ�����Ĺ��캯����" << endl;
    }

    // �������캯��������һ��ѧ�����������ݣ���ѧ��Ҳ������
    Student(const Student &other) : name(other.name), age(other.age), sex(other.sex), id(++studentNumber) {
        cout << "���ÿ������캯����" << endl;
    }

    // �Զ���������������������ٵ�ѧ����ID
    ~Student() {
        cout << "�����������������ٵ�ѧ����ѧ��Ϊ��" << id << endl;
    }

    // ��ȡѧ�������ĺ���
    static int getStudentNumber() {
        return studentNumber;
    }

    // �޸����ֵĺ���
    void setName(const string &newName) {
        name = newName;
    }

    // �޸�����ĺ���
    void setAge(int newAge) {
        age = newAge;
    }

    // ������Ԫ��������ʾѧ����Ϣ
    friend void show(const Student &student);
};

int Student::studentNumber = 0;

// ��Ԫ��������
void show(const Student &student) {
    cout << "ѧ����Ϣ���£�" << endl;
    cout << "ѧ�ţ�" << student.id << endl;
    cout << "������" << student.name << endl;
    if (student.sex) cout << "�Ա�" << "��" << endl;
    else cout << "�Ա�" << "Ů" << endl;
    cout << "���䣺" << student.age << endl;
    cout << "ѧУ��" << student.school << endl;
}

int main() {
    // ����Ĭ�Ϲ��캯��
    Student student1;
    show(student1);

    // ���Ծ���Ĭ��ֵ�Ĳ��������캯��
    Student student2("Alice", 20, false);
    show(student2);

    // ���Կ������캯��
    Student student3 = student2;
    show(student3);

    // �����޸����ֺ�����ĺ���
    Student student4("ABC", 16, true);
    show(student4);
    student4.setName("Mike");
    student4.setAge(19);
    show(student4);

    // ���Ծ�̬��Ա��������ȡѧ������
    cout << "ѧ��������Ϊ��" << Student::getStudentNumber() << endl;
    return 0;
}