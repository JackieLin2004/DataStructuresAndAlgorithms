#include <iostream>
#include <cmath>  // ������ѧ����ʹ�� M_PI ����

using namespace std;

class Shape {  // ������
public:
    virtual double area() const = 0;      // ���麯������shape�ı����
    virtual double volume() const = 0;    // ���麯������shape�����
    virtual void show() const {           // �麯������ʾshape����������
        cout << "Area: " << area() << ", Volume: " << volume() << endl;
    }
};

class Cube : public Shape {
private:
    double side;  // �߳�
public:
    Cube(double s) : side(s) {}  // ���캯��
    double area() const override {  // ������
        return 6 * side * side;
    }

    double volume() const override {  // �����
        return side * side * side;
    }
};

class Ball : public Shape {
private:
    double radius;  // �뾶
public:
    Ball(double r) : radius(r) {}  // ���캯��
    double area() const override {  // ������
        return 4 * M_PI * radius * radius;
    }

    double volume() const override {  // �����
        return (4.0 / 3.0) * M_PI * radius * radius * radius;
    }
};

class Cylinder : public Shape {
private:
    double radius, height;  // �뾶����
public:
    Cylinder(double r, double h) : radius(r), height(h) {}  // ���캯��
    double area() const override {  // ������
        return 2 * M_PI * radius * (radius + height);
    }

    double volume() const override {  // �����
        return M_PI * radius * radius * height;
    }
};

int main() {
    double var1, var2;  // ��ʱ����

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
