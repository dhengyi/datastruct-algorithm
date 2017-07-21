/*************************************************************************
	> File Name: 希尔排序.cpp
	> Author: HowYiAlways
	> Mail: championhengyi@gmail.com
	> Created Time: 2017年07月18日 星期二 22时57分21秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define SIZE 10

class Shell {
public:
    Shell() {  }
    int *sort(int array[], int length);
};

int *Shell :: sort(int array[], int length) {
    int N = length / 2;
    int temp;

    while(N >= 1) {
        for(int i = N; i < length; i++) {
            for(int j = i; j >= N && array[j] < array[j-N]; j -= N) {
                temp = array[j];
                array[j] = array[j-N];
                array[j-N] = temp;
            }
        }

        N /= 2;
    }

    return array;
}

int main()
{
    int array[SIZE];
    Shell shell;
    int *result;

    for(int i = 0; i < SIZE; i++) {
        cin >> array[i];
    }

    result = shell.sort(array, SIZE);

    for(int i = 0; i < SIZE; i++) {
        cout << result[i] << ' ';
    }

    return 0;
}
