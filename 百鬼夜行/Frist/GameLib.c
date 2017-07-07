/**
 *
 * 文件名: GameLib.c
 * 描  述: 实现Game.h中定义的操作函数
 * 作  者: 大鱼
 *
 **/

 #include "GameLib.h"

/* 设置控制台标题 */
void SetTitle(char * title)
{
    SetConsoleTitle(title);
}

/* 设置文字前景色和背景色 */
void SetColor(int foreColor, int backColor)
{
    HANDLE winHandle;   //句柄
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    //设置文字颜色
    SetConsoleTextAttribute(winHandle, foreColor + backColor * 0x10);
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
