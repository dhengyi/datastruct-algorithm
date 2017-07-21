/*************************************************************************
	> File Name: 归并排序.cpp
	> Author: HowYiAlways
	> Mail: championhengyi@gmail.com
	> Created Time: 2017年07月19日 星期三 22时19分50秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define SIZE 10

int main()
{
    int array[SIZE];
    int array_result[SIZE];
    int mid = SIZE/2;
    int i = 0, j = mid;

    for(int i = 0; i < SIZE; i++) {
        cin >> array[i];
    }

    for(int k = 0; k < SIZE; k++) {
        if(i >= mid) 
            array_result[k] = array[j++];
        else if(j >= SIZE) 
            array_result[k] = array[i++];
        else if(array[i] > array[j]) 
            array_result[k] = array[j++];
        else 
            array_result[k] = array[i++];
    }

    for(int k = 0; k < SIZE; k++) {
        cout << array_result[k] << ' ';
    }

    return 0;
}
