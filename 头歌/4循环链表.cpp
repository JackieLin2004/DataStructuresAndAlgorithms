#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>

/*
12 66 88 30 0
���:
������������...
--------ѭ�������ʼԪ��------
12 	66 	88 	30
--------ɾ���ڶ�������------
12 	88 	30
*/

#define ERROR 0
#define OK 1
typedef int EleType;
typedef struct CLinkNode {
    EleType data;
    struct CLinkNode *next;
} CLinkNode, *CLinkList;

/*
��ʼ��ѭ������
*/
int InitCLinkList(CLinkList *list) {
    if (list == NULL) {
        return ERROR;
    }

    int data = 0;
    CLinkNode *target = NULL;
    CLinkNode *head_node = NULL;
    printf("������������...\n");
    while (1) {
        scanf("%d", &data);
        if (data == 0) {
            //�˳�ѭ����־���û�����0 ��ʾ������������
            break;
        }

        if (*list == NULL) {
            CLinkNode *head = (CLinkNode *) malloc(sizeof(CLinkNode));
            //������ռ�ʧ��
            if (head == NULL) {
                exit(0);
            }

            *list = head;//����ָ��ͷ���

            CLinkNode *node = (CLinkNode *) malloc(sizeof(CLinkNode));
            if (node == NULL) {
                exit(0);
            }
            node->data = data;
            node->next = head;
            head->next = node;
        } else {
            for (target = (*list)->next; target->next != *list; target = target->next);
            head_node = target->next;

            CLinkNode *node = (CLinkNode *) malloc(sizeof(CLinkNode));
            if (node == NULL) {
                exit(0);
            }
            node->data = data;
            node->next = head_node;

            target->next = node;//���½�����β��
        }

    }
    return OK;
}

/*
������ָ��λ�ò�������
list ѭ������
loc ��locλ�ò���Ԫ�أ�loc ��1 ��ʼ����
data ����Ԫ�ص�������
*/
int InsertCLinkNode(CLinkList list, int loc, EleType data) {
    if (list == NULL || loc < 1)
        return ERROR;
    /*
    ѭ��Ŀ�ģ��ҵ���loc-1λ�ý��
    */
    int i = 1;
    CLinkNode *node = list;//�տ�ʼnodeָ��ͷ���
    while (node->next != list && i < loc) {
        node = node->next;
        i++;
    }
    if (i == loc) {
        CLinkNode *new_node = (CLinkNode *) malloc(sizeof(CLinkNode));
        if (new_node == NULL) {
            exit(0);
        }
        new_node->data = data;
        new_node->next = node->next;//�½��ָ���� ָ��ǰ�����ĺ�̽��
        node->next = new_node;//���½���������
    } else {
        return ERROR;
    }

    return OK;
}

/*
ɾ��ָ����㣬ͨ��ָ�뷵��ɾ���������ݣ���������data
*/
int DelCLinkNode(CLinkList list, int loc, EleType *data) {
    if (list == NULL || loc < 1)
        return ERROR;
    /*
    ѭ��Ŀ�ģ��ҵ���loc-1λ�ý��
    */
    int i = 1;// ������Ķ��� i��ʾ��i��λ�� �� loc �����˼һ��
    CLinkNode *node = list;//�տ�ʼnodeָ��ͷ���
    while (node->next != list && i < loc) {
        node = node->next;
        i++;
    }
    //ѭ������ node ָ�� loc-1 λ�� �� node ����Ϊβ���,Ϊʲô����Ϊβ��㣿��Ϊ����ɾ�� λ����û��Ԫ�صĽ�㣡
    if (i == loc && node->next != list) {
        // ���������Begin-End֮�䲹����룬��ɶԽ���ɾ����
        /********** Begin *********/

        node->next = node->next->next;

        /********** End **********/

    }
    return OK;
}

/*
չʾѭ������Ԫ��
*/
int ShowCLinkList(CLinkList list) {
    if (list == NULL) {
        return ERROR;
    }
    CLinkNode *target = NULL;

    for (target = list->next; target != list; target = target->next)
        printf("%d \t", target->data);
    printf("\n");
    return OK;
}

int main(int argc, char *argv[]) {
    int flag = 0;
    CLinkList list = NULL;
    list = NULL;
    InitCLinkList(&list);
    printf("--------ѭ�������ʼԪ��------\n");
    ShowCLinkList(list);
    int loc = 2;
    int data = 0;
    DelCLinkNode(list, loc, &data);
    printf("--------ɾ���ڶ�������------\n");
    ShowCLinkList(list);
    return 0;
}