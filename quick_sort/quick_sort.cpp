#include <iostream>
#include <vector>

using namespace std;

void swap(int* left, int* right) {
    int temp = *left;
    *left = *right;
    *right = temp;
}

int partition(vector<int>& array, const int begin, const int end) {
    int pivot = array.at(end-1);
    int i = begin-1;

    for (int j = begin; j < end-1; j++ ) {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array.at(i), &array.at(j));
        }
    }
    swap(&array.at(i+1), &array.at(end-1));

    return i+1;
}

int quick_sort(vector<int>& array, const int begin, const int end) {
    if (begin < end) {
        int pi = partition(array, begin, end);

        quick_sort(array, begin, pi);
        quick_sort(array, pi+1, end);
        return 1;
    }
    return 0;
}

int main(int argc, char** argv) {
    int array_test[] = { 5, 2, 4, 7, 1, 3, 2, 6 };
    vector<int> array (array_test, array_test+8);

    for (int i=0; i < array.size(); i++) {
        cout << array.at(i) << '\t';
    }
    cout << endl;

    // 测试partition函数是否能有效分割
    //int k = partition(array, 0, array.size());
    //cout << k << endl;

    quick_sort(array, 0, array.size());

    for (int i=0; i < array.size(); i++) {
        cout << array.at(i) << '\t';
    }
    cout << endl;
    
    return 0;
}