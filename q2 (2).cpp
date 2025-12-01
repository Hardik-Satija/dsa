#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int minIndex = left;
        int maxIndex = right;

        if (arr[minIndex] > arr[maxIndex])
            swap(arr[minIndex], arr[maxIndex]);

        for (int i = left + 1; i < right; i++) {
            if (arr[i] < arr[minIndex]) minIndex = i;
            if (arr[i] > arr[maxIndex]) maxIndex = i;
        }

        swap(arr[left], arr[minIndex]);

        if (maxIndex == left)
            maxIndex = minIndex;

        swap(arr[right], arr[maxIndex]);

        left++;
        right--;
    }
}

int main() {
    int arr[] = {10, 3, 15, 7, 8, 23, 98, 29};
    int n = sizeof(arr)/sizeof(arr[0]);

    improvedSelectionSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
