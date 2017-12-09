#include "tree.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct pair
{
    TREEnode *parent;
    TREEnode *child;
}Pair;

static bool ToLeft (const Item *p1 , const Item *p2 )
{
    if ( p1->data > p2->data )
        return true;
    else
        return false;
}
static bool ToRight (const Item *p1 , const Item *p2 )
{
    if ( p1->data < p2->data )
        return true;
    else
        return false;
}

static TREEnode * MakeNode (const Item *pi)
{
    TREEnode *newnode;
    newnode = (TREEnode*)malloc(sizeof(TREEnode));
    if ( newnode )
    {
        newnode->left = NULL;
        newnode->left = NULL;
        newnode->item = *pi;
    }
    return newnode;
}

static Pair SeekItem (const Item *pi , const Tree *ptree ) //查找相同项
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;
    if( look.child == NULL )
        return look;
    while( look.child )
    {
        if(ToLeft( pi , &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if(ToRight( pi , &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else
            break;
    }
    return look;
}

static void AddNode ( TREEnode *newnode , TREEnode *root )
{
    if ( ToLeft( &newnode->item , &root->item ))
    {
        if (root->left == NULL)
            root->left = newnode;
        else
            AddNode( newnode , root->left );
    }
    else if ( ToRight( &newnode->item , &root->item ))
    {
        if (root->right == NULL)
            root->right = newnode;
        else
            AddNode( newnode , root->right );
    }
    else
    {
        printf("Error in AddNode.\n");
        exit(1);
    }
}

static void DeleteNode( TREEnode **ptr)
{
    TREEnode *temp;
    if((*ptr)->left == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
    else if ((*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
    else
    {
        for ( temp = (*ptr)->left ; temp->right !=NULL;
              temp = temp->right)
                continue;
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}

static void InOrder ( const TREEnode *root , void(*pfun)(Item item))
{
    if (root)
    {
        InOrder( root->left , pfun );
        (*pfun)(root->item);
    }
}

static void DeleteAllNodes( TREEnode *root )
{
    TREEnode *temp;
    if ( root )
    {
        temp = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(temp);
    }
}

void InitializeTree (Tree *ptree)
{
    ptree->size = 0;
    ptree->root = NULL;
}

bool Treeisempty ( const Tree *ptree )
{
    if ( ptree->root)
        return true;
    else
        return false;
}

bool Treeisfull ( const Tree *ptree )
{
    if (ptree->size == MAXITEMS)
        return true;
    else
        return false;
}

int TreeItemCount( const Tree*ptree )  //确定树的项数
{
    return ptree->size;
}

bool AddItem ( const Item *pi , Tree *ptree )
{
    TREEnode *newnode;
    if(Treeisfull(ptree))
    {
        printf("Tree is full.\n");
        return false;
    }
    if(SeekItem( pi , ptree ).child != NULL )
    {
        printf("Attempted to add duplicate item.\n");
        return false;
    }
    newnode =MakeNode(pi);
    if (newnode)
    {
        ptree->size++;
        if (ptree->root)
        {
            AddNode(newnode , ptree->root);
        }
        else
            ptree->root = newnode;
    }
    else
    {
        printf("Couldn't creat node.\n");
        return false;
    }
    return true;
}

bool DeleteItem ( const Item *pi, Tree *ptree )
{
    Pair look;
    look = SeekItem( pi , ptree);
    if (look.child == NULL){
        return false;
    }
    if(look.parent == NULL)
        DeleteNode(&ptree->root);
    else if (look.parent->left == look.child )
        DeleteNode(&look.parent->left);
    else if (look.parent->right == look.child )
        DeleteNode(&look.parent->right);
    ptree->size--;
    return true;
}

bool InTree ( const Item *pi , Tree *ptree )  //查找项
{
    return (SeekItem( pi , ptree).child == NULL ? false : true );
}

void Traverse ( const Tree * ptree , void(*pfun)(Item item))  //把函数应用于树中每一项
{
  if (ptree)
    InOrder (ptree->root , pfun);
}

void DeleteAll ( Tree *ptree )
{
    if ( ptree )
    {
        DeleteAllNodes( ptree->root );
    }
    ptree->root = NULL;
    ptree->size = 0;
}



