#include <stdio.h>
#include <stdlib.h>

/*
3
8 1
2 3
9 9
2
1 2
4 5
���:
La=8x+2x^3+9x^9
Lb=x^2+4x^5
������Ϊ��
Lc=8x+x^2+2x^3+4x^5+9x^9
*/

typedef struct PLnode {
    //������coef ��ʾϵ����expn ��ʾָ��
    float coef;
    int expn;
    //ָ����
    struct PLnode *next;
} PLnode, *PLinkList;

//һԪ����ʽ�������ʾ�������������� m ���ϵ����ָ����������ʾһԪ����ʽ����������L
void creatpolyn(PLinkList L, int m) {
    int i;
    float coef;
    int expn;
    PLinkList tail, n;
    L->coef = m;
    L->expn = -1;
    tail = L;
    for (i = 1; i <= m; i++) {
        n = (PLinkList) malloc(sizeof(PLnode));
        scanf("%f", &coef);
        scanf("%d", &expn);
        n->coef = coef;
        n->expn = expn;
        n->next = NULL;
        tail->next = n;
        tail = n;
    }
}

//��ɶ���ʽ������㣬�� Lc = La + Lb��������һԪ����ʽ Lb
PLinkList addpolyn(PLinkList La, PLinkList Lb) {
    int x, len;
    float y;
    PLinkList Lc, pa, pb, pc, u;
    Lc = La;
    len = 0;
    pc = Lc;
    //��pa��pb ָ��La ��Lb ����Ԫ���
    pa = La->next;
    pb = Lb->next;
    //ͨ�� pa��pb �������� La��Lb��ֻ����ָ��ͬʱ����ʱ������Ҫ����
    while (pa && pb) {
        x = pa->expn - pb->expn;
        //�ж�pa ��ָ����ָ����pb ��ָ���ָ���Ĵ�С��ϵ
        if (x < 0) {
            //���С������ȥ qa ��㵽Lc ��
            pc = pa;
            len++;
            pa = pa->next;
        }
            //�����ȣ����ж�������ϵ�����Ƿ�Ϊ0
        else if (x == 0) {
            // ���������Begin-End֮�䲹����룬���һԪ����ʽ����ӡ�
            /********** Begin *********/

            pa->coef = pa->coef + pb->coef;
            pc = pa;
            len++;
            pa = pa->next;
            pb = pb->next;

            /********** End **********/
        }
            //���pb ��ָ���ָ��ֵС����ժȡpb��ָ��㵽 LC������
        else {
            u = pb->next;
            pb->next = pa;
            pc->next = pb;
            pc = pb;
            len++;
            pb = u;
        }
    }
    //�������� La �Ͻ���һԪ����ʽ�ļӺͣ�����������й��� pa �����н�㣬��pb ���У�����Ҫ��pbʣ�������ӵ� Lc ��
    if (pb) {
        pc->next = pb;
    }
    //���� Lc �ĳ���
    while (pc) {
        pc = pc->next;
        if (pc) {
            len++;
        }
    }
    //Lc ��ͷ����м�¼Lc ����ĳ���
    Lc->coef = len;
    //�Ӻ���ɵ�ͬʱ���ͷ�Lb ���
    free(Lb);
    return Lc;
}

//��������洢��Ϣ�������� q
void printpoly(PLinkList q) {
    if (q->expn == 0) {
        printf("%.0f", q->coef);
    } else if (q->expn == 1) {
        if (q->coef == 1) {
            printf("x");
        } else if (q->coef == -1) {
            printf("-x");
        } else {
            printf("%.0f", q->coef);
            printf("x");
        }
    } else if (q->coef == 1) {
        printf("x^%d", q->expn);
    } else if (q->coef == -1) {
        printf("-x^%d", q->expn);
    } else {
        printf("%.0fx^%d", q->coef, q->expn);
    }
}

//���һԪ����ʽL
void printpolyn(PLinkList L) {
    int n;
    PLinkList p;
    p = L->next;
    n = 0;
    while (p) {
        n++;
        if (n == 1) {
            printpoly(p);
        } else if (p->coef > 0) {
            printf("+");
            printpoly(p);
        } else {
            printpoly(p);
        }
        p = p->next;
    }
}

int main() {
    PLinkList La, Lb, Lc;
    int m, n;
    //���� n ��ֵ����������La
    scanf("%d", &n);
    La = (PLinkList) malloc(sizeof(PLnode));
    creatpolyn(La, n);
    //���� m ��ֵ������ Lb
    scanf("%d", &m);
    Lb = (PLinkList) malloc(sizeof(PLnode));
    creatpolyn(Lb, m);
    //���La��Lb
    printf("La=");
    printpolyn(La);
    printf("\nLb=");
    printpolyn(Lb);
    //����La+Lb����������� Lc��
    printf("\n������Ϊ��");
    Lc = addpolyn(La, Lb);
    printf("\nLc=");
    printpolyn(Lc);
    return 0;
}