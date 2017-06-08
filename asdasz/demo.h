#ifndef DEMO_H_INCLUDED
#define DEMO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
/* ���� */
void Data();
/* ��ӡ���� */
void ShowData(int *a);
/* ������� */
void GetData(int *a);
/* �������� */
void SortData(int *a);
/* �޸����� */
void ChangeData(int *a);
/* �������� */
void AddData(int *a);
/* ɾ������ */
void DelData(int *a);
/* �������� */
void Break();


/* ���ù���λ�� */
void SetPosition(int x, int y);
/* ��x��y���꿪ʼ����rowCount�� */
void Clear(int x, int y, int rowCount);
#endif // DEMO_H_INCLUDED
