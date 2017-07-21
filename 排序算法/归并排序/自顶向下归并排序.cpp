/*************************************************************************
	> File Name: 自顶向下归并排序.cpp
	> Author: HowYiAlways
	> Mail: championhengyi@gmail.com
	> Created Time: 2017年07月19日 星期三 23时00分06秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define SIZE 11

class MergeTD {
private:
    int *array_temp;

public:
    MergeTD(int array_temp[]) {
        this -> array_temp = array_temp;
    }

    void sort(int array[]);
    void merge(int array[], int mid, int l, int r);
    void sort(int array[], int l, int r);
};

void MergeTD :: sort(int array[]) {
    sort(array, 0, SIZE-1);
}

void MergeTD :: sort(int array[], int l, int r) {
    if(l >= r)
        return ;

    int mid = l+(r-l)/2;
    
    sort(array, l, mid);
    sort(array, mid+1, r);
    merge(array, mid, l, r);
}

void MergeTD :: merge(int array[], int mid, int l, int r) {
    int m = l, n = mid+1;

    for(int k = l; k <= r; k++) {
        array_temp[k] = array[k];
    }

    for(int i = l; i <= r; i++) {
        if(m > mid)
            array[i] = array_temp[n++];
        else if(n > r)
            array[i] = array_temp[m++];
        else if(array_temp[n] < array_temp[m])
            array[i] = array_temp[n++];
        else
            array[i] = array_temp[m++];
    }
}

int main()
{
    int array[SIZE];
    int array_temp[SIZE];
    MergeTD TDMerge(array_temp);

    for(int i = 0; i < SIZE; i++) {
        cin >> array[i];
    }

    TDMerge.sort(array);

    for(int i = 0; i < SIZE; i++) {
        cout << array[i] << ' ';
    }

    return 0;
}
