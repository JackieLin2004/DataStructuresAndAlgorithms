#include <iostream>
#include <cmath>

using namespace std;

class Shape {                       // ������
public:
    virtual double area() = 0;      //���麯������shape�ı����
    virtual double volume() = 0;    //���麯������shape�����
    virtual void show() {            //�麯������ʾshape����������
        cout << "Area: " << area() << ", Volume: " << volume() << endl;
    }
};

class Cube : public Shape {
private:
    double side;        // �߳�
public:
    Cube(double s) {    //���캯��
        side = s;
    }

    double area() override {     //������
        return 6 * side * side;
    }

    double volume() override {       //�����
        return side * side * side;
    }
};

class Ball : public Shape {
private:
    double radius;      // �뾶
public:
    Ball(double r) {    //���캯��
        radius = r;
    }

    double area() override {    //������
        return 4 * M_PI * radius * radius;
    }

    double volume() override {     //�����
        return (4.0 / 3.0) * M_PI * radius * radius * radius;
    }
};

class Cylinder : public Shape {
private:
    double radius, height;   // �뾶����
public:
    Cylinder(double r, double h) {      //���캯��
        radius = r;
        height = h;
    }

    double area() override {    //������
        return 2 * M_PI * radius * radius + 2 * M_PI * radius * height;
    }

    double volume() override {   //�����
        return M_PI * radius * radius * height;
    }

};

int main() {
    double var1, var2;        //��ʱ����

    cout << "������������߳�: ";
    cin >> var1;
    Cube c(var1);
    c.show();

    cout << "����������뾶: ";
    cin >> var1;
    Ball b(var1);
    b.show();

    cout << "������Բ�������뾶�͸�: ";
    cin >> var1 >> var2;
    Cylinder cy(var1, var2);
    cy.show();

    return 0;
}
