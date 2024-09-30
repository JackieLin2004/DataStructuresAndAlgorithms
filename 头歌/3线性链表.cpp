#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
����
����
����
���:
�����������ɹ���
����
����
����
 */

struct stu {
    char name[32];
    struct stu *next;
};

/*������������n�ǳ�ʼ������ʱ���������ݸ���
prev��ָ��ǰ����ǰһ�����
cur��ָ��ǰ���
head�������ͷ����ָ��*/
struct stu *CreatList(int n) {
    int i;
    char age[12];
    struct stu *prev, *cur, *head;
    head = (struct stu *) malloc(sizeof(struct stu));
    if (head == NULL) {
        printf("Can't alloc memory\n");
        return NULL;
    }
    prev = head;
    head->name[0] = '\0';
    head->next = NULL;
    for (i = 1; i <= n; i++) {
        cur = (struct stu *) malloc(sizeof(struct stu));
        if (cur == NULL) {
            printf("Can't alloc memory\n");
            return NULL;
        }
        scanf("%s", cur->name);
        // ���������Begin-End֮�䲹����룬�����㡣
        /********** Begin *********/

        prev->next = cur;
        prev = prev->next;

        /********** End **********/
    }
    printf("�����������ɹ���\n");
    return head;
}

/*����������ӡ��������*/
void Print(struct stu *head) {
    struct stu *cur;
    cur = head->next;
    while (cur != NULL) {
        printf("%s\n", cur->name);
        cur = cur->next;
    }
}

int main() {
    int number = 3;
    char _name[32];
    struct stu *head, *cur, *fro;
    head = CreatList(number);
    if (head == NULL)
        return -1;
    Print(head);
    return 0;
}