#include <stdio.h>
#include <stdlib.h>

/*
4 1 3 0 8 9
���:
����������...
����ṹΪ��4 <-> 1 <-> 3 <-> 0 <-> 8 <-> 9
�����е� 4 ���ڵ��ֱ��ǰ���ǣ�3
*/

//�ڵ�ṹ
typedef struct line {
    struct line *prior;
    int data;
    struct line *next;
} line;

//˫����Ĵ�������
line *initLine(line *head);

//���˫����ĺ���
void display(line *head);

int main() {
    //����һ��ͷָ��
    line *head = NULL;
    //��������������
    head = initLine(head);
    printf("����ṹΪ��");
    //��������õ�����
    display(head);
    //��ʾ˫������ŵ�
    printf("�����е� 4 ���ڵ��ֱ��ǰ���ǣ�%d", head->next->next->next->prior->data);
    return 0;
}

line *initLine(line *head) {
    printf("����������...\n");
    int data[6] = {0};
    for (int i = 0; i < 6; i++) {
        scanf("%d", &data[i]);
    }
    line *list = NULL;
    //����һ����Ԫ�ڵ㣬�����ͷָ��Ϊhead
    head = (line *) malloc(sizeof(line));
    //�Խڵ���г�ʼ��
    head->prior = NULL;
    head->next = NULL;
    head->data = data[0];
    //����һ��ָ����Ԫ�ڵ��ָ�룬�������������������´����Ľڵ�
    list = head;
    for (int i = 1; i <= 5; i++) {

        // ���������Begin-End֮�䲹����룬�����㣬���н������Ϊdata[i]��
        /********** Begin *********/

        line *node = (line *) malloc(sizeof(line));
        node->data = data[i];
        node->prior = list;
        node->next = NULL;
        list->next = node;
        list = node;

        /********** End **********/
    }
    //�����´���������
    return head;
}

void display(line *head) {
    line *temp = head;
    while (temp) {
        //����ýڵ��޺�̽ڵ㣬˵���˽ڵ�����������һ���ڵ�
        if (temp->next == NULL) {
            printf("%d\n", temp->data);
        } else {
            printf("%d <-> ", temp->data);
        }
        temp = temp->next;
    }
}