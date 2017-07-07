#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "GameLib.h"
extern int X, Y;
int main()
{
    Init();
    SetTitle("                                                          百鬼夜行-大鱼魔改版.01v");
    SetColor(10,0);   //前景亮绿，背景黑
    char key;
    for(;;)
    {
    ShowMap();
    ShowMainMenu();
    ShowWelcome();
    key=getch();
        if(key == '1' || key == '2' || key == '3' || key == '4' || key == '5')
        {
            /* 处理用户的菜单选项 */
            ProcessMainMenu(key);
        }
        else if(key == VK_UP || key == 72)//用户按了上键
        {
            Y--;
        }
        else if(key == 39 || key == 77)//右
        {
            X++;
        }
        else if(key == 40 || key == 80)//下
        {
            Y++;
        }
        else if(key == 37 || key == 75)//左
        {
            X--;
        }
        if(X > 7) X = 0;
        if(X < 0) X = 7;
        if(Y > 7) Y = 0;
        if(Y < 0) Y = 7;

    }




    return 0;
}
