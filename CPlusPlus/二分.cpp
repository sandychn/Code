// a[]中>=val的最小位置
int lowerBound(int* a, int l, int r, int val) {
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] <= val) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

// a[]中<=val的最大位置
int upperBound(int* a, int l, int r, int val) {
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (a[mid] <= val) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}
