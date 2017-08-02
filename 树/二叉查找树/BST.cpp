/*************************************************************************
	> File Name: BST.cpp
	> Author: HowYiAlways
	> Mail: championhengyi@gmail.com
	> Created Time: 2017年07月31日 星期一 22时31分27秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
using namespace std;

#define N 10

//BST的数据结构
typedef int keyType;

typedef struct Node {
    keyType data;
    struct Node *lchild, *rchild;
} BSTNode, BSTree;

void create_BSTree(int array[], BSTree **bstree);
void insert(BSTree **bstree, keyType data);
void print_tree(BSTree *bstree, int h);
BSTNode *find_recursive(BSTree *bstree, keyType key);
BSTNode *find(BSTree *bstree, keyType key);
BSTree *deleteNode(BSTree *bstree, keyType key);

void insert(BSTree **bstree, keyType data) { 
    BSTNode *bstnode;

    if(*bstree == NULL) {
        bstnode = (BSTNode *)malloc(sizeof(BSTNode));
        bstnode -> data = data;
        bstnode -> lchild = NULL;
        bstnode -> rchild = NULL;
        *bstree = bstnode;
    } else if(data <= (*bstree) -> data) {
        insert(&((*bstree)->lchild), data);
    } else {
        insert(&((*bstree)->rchild), data);
    }
}

void create_BSTree(int array[], BSTree **bstree) {
    //二叉查找树的创建是建立在插入上面的
    for(int i = 0; i < N; i++) {
        insert(bstree, array[i]);
    }
}

void print_tree(BSTree *bstree, int h) {
    if(bstree == NULL) {
        return ;
    }

    if(bstree -> rchild != NULL) {
        print_tree(bstree -> rchild, h+1);
    }

    for(int i = 0; i < h; i++) {
        cout << "   ";
    }
    cout << bstree -> data << endl;

    if(bstree -> lchild != NULL) {
        print_tree(bstree -> lchild, h+1);
    }
}

//递归实现
BSTNode *find_recursive(BSTree *bstree, keyType key) {
    if(bstree == NULL) {
        return NULL;
    }

    if(bstree -> data == key) {
        return bstree;
    } else if(key <= bstree -> data) {
        return find(bstree -> lchild, key);
    } else {
        return find(bstree -> rchild, key);
    }
}

//非递归实现
BSTNode *find(BSTree *bstree, keyType key) {
    while(bstree != NULL) {
        if(bstree -> data == key) {
            return bstree;
        } else if(bstree -> data >= key){
            bstree = bstree -> lchild;
        } else {
            bstree = bstree -> rchild;
        }
    }

    return bstree;
}

BSTree *deleteNode(BSTree *bstree, keyType key) {
    //定义父节点和孩子节点
    BSTree *root, *child;
    //定义替换的节点
    BSTree *alter;

    child = root = bstree;

    //首先考虑特殊情况（根节点为空|只有根节点）
    if(root == NULL) {
        cout << "这是棵空树" << endl;
    } else if (root -> lchild == NULL && root -> rchild == NULL) {
        if(root -> data == key) {
            root = NULL;
        } else {
            cout << "没要找到您要删除的节点" << endl;
        }
    } else {
        while(child != NULL && child -> data != key) {
            if(key <= child -> data) {
                root = child;
                child = root -> lchild;
            } else {
                root = child;
                child = root -> rchild;
            }
        }

        if(child == NULL) {
            cout << "没有找到您要删除的节点" << endl;
        } else {
            //待删节点是叶子节点
            if(child -> lchild == NULL && child -> rchild == NULL) {
                if(root -> lchild == child) {
                    root -> lchild = NULL;
                    free(child);
                } else {
                    root -> rchild = NULL;
                    free(child);
                }
            }

            //待删节点只有左子树或者右子树
            else if(child -> lchild == NULL || child -> rchild == NULL) {
                if(root -> lchild == child && child -> lchild != NULL) {
                    root -> lchild = child -> lchild;
		            free(child);
                } else if(root -> lchild == child && child -> rchild != NULL) {
                    root -> lchild = child -> rchild;
		            free(child);
                } else if(root -> rchild == child && child -> lchild != NULL) {
		            root -> rchild = child -> lchild;
		            free(child);
		        } else {
		            root -> rchild = child -> rchild;
		            free(child);
		        }
            } 

            //待删节点只是普通节点
            else {
                //找到替换节点与替换节点的父节点
                BSTNode *alterParent = child;
                alter = alterParent -> lchild;
                while(alter -> rchild != NULL) {
                    alterParent = alter;
                    alter = alterParent -> rchild;
                }

                //替换节点的父节点等于待删节点且删除节点是根节点的时候
                if(alterParent == child && child == bstree) {
                    //由于我查找替换节点的方式是左子树的最右边，所以当满足上面的if语句之后，我的替换节点必定在
                    //待删除节点的左边
                    alter -> lchild = child -> lchild -> lchild;
                    alter -> rchild = child -> rchild;
                    bstree = alter;
                    free(child);
                } else if(alterParent == child && child != bstree) {
                    alter -> lchild = child -> lchild -> lchild;
                    alter -> rchild = child -> rchild;
                    if(child == root -> lchild) {
                        root -> lchild = alter;
                        free(child);
                    } else {
                        root -> rchild = alter;
                        free(child);
                    }
                } else if(alterParent != child && child == bstree) {
                    //如果是这种情况，那么替换节点就在替换父节点的右子树上
                    alter -> lchild = child -> lchild;
                    alter -> rchild = child -> rchild;
                    free(child);
                    bstree = alter;
                    alterParent -> rchild = NULL;
                } else {
                    alter -> lchild = child -> lchild;
                    alter -> rchild = child -> rchild;
                    if(child == root -> lchild){
                        root -> lchild = alter;
                        free(child);
                    } else {
                        root -> rchild = alter;
                        free(child);
                    }
                    alterParent -> rchild = NULL;
                }
            } 
        }
    }
    return bstree;
}

int main() {
    keyType array[N];
    keyType key;
    //初始化二叉查找树的根节点
    BSTree *bstree = NULL;
    BSTNode *result = NULL;

    for(int i = 0; i < N; i++) {
        cin >> array[i];
    }
    
    //建立BST
    create_BSTree(array, &bstree);

    //对二叉查找树进行树状打印
    print_tree(bstree, 1);

    cin >> key;
    //对二叉查找树进行查找
    //result = find_recursive(bstree, key);
    result = find(bstree, key);

    if(result == NULL) {
        cout << "Not Find" << endl;
    } else {
        cout << result -> data << endl;
    }

    cin >> key;
    //进行指定节点的删除
    bstree = deleteNode(bstree, key);

    print_tree(bstree, 1);

    return 0;
}
