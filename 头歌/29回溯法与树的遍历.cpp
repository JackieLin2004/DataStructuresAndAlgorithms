#include <stdio.h>
#include <stdlib.h>

#define MAXN 20              //���ʺ����
int q[MAXN];                 //��Ÿ��ʺ������к�
int count = 0;              //���һ����

void dispsolution(int n)     //���һ����
{
    printf("��%d���⣺", ++count);
    for (int i = 1; i <= n; i++) {
        printf("(%d,%d)", i, q[i]);
    }
    printf("\n");
}

bool place(int i)               //���Ե�i�е�q[i]�����ܷ�ڷŻʺ�
{
    int j = 1;
    if (i == 1)return true;
    while (j < i)                  //j=1~i-1���ѷ����˻ʺ����
    {
        if ((q[j] == q[i]) || (abs(q[j] - q[i]) == abs(j - i))) {
            //�ûʺ��Ƿ�����ǰ�Ļʺ�ͬ�У�λ��(j,q[j])��(i,q[i])�Ƿ�ͬ�Խ���
            return false;
        }
        j++;
    }
    return true;
}

void Queens(int n)                   //���n�ʺ�����
{
    int i = 1;                        //i��ʾ��ǰ�У�Ҳ��ʾ���õ�i���ʺ�
    q[i] = 0;                         //q[i]�ǵ�ǰ�У�ÿ���¿��ǵĻʺ�ĳ�ʼλ����Ϊ0��
    while (i >= 1)                     //��δ���ݵ�ͷ��ѭ��
    {
        /********** Begin **********/

        while (i >= 1) {
            q[i]++;
            while (q[i] <= n) {
                if (place(i)) {
                    if (i == n) {
                        dispsolution(n);  // ������
                        q[i]++;
                    } else {
                        i++;
                        q[i] = 0;  // ��һ�лʺ�λ�ó�ʼ��0
                        break;
                    }
                } else {
                    q[i]++;
                }
            }
            if (q[i] > n) {
                i--; // ����
            }
        }

        /********** End **********/
    }
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d�ʺ�������£�\n", n);
    Queens(n);
    return 0;
}