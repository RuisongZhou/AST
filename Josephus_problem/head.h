#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
typedef struct CirNode {
    int data;//����
    int number;//���
    struct CirNode *next;
}CirNode, *CirList;


void createCirList(CirList *L, int n);//�������ɳ���Ϊn��ѭ������
void JosephCircle(CirList *L, int m);//�����������Լɪ�򻷵Ľ���


#endif // HEAD_H_INCLUDED
