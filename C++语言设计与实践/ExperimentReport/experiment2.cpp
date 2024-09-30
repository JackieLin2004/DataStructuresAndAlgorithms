#include <iostream>
#include <string>
#include <vector>

using namespace std;

// �������ڵĽṹ��
struct Date {
    int year;
    int month;
    int day;
};

// �˻���
class People {
protected:
    int id;     // ���
    string name;    // ����
    string sex;     // �Ա�
    string tel;     // ��ϵ�绰
    string e_mail;      // ����
    Date bir;       // ��������
public:
    People(int id, string name, string sex, string tel, string e_mail, Date bir)
            : id(id), name(name), sex(sex), tel(tel), e_mail(e_mail), bir(bir) {}

    // ���Ա����show()
    virtual void show() const {
        cout << "��ţ�" << id << endl;
        cout << "������" << name << endl;
        cout << "�Ա�" << sex << endl;
        cout << "��ϵ�绰��" << tel << endl;
        cout << "���䣺" << e_mail << endl;
        cout << "�������ڣ�" << bir.year << "-" << bir.month << "-" << bir.day << endl;
    }

    virtual ~People() {
        cout << "����People������������" << endl;
    }
};

// ��ʦ��
class Teacher : public virtual People {
private:
    string degree;      // ѧλ
    string dep;     // ����
public:
    Teacher(int id, string name, string sex, string tel, string e_mail, Date bir,
            string degree, string dep)
            : People(id, name, sex, tel, e_mail, bir), degree(degree), dep(dep) {}

    // ��д������麯������ʾ�����Ϣ
    void show() const override {
        People::show();
        cout << "ѧλ��" << degree << endl;
        cout << "���ţ�" << dep << endl;
    }

    // ��д�鹹����
    ~Teacher() override {
        cout << "����Teacher������������" << endl;
    }
};

// ѧ����
class Student : public virtual People {
private:
    string sno;     // ѧ��
    string major;       // רҵ
public:
    Student(int id, string name, string sex, string tel, string e_mail, Date bir,
            string sno, string major)
            : People(id, name, sex, tel, e_mail, bir), sno(sno), major(major) {}

    // ��д������麯������ʾ�����Ϣ
    void show() const override {
        People::show();
        cout << "ѧ�ţ�" << sno << endl;
        cout << "רҵ��" << major << endl;
    }

    // ��д�鹹����
    ~Student() override {
        cout << "����Student������������" << endl;
    }
};

// �γ���Ϣ�ṹ��
struct CourseInfo {
    string name;    // �γ�����
    int id;     // �γ�id
    vector<Student> students;   // ��������vector���ɱ����顣���ڴ����������
    Teacher teacher;
};

// �γ���
class Course : public Teacher, public Student {
private:
    CourseInfo cinfo;
public:
    Course(int pid, string pname, string psex, string ptel, string pe_mail, Date pbir,
           string tdegree, string tdep, string ssno, string smajor,
           CourseInfo cinfo)
            : People(pid, pname, psex, ptel, pe_mail, pbir),
              Teacher(pid, pname, psex, ptel, pe_mail, pbir, tdegree, tdep),
              Student(pid, pname, psex, ptel, pe_mail, pbir, ssno, smajor), cinfo(cinfo) {}

    // ��д������麯������ʾ�����Ϣ
    void show() const override {
        Teacher::show();
        Student::show();
        cout << "==============================" << endl;
        cout << "�γ������Ϣ��" << endl;
        cout << "�γ����ƣ�" << cinfo.name << "\n"
             << "�γ�id�� " << cinfo.id << "\n"
             << "�ο���ʦ�� \n";
        cinfo.teacher.show();
        cout << "�༶ѧ����\n";
        for (const auto &student: cinfo.students) {
            student.show();
        }
    }

    // ��д�鹹����
    ~Course() override {
        cout << "����Course������������" << endl;
    }
};

int main() {
    // ������Ҫ�����ĳ�������
    Date birthDate1 = {1979, 5, 20};
    Date birthDate2 = {2004, 2, 14};
    Date birthDate3 = {2004, 3, 16};
    Date birthDate4 = {1986, 7, 17};
    // ����һ����ʦ��չʾ����
    Teacher teacher1(1, "������ʦ", "��", "12345678910", "Zhangsan@163.com",
                     birthDate1, "��ʿ", "���ѧԺ");
    teacher1.show();
    // ����ѧ����չʾ����
    Student student1(2, "С��", "��", "98765432100", "Xiaoming@163.com",
                     birthDate2, "S001", "�������");
    student1.show();
    Student student2(3, "С��", "Ů", "55556667777", "Xiaohong@163.com",
                     birthDate3, "S002", "����ռ䰲ȫ");
    student2.show();

    cout << "==============================" << endl;
    // ����γ���Ϣ����֮ǰ�������ʦ��ѧ���ӽ�ȥ
    CourseInfo courseInfo = {"���ݽṹ���㷨", 101, {student1, student2}, teacher1};
    // ����һ�ſγ�
    Course course(4, "������ʦ", "Ů", "11222333444", "Lisi@163.com", birthDate4, "��ʿ",
                  "��ϢѧԺ", "S003", "�˹�����", courseInfo);
    course.show();
    return 0;
}