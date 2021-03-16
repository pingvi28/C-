#include <iostream>
using namespace std;
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int middle, int right);
void printArray(int data[], int size);


void mergeSort(int arr[], int left, int right)
{
    
    if (arr == NULL) {
        cout << "Array points to null";
    }
      else if (left < 0) {
       cout << "Uncorrectly param";
    }
    else if (left + 1 >= right) {
         return;
    }
    else {
        int middle = (left + right) / 2;
        mergeSort(arr, left, middle); //1 part array
        mergeSort(arr, middle, right);  //2 part array
        merge(arr, left, middle, right);
    }
}

void merge(int arr[], int left, int middle, int right)
{
    int i = 0;
    int j = 0;
    int* sortingArr = new int[right - left];
    while (left + i < middle && middle + j < right) {
        if (arr[left + i] < arr[middle + j]) {
            sortingArr[i + j] = arr[left + i];
            i++;
        }
        else {
            sortingArr[i + j] = arr[middle + j];
            j++;
        }
    }
    while (left + i < middle) {
        sortingArr[i + j] = arr[left + i];
        i++;
    }
    while (middle + j < right) {
        sortingArr[i + j] = arr[middle + j];
        j++;
    }
    for (int i = 0; i < right - left; i++) {
        arr[left + i] = sortingArr[i];
    }
    delete[] sortingArr;
}


void printArray(int data[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", data[i]);
    printf("\n");
}

int main()
{
    cout << "array size" << endl;
    int k, i;
    cin >> k;
    int* arr = new int[k];
    for (i = 0; i < k; i++) {
        cout << "enter element ";
        cin >> arr[i];
    }

    cout << "Our array is" << endl;
    printArray(arr, k);
    mergeSort(arr, 0, k);

    cout << "Sorted array is" << endl;
    printArray(arr, k);
    return 0;
}
