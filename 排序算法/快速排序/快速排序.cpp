/*************************************************************************
	> File Name: 快速排序.cpp
	> Author: HowYiAlways
	> Mail: championhengyi@gmail.com
	> Created Time: 2017年07月21日 星期五 22时01分49秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define N 10

class Quick{
public:
    Quick() {  };
    void sort(int array[]);
    void sort(int array[], int l, int r);
    int process(int array[], int l, int r);
};

void Quick :: sort(int array[]) {
    int l = 0, r = N-1;
    sort(array, l, r);
}

void Quick :: sort(int array[], int l, int r) {
    if(l < r) {
        int pos = process(array, l, r);
        sort(array, l, pos-1);
        sort(array, pos+1, r);
    }
}

int Quick :: process(int array[], int l, int r) {
    int temp = array[l];

    while(l != r) {
        while(l < r && array[r] >= temp) r--;
        array[l] = array[r];

        while(l < r && array[l] <= temp) l++;
        array[r] = array[l];
    }
    array[l] = temp;

    return l;
}

int main()
{
    int array[N];
    Quick quick;

    for(int i = 0; i < N; i++) {
        cin >> array[i];
    }

    quick.sort(array);

    for(int i = 0; i < N; i++) {
        cout << array[i] << ' ';
    }

    return 0;
}
