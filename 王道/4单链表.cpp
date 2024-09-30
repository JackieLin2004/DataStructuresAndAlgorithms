#include <stdio.h>
#include <stdlib.h>

//�ô�����ͷ�巨��β�巨����������ͷ���ĵ�����������һϵ�еĲ���

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

//ר�Ŵ�ӡ����ĺ���
void PrintList(LinkList &list) {
    LinkList p = list->next;
    if (p == NULL) printf("������Ϊ�գ�����Ϊ������Ԫ�أ�\n");
    else {
        printf("����Ϊ: ");
        while (p != NULL) {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
    free(p);
}

//ͷ�巨����������
LinkList List_HeadCreate(LinkList &list) {
    LNode *p;    //����ÿ�β���Ľ��
    int x;    //��������ֵ
    list = (LinkList) malloc(sizeof(LNode));    //Ϊlist�ȷ���һ��ͷ���
    list->next = NULL;
    scanf("%d", &x);
    while (x != 999) {    //���뵽999��ʱ��ֹͣ���룬�Զ���һ��ֹͣ��ֵ
        p = (LNode *) malloc(sizeof(LNode));
        p->data = x;
        p->next = list->next;
        list->next = p;
        scanf("%d", &x);
    }
    return list;
}

//β�巨����������
LinkList List_TailCreate(LinkList &list) {
    LNode *p;    //����ÿ�β���Ľ��
    int x;    //��������ֵ
    list = (LinkList) malloc(sizeof(LNode));    //Ϊlist�ȷ���һ��ͷ���
    LNode *q = list;    //qΪ��βָ��
    scanf("%d", &x);
    while (x != 999) {
        p = (LNode *) malloc(sizeof(LNode));
        p->data = x;
        q->next = p;
        q = p;
        scanf("%d", &x);
    }
    q->next = NULL;
    return list;
}

//�����������λ��i����Ԫ��e
bool List_Insert(LinkList &list, int i, int e) {
    if (i < 1) return false;
    LNode *p = list;    //��ʾ��ǰɨ�赽�Ľ��
    int j = 0;     //��ǰpָ����ǵڼ������
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) return false;    //��Ҫ��p�ĺ�����룬���pΪNULL��û�в���ı�Ҫ��
    LNode *temp = (LNode *) malloc(sizeof(LNode));
    if (temp == NULL) return false;    //�ڴ����ʧ��
    temp->data = e;
    temp->next = p->next;
    p->next = temp;
    return true;
}

//ɾ��������ɾ��λ��i��Ԫ�ز���e���������
bool List_Delete(LinkList &list, int i, int &e) {
    if (i < 1) return false;
    LNode *p = list;    //��ʾ��ǰɨ�赽�Ľ��
    int j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL || p->next == NULL) return false;    //Ҫɾp����һ��������������һ��ΪNULL��û��ɾ���ı�Ҫ
    e = p->next->data;
    p->next = p->next->next;
    return true;
}

int main() {
    //����ͷ�巨������һ��������list1
    LinkList list1 = List_HeadCreate(list1);
    PrintList(list1);
    printf("%d", list1->next->data);
    //Ȼ����β�巨������һ��������list2
    LinkList list2 = List_TailCreate(list2);
    PrintList(list2);
    //��list1��λ��i����Ԫ��e���˴�ע��ǰ��ͺ������������ǰ��Ļ�ִ�к�岢����ֵ����
    if (List_Insert(list1, 2, 8)) {
        printf("����ɹ���������Ϊ: ");
        PrintList(list1);
    } else printf("����ʧ�ܣ����������Ƿ���ȷ��\n");
    //��list2ɾ����λ��i��Ԫ�أ�����e���������
    int e = 0;
    if (List_Delete(list2, 2, e)) {
        printf("ɾ���ɹ���ɾ����Ԫ��Ϊ: %d ! ������Ϊ: ", e);
        PrintList(list2);
    } else printf("ɾ��ʧ�ܣ����������Ƿ���ȷ��\n");
    return 0;
}