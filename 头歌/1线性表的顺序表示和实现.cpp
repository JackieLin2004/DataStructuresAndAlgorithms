#include <stdio.h>
#include <stdlib.h>

/*
6
5 9 11 31 6 90
0
9
���:
11  31  6  90
 */

typedef int T;

struct SeqList {
    T *data;   // ����Ԫ�ش洢�ռ�Ŀ�ʼ��ַ
    int len;   // ���Ա�ĵ�ǰ����
    int max;   // ���Ա����󳤶�
};

SeqList *SL_Create(int maxlen)
// ����һ��˳���
// ��SqLst_Free()��ԡ�
{
    SeqList *slist = (SeqList *) malloc(sizeof(SeqList));
    slist->data = (T *) malloc(sizeof(T) * maxlen);
    slist->max = maxlen;
    slist->len = 0;
    return slist;
}

void SL_Free(SeqList *slist)
// �ͷ�/ɾ�� ˳���
// ��SqLst_Create()��ԡ�
{
    free(slist->data);
    free(slist);
}

void SL_MakeEmpty(SeqList *slist)
// ��Ϊ�ձ�
{
    slist->len = 0;
}

int SL_Length(SeqList *slist)
// ��ȡ���ȡ�
{
    return slist->len;
}

bool SL_IsEmpty(SeqList *slist)
// �ж�˳����Ƿ�ա�
{
    return 0 == slist->len;
}

bool SL_IsFull(SeqList *slist)
// �ж�˳����Ƿ�����
{
    return slist->len == slist->max;
}

T SL_GetAt(SeqList *slist, int i)
// ��ȡ˳���slist�ĵ�i�Ž�����ݡ�
// ���ص�i�Ž���ֵ��
{
    if (i < 0 || i >= slist->len) {
        printf("SL_GetAt(): location error when reading elements of the slist!\n");
        SL_Free(slist);
        exit(0);
    } else
        return slist->data[i];
}

void SL_SetAt(SeqList *slist, int i, T x)
// ���õ�i�Ž���ֵ���Ե�i�Ž������ݽ���д����
{
    if (i < 0 || i >= slist->len) {
        printf("SL_SetAt(): location error when setting elements of the slist!\n");
        SL_Free(slist);
        exit(0);
    } else
        slist->data[i] = x;
}

bool SL_InsAt(SeqList *slist, int i, T x)
// ��˳����λ��i������x, ����d[i]֮ǰ��
// i ����Ч��Χ[0,plist->len]��
{
    // ���������Begin-End֮�䲹����룬�����㡣
    /********** Begin *********/

    if (slist->len == slist->max) return false;
    for (int j = slist->len; j > i; j--) slist->data[j] = slist->data[j - 1];
    slist->len++;
    slist->data[i] = x;
    return true;

    /********** End **********/
}

T SL_DelAt(SeqList *slist, int i)
// ɾ��˳���plist�ĵ�i�Ž�㡣
// i����Ч��ΧӦ��[0,plist->len)�ڣ����������쳣�����
// ���ر�ɾ��������Ԫ�ص�ֵ��
{
    // �������Begin-End֮�䲹����룬ɾ����i�Ž�㡣
    /********** Begin *********/

    T e = slist->data[i];
    for (int j = i + 1; j < slist->len; j++)
        slist->data[j - 1] = slist->data[j];
    slist->len--;
    return e;

    /********** End **********/
}

int SL_FindValue(SeqList *slist, T x)
// ��˳�����в��ҵ�һ��ֵΪx�Ľ�㣬���ؽ��ı�š�
// ����ֵ���ڵ���0ʱ��ʾ�ҵ�ֵΪx�Ľ��ı�ţ�-1��ʾû���ҵ���
{
    int i = 0;
    while (i < slist->len && slist->data[i] != x) i++;
    if (i < slist->len) return i;
    else return -1;
}

int SL_DelValue(SeqList *slist, T x)
// ɾ����һ��ֵΪx�Ľ�㡣
// ����ֵΪx�Ľ���򷵻ؽ����, δ�ҵ����أ�1��
{
    // �������Begin-End֮�䲹����룬ɾ����һ��ֵΪ x �Ľ�㡣
    /********** Begin *********/

    int e = -1;
    for (int i = 0; i < slist->len; i++) {
        if (slist->data[i] == x) {
            e = i;
            for (int j = i + 1; j < slist->len; j++)
                slist->data[j - 1] = slist->data[j];
            slist->len--;
            break;
        }
    }
    return e;

    /********** End **********/
}

void SL_Print(SeqList *slist)
// ��ӡ����˳���
{
    if (slist->len == 0) {
        printf("The slist is empty.\n");
        return;
    }

    //printf("The slist contains: ");
    for (int i = 0; i < slist->len; i++) {
        printf("%d  ", slist->data[i]);
    }

    printf("\n");

}

int main() {
    //�������Ա����ɴ洢��Ԫ�ظ���max
    int max = 100;
//����һ������Ϊmax�Ŀ����Ա�
    SeqList *slist = SL_Create(max);
//�������������Ա�ǰ����n
    int n;
    scanf("%d", &n);
    int i;
    int item;
    //ѭ������n�������������뵽���Ա���
    for (i = 0; i < n; i++) {
        scanf("%d", &item);
        SL_InsAt(slist, i, item);
    }
//����һ������idel���������Ա���λ��idel��������Ԫ��ɾ��
    int idel;
    scanf("%d", &idel);
    SL_DelAt(slist, idel);
    //����һ��������itemdel���������Ա��е�һ�γ��ָ�ֵ������Ԫ��ɾ��
    int itemdel;
    scanf("%d", &itemdel);
    SL_DelValue(slist, itemdel);
    SL_Print(slist);

//�ͷ����Ա�ռ�
    SL_Free(slist);
}