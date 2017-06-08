/**
 *
 * �ļ���: demo.c
 * ��  ��: ����ʵ�ֹ������ݵĺ�������
 * ��  ��: �� ��
 *
 **/
#include "demo.h"
#include <stdlib.h>
#include <time.h>
int count=0;  //���ݵĸ���
int min,max;    //������ʾ��Χ
/* ���� */
void Data()
{

    for(;;)
    {
        printf("��������С��Χ:");
        scanf("%d",&min);
        getchar();
        printf("���������Χ:");
        scanf("%d",&max);
        getchar();
        printf("������Ҫ���ɵ���������:");
        scanf("%d",&count);
        getchar();
        if(count<=(max-min) && max>min)
            break;
        else
            printf("��������������޷���������\n");
    }
    int a[1000];      //�洢��
    GetData(a);         //�������
    char choose;
    for(;;)
    {
        Break();
        SortData(a);
        ShowData(a);
        printf("******************************************************\n");
        printf("1.�޸�����\n");
        printf("2.��������\n");
        printf("3.ɾ������\n");
        choose=getch();
        switch(choose)
        {
        case '1':
            ChangeData(a);
            break;
        case '2':
            AddData(a);
            break;
        case '3':
            DelData(a);
            break;
        default:
            printf("���޴˹���");
            break;
        }
    }

}
/* ��ӡ���� */
void ShowData(int *a)
{
    printf("Ŀǰ��������\n");
    for(int i=0;i<count;i++)
    {
        printf("(%d)%d ",i+1,a[i]);
    }
    printf("\n");
}
/* ������� */
void GetData(int *a)
{
    int key=0;        //�ж��Ƿ��ظ�
    srand(time(NULL));
    for(;;)
    {

        for(int i=0;i<count;i++)
        {
            int num;
            for(;;)
            {

                num=rand()%max+1;
                if(min <= num)
                    break;
            }
            a[i]=num;
        }
        for(int i=0;i<count-1;i++)
        {
            for(int j=i+1;j<count;j++)
            {
                if(a[i]==a[j])
                    key=1;
            }
        }
        if(key==0)
            break;
    }
}
/* �������� */
void SortData(int *a)
{
    for(int i=0;i<count-1;i++)
    {
        for(int j=i+1;j<count;j++)
        {
            int t;
            if(a[i]>a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
}
/* �޸����� */
void ChangeData(int *a)
{
    int n;
    printf("��ѡ��Ҫ�޸����ݵ�ֵ:");
    scanf("%d",&n);
    for(int i=0;i<count;i++)
    {
        if(n==a[i])
        {
            printf("Ҫ��%d�޸�Ϊ:",n);
            scanf("%d",a+i);
            break;
        }
    }

}
/* �������� */
void AddData(int *a)
{
    printf("������Ҫ��������:");
    scanf("%d",a+count);
    count++;
}
/* ɾ������ */
void DelData(int *a)
{
    int n;
    printf("������Ҫɾ������:");
    scanf("%d",&n);
    for(int i=0;i<count;i++)
    {
        if(a[i]==n)
        {
            for(int j=i;j<count;j++)
            {
                a[j]=a[j+1];
            }
            count--;
        }
    }
}
/* �������� */
void Break()
{
    Clear(0,0,100);
    SetPosition(0,0);
}




/* ���ù���λ�� */
void SetPosition(int x, int y)
{
    HANDLE winHandle;   //���
    COORD pos = {x, y};
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    //���ù�������
    SetConsoleCursorPosition(winHandle, pos);
}

/* ��x��y���꿪ʼ����rowCount�� */
void Clear(int x, int y, int rowCount)
{
    //һ���ַ���80��
    //ÿ��������ٸ����ַ�-��ӡ���ٸ��ո�
    int i, j;
    for(i = 0; i < rowCount; i++)
    {
        SetPosition(x, y + i);
        for(j = 0; j < 78; j++)
        {
            printf(" ");
        }
    }
}
