#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>

using namespace std;


void merge(int arr[], int l, int m, int r, int len){
    int i = l;
    int j = m + 1;
    int k = l;
    int temp[len];

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= m) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int p = l; p <= r; p++) {
        arr[p] = temp[p];
    }
}
void mergeSort(int arr[], int l, int r, int len){
    if (l < r) {
        // find midpoint
        int m = (l + r) / 2;
        /* recurcive mergesort first and second halves */
        mergeSort(arr, l, m, len);
        mergeSort(arr, m + 1, r, len);
        // merge
        merge(arr, l, m, r, len);
    }
}

void PrintArray(int *arr, int size){
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int len = 1;
    /*int ct = 0;
    double time_taken[1000]={};
    double full_time = 0;
    srand( time(NULL));
    clock_t start_time, end_time;*/
    while(len!=0){
        cin >> len;
        int arr[len];
        //start_time = clock();
        for (int i = 0; i < len; i++) {
           // arr[i] = rand() % (10000 - (-10000) + 1) + (-10000);
            cin >> arr[i];
        }
        mergeSort(arr, 0, (len - 1), len);
        /*end_time = clock();
        time_taken[ct] = double(end_time - start_time) / double(CLOCKS_PER_SEC);*/
        PrintArray(arr,len);
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
