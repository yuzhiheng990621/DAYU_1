#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
/**********************************************
 * 文件名: Game.h
 * 描  述: 用来定义一些核心结构和函数
 * 作  者: 大鱼
 **********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/******************** 游戏的结构类型定义 *******************/
//玩家、地图、装备、怪物、
/* 游戏地图结构 游戏地图
   编号、名称、介绍、玩家的进入等级 */
typedef struct _map{
    int id;             //地图编号
    char name[50];      //名称
    int minLevel;       //玩家最低进入等级
    /* 坐标结构 */
    COORD coord;        //地图坐标
    char desc[2000];     //地图的介绍
}Map;
/* 游戏道具类型枚举 - 武器，防具，消耗品，卡片，碎片 */
typedef enum _proptype{
    Weapon, Armor, Con, Card, Frag
}PropType;
/* 游戏道具 - 武器、防具、消耗品、卡片、碎片 */
typedef struct _prop{
    int id;             //道具编号
    char name[50];      //道具名称
    int level;          //道具级别
    int stock;          //道具库存
    int price;           //道具单价
    PropType type;      //道具的类型
    union{//联合 - 多选一
        int Attack;     //武器 - 攻击力
        int Defence;    //防具 - 防御力
        int Power;      //消耗品 - 增益值
    };
    char desc[1000];        //道具的功能描述
}Prop;
/* 背包结构 */
typedef struct _bag{
    int id;             //编号
    int count;          //当前道具种类
    int max;            //最多能拥有的道具种类
    Prop props[162];      //道具
}Bag;
/* 帮派结构 */
typedef struct _martial{
    int id;
    char name[50];
    char type[50];  //帮忙类型  太古，上古，隐世，世俗
    char desc[1000];//门派描述
    COORD hqCoord;
    int isOpen;     //门派是否开放
}Martial;
/* 玩家结构 */
typedef struct _player{
    int id;                 //玩家编号
    char name[50];          //玩家名称
    char pass[50];          //玩家密码
    int hp;                 //玩家的生命值
    int hpmax;              //玩家的生命上限
    int mp;                 //玩家的魔力值
    int mpMax;              //玩家的魔力上限
    int level;              //玩家的级别
    int exp;                //玩家的经验值
    int gold;               //玩家的金币数量
    COORD coord;            //玩家当前所在地图的坐标
    Martial martial;        //玩家门派
    Prop weapon;            //玩家装备的武器
    Prop armor;             //玩家装备的防具
    Bag bag;                //玩家的背包
}Player;
typedef struct _monster{
    int id;                 //怪物的编号
    char name[50];          //怪物的名字
    int level;              //怪物的等级
    int hp;                 //怪物的生命值
    int att;                //怪物的攻击力
    int def;                //怪物的防御力
    int Money;           //怪物掉落金币
    int exp;                //怪物掉落经验
    //扩展: 怪物道具掉落
    int state;              //怪物当前的状态，0死，非零活
    COORD coord;            //怪物的坐标
}Monster;




/* 初始化游戏数据 */
void Init();
/* 显示全局数据 */
void Show();
/* 显示游戏的欢迎信息 */
void ShowWelcome();
/* 显示游戏地图 */
void ShowMap();
/* 在信息界面显示当前地图的信息 */
void ShowMapInfo();
/* 显示地图下方的信息框 */
void ShowInfomation();
/* 显示游戏的主菜单 */
void ShowMainMenu();
/* 在信息界面显示玩家的个人资料 */
void ShowPlayerInfo();
/* 显示玩家背包信息 */
void ShowBag();
/* 显示地图的怪物 */
void ShowMonsters();
/* 处理用户的菜单选项 */
void ProcessMainMenu(char key);
/* 刷怪的方法 */
void Fight(Monster *monster);
/* 返回城镇 */
void Move(int x,int y);
/* 商城 */
void Shop();
/* 显示商城已有商品信息 */
void ShowShop();
/* 商城交易 */
void Shopping(Prop *prop);









#endif // GAME_H_INCLUDED
