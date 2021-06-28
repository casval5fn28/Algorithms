#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int *arr, int front, int end){
    int pivot = arr[end];
    int i = front -1;
    for (int j = front; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]);
    return i;
}
void QuickSort(int *arr, int front, int end){
    if (front < end) {
        int pivot = Partition(arr, front, end);
        QuickSort(arr, front, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }
}
void PrintArray(int *arr, int size){
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int len = 1;
    /*int ct = 0;
    double time_taken[1000]={};
    double full_time = 0;
    srand( time(NULL));
    clock_t start_time, end_time;*/
    while(len!=0){
        cin>>len;
        int arr[len];
        //start_time = clock();
        for(int i=0;i<len;i++){
            //arr[i] = rand() % (10000 - (-10000) + 1) + (-10000);
            cin>>arr[i];
        }
        QuickSort(arr, 0, len-1);
        /*end_time = clock();
        time_taken[ct] = double(end_time - start_time) / double(CLOCKS_PER_SEC);*/
        PrintArray(arr, len);
        /*cout << "Time taken by program is : " << fixed << time_taken [ct]<< setprecision(10) << " sec " << endl;
        ct++;*/
    }
    /*for(int i=0;i<1000;i++){
        full_time += time_taken[i];
    }
    double avg = full_time/(ct-1);
    cout<<"Average time :"<< avg << " sec " << endl;
    cout<<"Fastest time :"<< *min_element(time_taken , time_taken + 1000) << " sec " << endl;
    cout<<"Slowest time :"<< *max_element(time_taken , time_taken + 1000) << " sec " << endl;*/
    return 0;
}
