/*************************************************************************
	> File Name: 自底向上归并排序.cpp
	> Author: HowYiAlways
	> Mail: championhengyi@gmail.com
	> Created Time: 2017年07月21日 星期五 17时32分06秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
using namespace std;

void sort(int array[], int size) {
    for(int i = 1; i < size; i += i) {
        for()
    }


}

int main()
{
    int *array;
    int size;

    cin >> size;
    array = (int *)malloc(sizeof(int)*size);

    for(int i = 0; i < size; i++) {
        cin >> array[i];
    }

    sort(array, size);
}
