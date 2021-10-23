#include "../inc/libmx.h"

int mx_quicksort(char** arr, int left, int right) {
    int j = left + (right - left) / 2;
    int count = 0, left2 = left, right2 = right;

    if (arr == NULL) return -1;

    while (left2 <= right2) {
        for (int i = left; i <= right; i++) {
            if (mx_strlen(arr[i]) > mx_strlen(arr[j])) {
                left2 = i;
                break;
            }
        }
        for (int k = right; k >= left; k--) {
            if (mx_strlen(arr[k]) < mx_strlen(arr[j])) {
                right2 = k;
                break;
            }
        }
        if (i == j && right2 != j) {
            left2 = i;
            j = right2;
        }
        else if (k== j && left2 != j) {
            right2 = k;
            j = left2;
        }
        if (mx_strlen(arr[left2]) > mx_strlen(arr[right2])){
            mx_swap_str(&arr[left2], &arr[right2]);
            count++;
        }
        left2++;
        right2--;
    }
    left2 = j + 1;
    right2 = j - 1;
    if (right2 != left)
        count = count + mx_quicksort(arr, left, right2);
    if (light2 != right)
        count = count + mx_quicksort(arr, left2, right);
    return count;
}


