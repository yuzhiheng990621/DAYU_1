/**
 *
 * 文件名: demo.c
 * 描  述: 用于实现关于数据的函数功能
 * 作  者: 大 鱼
 *
 **/
#include "demo.h"
#include <stdlib.h>
#include <time.h>
int count=0;  //数据的个数
int min,max;    //用来表示范围
/* 数据 */
void Data()
{

    for(;;)
    {
        printf("请输入最小范围:");
        scanf("%d",&min);
        getchar();
        printf("请输入最大范围:");
        scanf("%d",&max);
        getchar();
        printf("请输入要生成的整数个数:");
        scanf("%d",&count);
        getchar();
        if(count<=(max-min) && max>min)
            break;
        else
            printf("输入的条件有误，无法生成数据\n");
    }
    int a[1000];      //存储数
    GetData(a);         //获得数据
    char choose;
    for(;;)
    {
        Break();
        SortData(a);
        ShowData(a);
        printf("******************************************************\n");
        printf("1.修改数据\n");
        printf("2.新增数据\n");
        printf("3.删除数据\n");
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
            printf("暂无此功能");
            break;
        }
    }

}
/* 打印数据 */
void ShowData(int *a)
{
    printf("目前数据如下\n");
    for(int i=0;i<count;i++)
    {
        printf("(%d)%d ",i+1,a[i]);
    }
    printf("\n");
}
/* 获得数据 */
void GetData(int *a)
{
    int key=0;        //判断是否重复
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
/* 数据排序 */
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
/* 修改数据 */
void ChangeData(int *a)
{
    int n;
    printf("请选择要修改数据的值:");
    scanf("%d",&n);
    for(int i=0;i<count;i++)
    {
        if(n==a[i])
        {
            printf("要将%d修改为:",n);
            scanf("%d",a+i);
            break;
        }
    }

}
/* 新增数据 */
void AddData(int *a)
{
    printf("请输入要新增的数:");
    scanf("%d",a+count);
    count++;
}
/* 删除数据 */
void DelData(int *a)
{
    int n;
    printf("请输入要删除的数:");
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
/* 清屏返回 */
void Break()
{
    Clear(0,0,100);
    SetPosition(0,0);
}




/* 设置光标的位置 */
void SetPosition(int x, int y)
{
    HANDLE winHandle;   //句柄
    COORD pos = {x, y};
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    //设置光标的坐标
    SetConsoleCursorPosition(winHandle, pos);
}

/* 从x、y坐标开始，清rowCount行 */
void Clear(int x, int y, int rowCount)
{
    //一行字符有80个
    //每行清除多少个个字符-打印多少个空格
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
