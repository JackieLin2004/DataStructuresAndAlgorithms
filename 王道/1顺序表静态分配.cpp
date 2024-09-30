#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int length;
} SqList;

//ר������Ĵ�ӡ����
void print(SqList &list) {
    for (int i = 0; i < list.length; i++)
        printf("%d ", list.data[i]);
}

//��ʼ����������ֹ��������
void InitList(SqList &list) {
    for (int i = 0; i < MaxSize; i++)
        list.data[i] = 0;
    list.length = 0;
}

//�������ݵĲ��뺯��
bool ListInsert(SqList &list, int i, int e) {
    if (i < 1 || i > list.length + 1) return false;
    if (list.length >= MaxSize) return false;
    for (int j = list.length; j >= i; j--)
        list.data[j] = list.data[j - 1];
    list.length++;
    list.data[i - 1] = e;
    return true;
}

//ɾ�����ݵ�ɾ������
/*bool ListDelete(SqList &list, int i, int &e) {
    if (i < 1 || i > list.length + 1) return false;
    e = list.data[i - 1];
    for (int j = i; j < list.length; j++)
        list.data[j - 1] = list.data[j];
    list.length--;
    return true;
}*/
bool ListDelete(SqList &list, int i, int &e) {
    if (i < 1 || i > list.length + 1) return false;
    e = list.data[i - 1];
    for (int j = i - 1; j < list.length - 1; j++)
        list.data[j] = list.data[j + 1];
    list.length--;
    return true;
}

//��λ���Һ���
int getValue1(SqList &list, int e) {
    if (e < 1 || e > list.length) return -1;
    else return list.data[e - 1];
}

//��ֵ���Һ�������󷵻ص���λ��
int getValue2(SqList &list, int e) {
    for (int i = 0; i < list.length; i++)
        if (list.data[i] == e)
            return i + 1;
    return 0;
}

int main() {
    SqList list;
    InitList(list);
    //һЩ����ĸ�ֵ
    list.data[0] = 2;
    list.data[1] = 5;
    list.data[2] = 6;
    list.data[3] = 3;
    list.data[4] = 9;
    list.length = 5;
    print(list);
    //����������ڵ�i��λ�ò���Ԫ��e
    if (ListInsert(list, 3, 4)) {
        printf("\n������µ�����Ϊ: ");
        print(list);
    } else printf("\n��������ʧ�ܣ����������Ƿ���ȷ������");

    //ɾ����i��Ԫ�أ�����e��ɾ����Ԫ�ش�����
    int e = -1;
    if (ListDelete(list, 4, e)) {
        printf("\nɾ�����µ�����Ϊ: ");
        print(list);
    } else printf("\nɾ������ʧ�ܣ����������Ƿ���ȷ������");

    //��λ����
    if (getValue1(list, 6) == -1)
        printf("\n�����������λ���Ƿ���ȷ��");
    else
        printf("\n��λ��Ԫ�ص�ֵ�� %d", getValue1(list, 6));
    //��ֵ���ң����õ���һ����ֵ��λ��
    if (getValue2(list, 9))
        printf("\n��Ԫ�ص�λ���ǵ� %d ��", getValue2(list, 9));
    else
        printf("\n�����������λ���Ƿ���ȷ��");
    return 0;
}

