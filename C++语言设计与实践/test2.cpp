#include <iostream>
#include <cmath>  // 包含数学库以使用 M_PI 常量

using namespace std;

class Shape {  // 抽象类
public:
    virtual double area() const = 0;      // 纯虚函数，求shape的表面积
    virtual double volume() const = 0;    // 纯虚函数，求shape的体积
    virtual void show() const {           // 虚函数，显示shape的面积和体积
        cout << "Area: " << area() << ", Volume: " << volume() << endl;
    }
};

class Cube : public Shape {
private:
    double side;  // 边长
public:
    Cube(double s) : side(s) {}  // 构造函数
    double area() const override {  // 求表面积
        return 6 * side * side;
    }

    double volume() const override {  // 求体积
        return side * side * side;
    }
};

class Ball : public Shape {
private:
    double radius;  // 半径
public:
    Ball(double r) : radius(r) {}  // 构造函数
    double area() const override {  // 求表面积
        return 4 * M_PI * radius * radius;
    }

    double volume() const override {  // 求体积
        return (4.0 / 3.0) * M_PI * radius * radius * radius;
    }
};

class Cylinder : public Shape {
private:
    double radius, height;  // 半径，高
public:
    Cylinder(double r, double h) : radius(r), height(h) {}  // 构造函数
    double area() const override {  // 求表面积
        return 2 * M_PI * radius * (radius + height);
    }

    double volume() const override {  // 求体积
        return M_PI * radius * radius * height;
    }
};

int main() {
    double var1, var2;  // 临时变量

    cout << "请输入立方体边长: ";
    cin >> var1;
    Cube c(var1);
    c.show();

    cout << "请输入球体半径: ";
    cin >> var1;
    Ball b(var1);
    b.show();

    cout << "请输入圆柱体底面半径和高: ";
    cin >> var1 >> var2;
    Cylinder cy(var1, var2);
    cy.show();

    return 0;
}
