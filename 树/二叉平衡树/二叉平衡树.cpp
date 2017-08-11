/*************************************************************************
	> File Name: 二叉平衡树.cpp
	> Author: HowYiAlways
	> Mail: championhengyi@gmail.com
	> Created Time: 2017年08月10日 星期四 08时27分54秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

/**
 * BF = Node的右子树高度-Node的左子树高度
 */

typedef int Type;

//建立AVL树的基本数据结构(双向链表)
typedef struct AVLTreeNode {
    Type key;
    //用来记录此结点的平衡因子
    int bfactor;
    //记录当前结点的左右孩子结点，父结点
    struct AVLTreeNode *parent, *lchild, *rchild;
}Node, *AVLTree;

//创建AVL树
void create_avltree(AVLTree *root, Type key);
//对结点进行插入
void insert_node(AVLTree *root, Type key);
//返回结点插入的位置
Node *insert_local(AVLTree *node, Type key);
//左左型(左单旋转)
void LL(AVLTree *root, Node *unbalance_node, Node *child_node);
//树状打印
void print_tree(AVLTree root, int h);

void print_tree(AVLTree root, int h) {
    if(root == NULL) {
        return ;
    }

    if(root -> rchild != NULL) {
        print_tree(root -> rchild, h+1);  
    }

    for(int i = 0; i < h; i++) {
        cout << "   ";
            
    }
    cout << root -> key << endl;

    if(root -> lchild != NULL) {
        print_tree(root -> lchild, h+1);    
    }
}

void LL(AVLTree *root, Node *unbalance_node, Node *child_node) {
    Node *FA = unbalance_node -> parent;

    //旋转
    unbalance_node -> lchild = child_node -> rchild;
    child_node -> rchild = unbalance_node;

    unbalance_node -> bfactor = 0;
    child_node -> bfactor = 0;
    
    cout << "------------------" << endl;

    if(FA == NULL) {
        *root = child_node;
        cout << "+++++++++++++++++++" << endl;
    } else if(FA -> lchild == unbalance_node) {
        FA -> lchild = child_node;
    } else {
        FA -> rchild = child_node;
    }
}

Node *insert_local(AVLTree *node, Type key) {
    //进行查找的时候记录其父结点并改变各个结点的平衡因子
    Node *parent = NULL;
    while(*node != NULL) {
        if((*node) -> key < key) {
            parent = *node;
            parent -> bfactor += 1;
            node = &((*node) -> rchild);
        } else {
            parent = *node;
            parent -> bfactor -= 1;
            node = &((*node) -> lchild);
        }
    }

    *node = (Node *)malloc(sizeof(Node));
    (*node) -> key = key;
    (*node) -> bfactor = 0;
    (*node) -> parent = parent;
    (*node) -> lchild = NULL;
    (*node) -> rchild = NULL;

    return *node;
}

void insert_node(AVLTree *root, Type key) {
    Node *node, *parent;

    cout << "============" << endl;
    //插入新结点
    node = insert_local(root, key);
    parent = node -> parent;

    cout << "node: " << node -> key << endl;
    if(parent == NULL) {
        cout << "parent: " << parent << endl;
    } else {
        cout << "parent: " << parent -> key << endl;
    }

    //对新插入结点的父结点的平衡因子进行判断
    while(parent != NULL) {
        if(parent -> bfactor == 0) {
            return ;
        } else if(parent -> bfactor == 1 || parent -> bfactor == -1) {
            parent = parent -> parent;
            node = node -> parent;
        } else {
            //LL型
            if(node -> bfactor == -1 && parent -> bfactor == -2) {
                LL(root, parent, node);
            } else if(node -> bfactor == 1 && parent -> bfactor == 2) {                 //RR型

            } else if(node -> bfactor == 1 && parent -> bfactor == -2) {                //LR型

            } else {                                                                    //RL型

            }
        }
    }

    return ;
}

void create_avltree(AVLTree *root, Type key) {
    //创建AVL的过程就是对结点进行插入
    insert_node(root, key);
}

int main()
{
    Type *array;
    int size;
    AVLTree root = NULL;

    cin >> size;
    array = (Type *)malloc(sizeof(Type));

    for(int i = 0; i < size; i++) {
        cin >> array[i];
    }

    //建立平衡二叉树
    for(int i = 0; i < size; i++) {
        create_avltree(&root, array[i]);
    }

    //树状打印
    print_tree(root, 1);
}
