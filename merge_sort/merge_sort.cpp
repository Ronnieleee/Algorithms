#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& array, int start, int end, int temp);
int merge_sort(vector<int>& array, int start, int end);

int main(int argc, char** argv)
{
//    /*
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
//    */
/*
   int array_B[] = { 2, 4, 5, 7, 1, 2, 4, 6 };
   vector<int> array_merge (array_B, array_B+8);
   cout << array_merge.size() << endl; 
   merge(array_merge, 0, 7, 3);

   for (int i=0; i < array_merge.size(); i++)
       cout << array_merge.at(i) << '\t';
    
    cout << endl;
*/

    return 0;
}

void merge(vector<int>& array, int start, int end, int temp)
{
    int temp1 = temp - start + 1;
    int temp2 = end - temp;
    int array_L[temp1];
    int array_R[temp2]; 
    
    //
    for (int i = 0; i < temp1; i++) {
        array_L[i] = array.at(start+i);
    }

    for (int j = 0; j < temp2; j++) {
        array_R[j] = array.at(temp+1+j);
    }

    int i = 0;
    int j = 0;
    int k;
    for (k = start; j < temp2 && i < temp1 && k <= end; k++) {
        if (array_L[i] <= array_R[j]) {
            array[k]= array_L[i];
            i++;
        }
        else {
            array[k] = array_R[j];
            j++;
        }
    }

    if (i >= temp1) {
        while (k <= end && j < temp2) {
            array[k] = array_R[j];
            j++;
        }
    }

    if (j >= temp2) {
        while (k <= end && i < temp1) {
            array[k] = array_L[i];
            i++;            
        }
    }
}

int merge_sort(vector<int>& array, int start, int end)
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