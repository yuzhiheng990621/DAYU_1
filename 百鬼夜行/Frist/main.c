#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "GameLib.h"
extern int X, Y;
int main()
{
    Init();
    SetTitle("                                                          �ٹ�ҹ��-����ħ�İ�.01v");
    SetColor(10,0);   //ǰ�����̣�������
    char key;
    for(;;)
    {
    ShowMap();
    ShowMainMenu();
    ShowWelcome();
    key=getch();
        if(key == '1' || key == '2' || key == '3' || key == '4' || key == '5')
        {
            /* �����û��Ĳ˵�ѡ�� */
            ProcessMainMenu(key);
        }
        else if(key == VK_UP || key == 72)//�û������ϼ�
        {
            Y--;
        }
        else if(key == 39 || key == 77)//��
        {
            X++;
        }
        else if(key == 40 || key == 80)//��
        {
            Y++;
        }
        else if(key == 37 || key == 75)//��
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
