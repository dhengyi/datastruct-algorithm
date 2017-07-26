/*************************************************************************
	> File Name: 自底向上归并排序.cpp
	> Author: HowYiAlways
	> Mail: championhengyi@gmail.com
	> Created Time: 2017年07月21日 星期五 17时32分06秒
 ************************************************************************/

	#include<iostream>
	#include<cstdlib>
	#include<cstring>
	using namespace std;

	void sort(int array[], int size) {
	    int aux[size];

	    //刚开始子数组长度为1，然后进行一一归并，两两归并，四四归并... ...当子数组长度大于等于原数组长度时，整个数组有序
	    for(int i = 1; i < size; i *= 2) {
		//将原数组复制到一个临时数组之中
		memcpy(aux, array, 4*size);
		
		for(int j = 0; j < size; j++) {
		    cout << "debug: " << array[j] << ' ';
		}
		cout << endl;
		//进行归并操作，首先要判断好每次归并的start，mid，end
		for(int start = 0; start < size; start += i*2) {
		    int end = start + i*2-1;
		    int mid = (start+end)/2;
		    int m = start, n = mid+1;

		    //当我们对数组进行划分的时候，最后一个子数组的end有时候会大于数组长度，此时我们应该选取整体数组的长度
		    if(end >= size) {
		        end = size-1;
		    }

		    //开始进行单趟归并
		    for(int k = start; k <= end; k++) {
		        if(m > mid) {
		            array[k] = aux[n++];
		        } else if(n > end) {
		            array[k] = aux[m++];
		        } else if(aux[m] > aux[n]) {
		            array[k] = aux[n++];
		        } else {
		            array[k] = aux[m++];
		        }
		    }
		}
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

	    for(int i = 0; i < size; i++) {
		cout << array[i] << " ";
	    }

	    return 0;
	}
