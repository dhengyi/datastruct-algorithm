/*************************************************************************
	> File Name: 堆排序.cpp
	> Author: HowYiAlways
	> Mail: championhengyi@gmail.com
	> Created Time: 2017年07月27日 星期四 14时29分44秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define N 10

class Heap {
public:
    void sort(int array[], int size);
    void createHeap(int array[], int i, int size);
    void swap(int array[], int local);
};

void Heap :: swap(int array[], int local) {
    int temp = array[local];
    array[local] = array[0];
    array[0] = temp;
}

void Heap :: createHeap(int array[], int i, int size) {
    //先找到当前节点的左右孩子节点
    int l = 2*i+1;
    int r = l+1;
    int k;
    //保存当前节点的值
    int temp = array[i];
    cout << "l: " << l << " r: " << r << endl;

    while(l < size) {
        //先找到数值较大的孩子
        if(l == size-1) {
            k = l;
        } else {
            k = (array[l] >= array[r] ? l : r);
        }

        //将孩子和父节点进行比较
        if(array[k] <= temp) {
            break ;
        } else {
            array[i] = array[k];
            i = k;
            l = 2*i+1;
            r = l+1;
        }
        array[k] = temp;
    }

    for(int i = 0; i < N; i++) {
        cout << array[i] << ' ';
    }
    cout << endl;
}

void Heap :: sort(int array[], int size) {
    //先找到第一个非叶子节点
    int not_leafP = size/2-1;
    int local = size;

    //初始化堆
    for(int i = not_leafP; i >= 0; i--) {
        //建立子堆
        createHeap(array, i, size);
    }
    //将堆顶元素插入到数组尾的有序区间中
    swap(array, --local);
}

int main()
{
    int array[N];
    Heap heap;

    for(int i = 0; i < N; i++) {
        cin >> array[i];
    }
    
    //当只有一个节点进行初始化堆的时候，数组有序
    for(int size = N; size > 1; size--) {
        heap.sort(array, size);
    }

    for(int i = 0; i < N; i++) {
        cout << array[i] << ' ';
    }
    cout << endl;

    return 0;
}
