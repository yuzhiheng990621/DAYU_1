#ifndef GAMELIB_H_INCLUDED
#define GAMELIB_H_INCLUDED
/**********************************************
 * 文件名: GameLib.h
 * 描  述: 用来定义游戏中常用的系统操作
 * 作  者: 大鱼
 **********************************************/

#include <stdio.h>
#include <windows.h>
/* 设置控制台窗口的标题 */
void SetTitle(char *title);
/* 设置文字的前景色和背景色 */
/* 0-黑色, 1-蓝色,   2-绿色,      3-浅绿色,     4-红色,   5-紫色,   6-黄色,   7-白色,
 * 8-灰色, 9-淡蓝色, 10-淡绿色,   11-淡浅绿色   12-淡红色 13-淡紫色 14-淡黄色 15-亮白色
 */
void SetColor(int foreColor, int backColor);
/* 设置光标的位置 */
void SetPosition(int x, int y);
/* 从x、y坐标开始，清rowCount行 */
void Clear(int x, int y, int rowCount);


#endif // GAMELIB_H_INCLUDED
