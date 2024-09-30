#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

//��ӡ����ĺ���
void print(LinkList &list) {
    LinkList p = list->next;
    if (p == NULL) {
        printf("����һ���ձ���û��Ԫ�أ�\n");
        return;
    }
    printf("����Ϊ��");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

//��ʼ������
bool InitList(LinkList &list) {
    list = (LNode *) malloc(sizeof(LNode));//����һ��ͷ���
    //list = new LNode();
    if (list == NULL) return false;//�ڴ治�㣬����ʧ��
    list->next = NULL;//ͷ���֮����ʱ��û�н��
    return true;
}

//ǰ��������ڽ��p֮ǰ������s
bool InsertPriorNode(LNode *p, LNode *s) {
    if (p == NULL || s == NULL) return false;
    s->next = p->next;
    p->next = s;
    int temp = p->data;
    p->data = s->data;
    s->data = temp;
    return true;
}

//ָ�����ĺ�����,����Ԫ��e
bool InsertNextNode(LNode *p, int e) {
    if (p == NULL) return false;
    LNode *temp = (LNode *) malloc(sizeof(LNode));
    if (temp == NULL) return false;//�ڴ����ʧ��
    temp->next = p->next;
    p->next = temp;
    temp->data = e;
    return true;
}

//��λ����룬�ڵ�i��λ�ò���ֵe
bool ListInsert(LinkList &list, int i, int e) {
    if (i < 1) return false;
    LNode *p = list;//ָ��p��ǰɨ�赽�Ľ��
    int j = 0;//��ʾj�ǵ�ǰpָ��ĵڼ������
//    p = list;
    while (p != NULL && j < i - 1) {//ѭ���ҵ���i-1�����
        p = p->next;
        j++;
    }
    /* �˴����Խ��з�װ����װ������InsertNextNode����ߴ��븴����
    * if (p == NULL) return false;
    LNode* temp = (LNode*)malloc(sizeof(LNode));
    temp->next = p->next;
    p->next = temp;
    temp->data = e;
    return true;
    */
    return InsertNextNode(p, e);//ע�⣬�����д����ͷ����÷������������ǰ��
}

//��λ��ɾ����㺯��
bool ListDelete(LinkList &list, int i, int &e) {
    if (i < 1) return false;
    LNode *p;
    int j = 0;
    p = list;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL || p->next == NULL) return false;
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

int main() {
    LinkList list;//����һ��ָ�������ָ��
    //��ʼ����ͷ���ĵ�������ֹ������
    InitList(list);
    print(list);

    //ֱ�Ӳ��뷨
    LinkList l1 = (LNode *) malloc(sizeof(LNode));
    list->next = l1;
    l1->data = 3;
    l1->next = NULL;
    print(list);

    //��λ�����
    if (ListInsert(list, 2, 7)) {
        printf("����ɹ���������Ϊ��");
        print(list);
    } else printf("����ʧ�ܣ����������Ƿ���ȷ��\n");

    //ǰ����������ڸó������ƣ�ֻ������ͷ����ǰ��
    LinkList l2 = (LNode *) malloc(sizeof(LNode));
    LNode *p;
    p = list;
    p = p->next;
    l2->data = 4;
    l2->next = NULL;
    if (InsertPriorNode(p, l2)) { //����ֱ�Ӵ�ͷ�����룬ͷ�����û��ֵ��ģ���ͷ������һ��
        printf("ǰ�����ɹ���������Ϊ��");
        print(list);
        printf("\n");
    } else printf("ǰ�����ʧ�ܣ����������Ƿ���ȷ��\n");
    //free(p);

    //��λ��ɾ��
    int e = -1;//��e��ɾ�������ݴ�����
    if (ListDelete(list, 3, e)) {
        printf("ɾ���ɹ���ɾ����Ԫ��Ϊ %d\n", e);
        printf("ɾ�����������Ϊ��");
        print(list);
    } else printf("ɾ��ʧ�ܣ����������Ƿ���ȷ��\n");

    //��ָ�����ɾ��
    return 0;
}