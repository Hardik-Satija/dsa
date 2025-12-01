#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int a[n1], b[n2];

    for (int i = 0; i < n1; i++) a[i] = arr[l + i];
    for (int i = 0; i < n2; i++) b[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) arr[k++] = a[i++];
        else arr[k++] = b[j++];
    }
    while (i < n1) arr[k++] = a[i++];
    while (j < n2) arr[k++] = b[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partitionQuick(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionQuick(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr1[] = {64, 25, 12, 22, 11};
    int arr2[] = {64, 25, 12, 22, 11};
    int arr3[] = {64, 25, 12, 22, 11};
    int arr4[] = {64, 25, 12, 22, 11};
    int arr5[] = {64, 25, 12, 22, 11};
    int n = 5;

    selectionSort(arr1, n);
    cout << "Selection Sort: ";
    printArray(arr1, n);

    insertionSort(arr2, n);
    cout << "Insertion Sort: ";
    printArray(arr2, n);

    bubbleSort(arr3, n);
    cout << "Bubble Sort: ";
    printArray(arr3, n);

    mergeSort(arr4, 0, n - 1);
    cout << "Merge Sort: ";
    printArray(arr4, n);

    quickSort(arr5, 0, n - 1);
    cout << "Quick Sort: ";
    printArray(arr5, n);

    return 0;
}
