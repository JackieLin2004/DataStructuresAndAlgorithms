#include <stdio.h>
#include <stdlib.h>

#define MAXV 50
#define INF 32767

// MGraph �ṹ�嶨��
typedef struct {
    int n, e;             // ������n�ͱ���e
    int edges[MAXV][MAXV]; // �ڽӾ���洢�ߵ���Ϣ
} MGraph;

void Ppath(int path[][MAXV], int i, int j)  /*ǰ��ݹ����·���ϵĶ���*/
{
    int k;
    k = path[i][j];
    if (k == -1) return;    /*�ҵ�������򷵻�*/
    Ppath(path, i, k);    /*�Ҷ���i��ǰһ������k*/
    printf("%d,", k);
    Ppath(path, k, j);    /*�Ҷ���k��ǰһ������j*/
}

void Dispath(int A[][MAXV], int path[][MAXV], int n) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            if (A[i][j] == INF) {
                if (i != j)
                    printf("��%d��%dû��·��\n", i, j);
            } else {
                printf("  ��%d��%d=>·������:%d ·��:", i, j, A[i][j]);
                printf("%d,", i);    //���·���ϵ����
                Ppath(path, i, j);    //���·���ϵ��м��
                printf("%d\n", j);    //���·���ϵ��յ�
            }
        }
}

void Floyd(MGraph g) {
    /********** Begin **********/

    int A[MAXV][MAXV], path[MAXV][MAXV];
    int i, j, k, n = g.n;
    for (i = 0; i < n; i++)    //��A�����ó�ֵ
        for (j = 0; j < n; j++) {
            A[i][j] = g.edges[i][j];
            path[i][j] = -1;
        }
    for (k = 0; k < n; k++) {    //����Ak
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (A[i][j] > (A[i][k] + A[k][j])) {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = k;
                }
            }
        }
    }

    /********** End **********/
    Dispath(A, path, g.n);   /*������·��*/
}

int main() {
    int i, j;
    MGraph g;
    int n, e;
    int a[MAXV][MAXV];
    scanf("%d %d", &n, &e);
    g.n = n;
    g.e = e;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < g.n; i++)        /*����ͼ9.18��ʾ��ͼ���ڽӾ���*/
        for (j = 0; j < g.n; j++)
            g.edges[i][j] = a[i][j];
    printf("����������·��:\n");
    Floyd(g);
    return 0;
}
