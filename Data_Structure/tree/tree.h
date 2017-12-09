#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include<stdbool.h>

#define SLEN 20
typedef struct item
{
    int depth;
    int data;
}Item;

#define MAXITEMS 10

typedef struct treenode
{
    Item item;
    struct treenode *left;
    struct treenode *right;
}TREEnode;

typedef struct tree
{
    TREEnode *root;
    int size;
}Tree;

void InitializeTree (Tree *ptree);
bool Treeisempty ( const Tree *ptree );
bool Treeisfull ( const Tree *ptree );
int TreeItemCount( const Tree*ptree );  //ȷ����������
bool AddItem ( const Item *pi , Tree *ptree );
bool DeleteItem ( const Item *pi, Tree *ptree );
bool InTree ( const Item *pi , Tree *ptree ); //������
void Traverse ( const Tree * ptree , void(*pfun)(Item item)); //�Ѻ���Ӧ��������ÿһ��
void DeleteAll ( Tree *ptree );

#endif // TREE_H_INCLUDED
