#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& array, const int start, const int end, const int temp);
int merge_sort(vector<int>& array, const int start, const int end);

int main(int argc, char** argv)
{
    //  /*
    int array_A[] = { 5, 2, 4, 7, 1, 3, 2, 6 };
    vector<int> array(array_A, array_A+8);

    for (int i=0; i < array.size(); i++) {
        cout << array.at(i) << '\t';
    }
    cout << endl;

    merge_sort(array, 0, 7);

    for (int i=0; i < array.size(); i++) {
        cout << array.at(i) << '\t';
    }
    cout << endl;
    
    // 测试merge函数的正确性 
    /*
    int array_B[] = { 2, 4, 5, 7, 1, 2, 4, 6 };
    vector<int> array_merge (array_B, array_B+8);
    cout << array_merge.size() << endl; 
    merge(array_merge, 0, 7, 3);
    merge(array_merge,0, 1, 0);

    for (int i=0; i < array_merge.size(); i++)
        cout << array_merge.at(i) << '\t';
    
    cout << endl;
    */

    return 0;
}

void merge(vector<int>& array, const int start, const int end, const int temp)
{
    int temp1 = temp - start + 1;
    int temp2 = end - temp;
    int array_L[temp1];
    int array_R[temp2]; 
    
    // 初始化左右边界数组
    for (int i = 0; i < temp1; i++) {
        array_L[i] = array.at(start+i);
    }

    for (int j = 0; j < temp2; j++) {
        array_R[j] = array.at(temp+1+j);
    }

    int i = 0;
    int j = 0;
    int k = start;
   
    while (i < temp1 && j < temp2) {
        if (array_L[i] <= array_R[j]) {
            array[k] = array_L[i];
            i++;
            k++;
        }
        else {
            array[k] = array_R[j];
            j++;
            k++;
        }
    }

    while (i < temp1) {
        array[k] = array_L[i];
        i++;
        k++;
    }

    while (j < temp2) {
        array[k] = array_R[j];
        j++;
        k++;
    }

}

int merge_sort(vector<int>& array, const int start, const int end)
{
    if (start < end) {
        int temp = (start + end) / 2;
        merge_sort(array, start, temp);
        merge_sort(array, temp+1, end);
        merge(array, start, end, temp);
        
        return 1;
    }
    return 0;
}