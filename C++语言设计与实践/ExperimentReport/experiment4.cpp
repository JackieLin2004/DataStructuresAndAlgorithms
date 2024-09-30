#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template<class T>
class Stack {
private:
    int size;  // ջ�ռ��С
    int top;   // ջָ��
    T *space;  // ��̬����ָ��
public:
    // ���캯��
    Stack(int s = 10) : size(s), top(-1) {
        if (size <= 0) {
            throw invalid_argument("�ڴ治�㣬����ռ�ʧ�ܣ�");
        }
        space = new T[size];
    }

    // ��������
    ~Stack() {
        delete[] space;
    }

    // ��ջ����
    bool push(const T &item) {
        if (IsFull()) {
            throw overflow_error("ջ�������޷�������ջ������");
        }
        space[++top] = item;
        return true;
    }

    // ��ջ����
    T pop() {
        if (IsEmpty()) {
            throw underflow_error("ջ�ѿգ��޷����г�ջ������");
        }
        return space[top--];
    }

    // �п�
    bool IsEmpty() const {
        return top == -1;
    }

    // ����
    bool IsFull() const {
        return top == size - 1;
    }
};

int main() {
    try {
        // ����ջ������ز���
        Stack<string> nameStack(10);
        nameStack.push("yi");
        nameStack.push("Xiao");
        nameStack.push("Lin");
        nameStack.push("�� ");
        nameStack.push("��");
        nameStack.push("��");
        cout << "����Ϊ��" << endl;
        while (!nameStack.IsEmpty()) {
            cout << nameStack.pop();
        }
        cout << endl;

        // ѧ��ջ������ز���
        Stack<int> idStack(5);
        idStack.push(76);
        idStack.push(11200);
        idStack.push(2022);
        cout << "ѧ��Ϊ��" << endl;
        while (!idStack.IsEmpty()) {
            cout << idStack.pop();
        }
        cout << endl;
        // ����ѧ��ջջ�յĳ�ջ�������Ƿ��׳��쳣
        idStack.pop();
    } catch (const exception &e) {
        cout << "����쳣��" << e.what() << endl;
    }
    return 0;
}