/*************************************************************************
	> File Name: 二分查找.cpp
	> Author: HowYiAlways
	> Mail: championhengyi@gmail.com
	> Created Time: 2017年07月17日 星期一 22时11分24秒
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;

#define SIZE 100

class BinarySearch {
public:
    int result;
    int getResult(int array[], int mid, int length);
};

int BinarySearch :: getResult(int array[], int search, int length) {
    int front = 0;
    int end = length-1;
    int mid = (front+end)/2;

    while(front <= end) {
        if(array[mid] == search) {
            return mid;
        } else if(search < array[mid]) {
            front = 0;
            end = mid-1;
            mid = (front+end)/2;
        } else {
            front = mid+1;
            end = length-1;
            mid = (front+end)/2;
        }
    }

    return -1;
}

int main()
{
    int number[SIZE];
    int size;
    int find;
    int subscript;

    cin >> size;
    for(int i = 0; i < size; i++){
        cin >> number[i];
    }
    cin >> find;
    
    BinarySearch binary;
    subscript = binary.getResult(number, find, size);

    cout << subscript;
}
