/**
 *
 * �ļ���: GameLib.c
 * ��  ��: ʵ��Game.h�ж���Ĳ�������
 * ��  ��: ����
 *
 **/

 #include "GameLib.h"

/* ���ÿ���̨���� */
void SetTitle(char * title)
{
    SetConsoleTitle(title);
}

/* ��������ǰ��ɫ�ͱ���ɫ */
void SetColor(int foreColor, int backColor)
{
    HANDLE winHandle;   //���
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    //����������ɫ
    SetConsoleTextAttribute(winHandle, foreColor + backColor * 0x10);
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
