#include<stdio.h>
#include<stdlib.h>

typedef struct OLNode {
    int i, j, e; //������Ԫ��i������ j������ e����ǰλ�õ�����
    struct OLNode *right, *down; //ָ���� ��ָ�� ��ָ��
} OLNode, *OLink;
typedef struct {
    OLink *rhead, *chead; //�к�������ͷָ��
    int mu, nu, tu;  //���������,�����ͷ���Ԫ�ĸ���
} CrossList;

CrossList CreateMatrix_OL(CrossList M);

void display(CrossList M);

int main() {
    CrossList M;
    M.rhead = NULL;
    M.chead = NULL;
    M = CreateMatrix_OL(M);
    printf("�������M:\n");
    display(M);
    return 0;
}

CrossList CreateMatrix_OL(CrossList M) {
    int m, n, t;
    int i, j, e;
    OLNode *p, *q;
    printf("�������������������ͷ�0Ԫ�ظ�����");
    scanf("%d%d%d", &m, &n, &t);
    M.mu = m;
    M.nu = n;
    M.tu = t;
    if (!(M.rhead = (OLink *) malloc((m + 1) * sizeof(OLink))) ||
        !(M.chead = (OLink *) malloc((n + 1) * sizeof(OLink)))) {
        printf("��ʼ������ʧ��");
        exit(0);
    }
    for (i = 1; i <= m; i++) {
        M.rhead[i] = NULL;
    }
    for (j = 1; j <= n; j++) {
        M.chead[j] = NULL;
    }
    for (scanf("%d%d%d", &i, &j, &e); 0 != i; scanf("%d%d%d", &i, &j, &e)) {
        if (!(p = (OLNode *) malloc(sizeof(OLNode)))) {
            printf("��ʼ����Ԫ��ʧ��");
            exit(0);
        }
        p->i = i;
        p->j = j;
        p->e = e;
        //���ӵ��е�ָ��λ��
/*** �����·���д��Ĵ��� *********/
/************* begin **************/

// ���ӵ��е�ָ��λ��
        if (M.rhead[i] == NULL) {
            M.rhead[i] = p;
            p->right = NULL;
        } else {
            p->right = M.rhead[i]->right;
            M.rhead[i]->right = p;
        }
        
// ���ӵ��е�ָ��λ��
        if (M.chead[j] == NULL) {
            M.chead[j] = p;
            p->down = NULL;
        } else {
            p->down = M.chead[j]->down;
            M.chead[j]->down = p;
        }

/************** end ***************/
        //���ӵ��е�ָ��λ��

    }
    return M;
}

void display(CrossList M) {
    for (int i = 1; i <= M.nu; i++) {
        if (NULL != M.chead[i]) {
            OLink p = M.chead[i];
            while (NULL != p) {
                printf("%d\t%d\t%d\n", p->i, p->j, p->e);
                p = p->down;
            }
        }
    }
}