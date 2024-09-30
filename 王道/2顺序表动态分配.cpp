#include <stdio.h>
#include <stdlib.h> //malloc��free�����ڴ�ͷ�ļ�

#define InitSize 10 // Ĭ����󳤶�
typedef struct {
    int *data;
    int MaxSize;
    int length;
} SqList;

//��ʼ����������ֹ��������
void InitList(SqList &list) {
    //��malloc��������һ�������Ĵ洢�ռ�
    list.data = (int *) malloc(sizeof(int) * InitSize);
    list.length = 0;
    list.MaxSize = InitSize;
}

void print(SqList &list) {
    for (int i = 0; i < list.length; i++)
        printf("%d ", list.data[i]);
}

//�������ݵĲ��뺯��
bool ListInsert(SqList &list, int i, int e) {
    if (i < 1 || i > list.length + 1) return false;
    if (list.length >= InitSize) return false;
    for (int j = list.length; j >= i; j--)
        list.data[j] = list.data[j - 1];
    list.length++;
    list.data[i - 1] = e;
    return true;
}

//���Ӷ�̬���鳤�ȵĺ���
void IncreaseSize(SqList &list, int len) {
    int *p = list.data;
    list.data = (int *) malloc(sizeof(int) * (list.MaxSize + len));
    for (int i = 0; i < list.length; i++)
        list.data[i] = p[i];
    list.MaxSize += len;
    free(p);
}

int main() {
    SqList list;
    InitList(list);
    //��˳������������һЩԪ��
    list.data[0] = 2;
    list.data[1] = 5;
    list.data[2] = 6;
    list.data[3] = 3;
    list.data[4] = 9;
    list.length = 5;
    print(list);
    //�������Ӷ�̬����ĳ���
    IncreaseSize(list, 10);
    //����������ڵ�i��λ�ò���Ԫ��e
    if (ListInsert(list, 3, 4)) {
        printf("\n������µ�����Ϊ: ");
        print(list);
    } else printf("\n��������ʧ�ܣ����������Ƿ���ȷ������");
    return 0;
}
