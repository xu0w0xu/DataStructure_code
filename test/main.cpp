#include "function.h"

typedef int ElemType;
typedef struct {
    ElemType* elem;//����ָ�룬����Ķѿռ����ʼ��ַ����elem
    int TableLen;//�洢��̬�������Ԫ�صĸ���
}SSTable;

void ST_Init(SSTable& ST, int len)
{
    //��������һ��λ��,Ϊ�˴��ڱ�,��ʹ���ڱ�Ҳ���ԣ�Ϊ�˺������鱣��һ��
    ST.TableLen = len + 1;
    ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
    int i;
    srand(time(NULL));//���������,���в���Ҫ����
    for (i = 1; i < ST.TableLen; i++)//��Ϊ��0�����ڱ������Դ�1���
    {
        ST.elem[i] = rand() % 100;//Ϊ��������ɵ�������0��99֮��
    }
}
//��ӡ˳���
void ST_print(SSTable ST)
{
    int i;
    for (i = 1; i < ST.TableLen; i++)
    {
        printf("%3d", ST.elem[i]);
    }
    printf("\n");
}

int Search_Seq(SSTable ST, ElemType key)
{
    ST.elem[0] = key;//key�������λ�ã���Ϊ�ڱ������������������ѭ��ʱ��������дһ��i>=0�ж�
    int i;
    for (i = ST.TableLen - 1; ST.elem[i] != key; i--);//�Ӻ���ǰ�ң��ҵ��ˣ�i���Ǹպ��Ƕ�Ӧ��λ��
    return i;
}
//˳�����
int main() {
    SSTable ST;
    ST_Init(ST, 10);
    ST_print(ST);//��ӡ˳�����Ԫ��
    ElemType key;
    printf("please input search key:\n");
    scanf("%d", &key);
    int pos;
    pos = Search_Seq(ST, key);
    if (pos)
    {
        printf("find key,pos=%d\n", pos);
    }
    else {
        printf("not find.\n");
    }
    return 0;
}
