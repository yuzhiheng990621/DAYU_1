#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
/**********************************************
 * �ļ���: Game.h
 * ��  ��: ��������һЩ���Ľṹ�ͺ���
 * ��  ��: ����
 **********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/******************** ��Ϸ�Ľṹ���Ͷ��� *******************/
//��ҡ���ͼ��װ�������
/* ��Ϸ��ͼ�ṹ ��Ϸ��ͼ
   ��š����ơ����ܡ���ҵĽ���ȼ� */
typedef struct _map{
    int id;             //��ͼ���
    char name[50];      //����
    int minLevel;       //�����ͽ���ȼ�
    /* ����ṹ */
    COORD coord;        //��ͼ����
    char desc[2000];     //��ͼ�Ľ���
}Map;
/* ��Ϸ��������ö�� - ���������ߣ�����Ʒ����Ƭ����Ƭ */
typedef enum _proptype{
    Weapon, Armor, Con, Card, Frag
}PropType;
/* ��Ϸ���� - ���������ߡ�����Ʒ����Ƭ����Ƭ */
typedef struct _prop{
    int id;             //���߱��
    char name[50];      //��������
    int level;          //���߼���
    int stock;          //���߿��
    int price;           //���ߵ���
    PropType type;      //���ߵ�����
    union{//���� - ��ѡһ
        int Attack;     //���� - ������
        int Defence;    //���� - ������
        int Power;      //����Ʒ - ����ֵ
    };
    char desc[1000];        //���ߵĹ�������
}Prop;
/* �����ṹ */
typedef struct _bag{
    int id;             //���
    int count;          //��ǰ��������
    int max;            //�����ӵ�еĵ�������
    Prop props[162];      //����
}Bag;
/* ���ɽṹ */
typedef struct _martial{
    int id;
    char name[50];
    char type[50];  //��æ����  ̫�ţ��Ϲţ�����������
    char desc[1000];//��������
    COORD hqCoord;
    int isOpen;     //�����Ƿ񿪷�
}Martial;
/* ��ҽṹ */
typedef struct _player{
    int id;                 //��ұ��
    char name[50];          //�������
    char pass[50];          //�������
    int hp;                 //��ҵ�����ֵ
    int hpmax;              //��ҵ���������
    int mp;                 //��ҵ�ħ��ֵ
    int mpMax;              //��ҵ�ħ������
    int level;              //��ҵļ���
    int exp;                //��ҵľ���ֵ
    int gold;               //��ҵĽ������
    COORD coord;            //��ҵ�ǰ���ڵ�ͼ������
    Martial martial;        //�������
    Prop weapon;            //���װ��������
    Prop armor;             //���װ���ķ���
    Bag bag;                //��ҵı���
}Player;
typedef struct _monster{
    int id;                 //����ı��
    char name[50];          //���������
    int level;              //����ĵȼ�
    int hp;                 //���������ֵ
    int att;                //����Ĺ�����
    int def;                //����ķ�����
    int Money;           //���������
    int exp;                //������侭��
    //��չ: ������ߵ���
    int state;              //���ﵱǰ��״̬��0���������
    COORD coord;            //���������
}Monster;




/* ��ʼ����Ϸ���� */
void Init();
/* ��ʾȫ������ */
void Show();
/* ��ʾ��Ϸ�Ļ�ӭ��Ϣ */
void ShowWelcome();
/* ��ʾ��Ϸ��ͼ */
void ShowMap();
/* ����Ϣ������ʾ��ǰ��ͼ����Ϣ */
void ShowMapInfo();
/* ��ʾ��ͼ�·�����Ϣ�� */
void ShowInfomation();
/* ��ʾ��Ϸ�����˵� */
void ShowMainMenu();
/* ����Ϣ������ʾ��ҵĸ������� */
void ShowPlayerInfo();
/* ��ʾ��ұ�����Ϣ */
void ShowBag();
/* ��ʾ��ͼ�Ĺ��� */
void ShowMonsters();
/* �����û��Ĳ˵�ѡ�� */
void ProcessMainMenu(char key);
/* ˢ�ֵķ��� */
void Fight(Monster *monster);
/* ���س��� */
void Move(int x,int y);
/* �̳� */
void Shop();
/* ��ʾ�̳�������Ʒ��Ϣ */
void ShowShop();
/* �̳ǽ��� */
void Shopping(Prop *prop);









#endif // GAME_H_INCLUDED
