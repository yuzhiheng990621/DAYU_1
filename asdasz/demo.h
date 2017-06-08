#ifndef DEMO_H_INCLUDED
#define DEMO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
/* 数据 */
void Data();
/* 打印数据 */
void ShowData(int *a);
/* 获得数据 */
void GetData(int *a);
/* 数据排序 */
void SortData(int *a);
/* 修改数据 */
void ChangeData(int *a);
/* 新增数据 */
void AddData(int *a);
/* 删除数据 */
void DelData(int *a);
/* 清屏返回 */
void Break();


/* 设置光标的位置 */
void SetPosition(int x, int y);
/* 从x、y坐标开始，清rowCount行 */
void Clear(int x, int y, int rowCount);
#endif // DEMO_H_INCLUDED
