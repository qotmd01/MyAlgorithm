/*
https://velog.io/@qotmd01/알고리즘-lowerbound-upperbound
*/


int lower_bound(int target, vector<int> a, int N){
    int start = 0, end = N - 1, mid;
    while (start < end)
    {
        mid = (start + end) / 2;
        if(target <= a[mid]) end = mid;
        else start = mid + 1;
    }
    return end;
}

int Upper_bound(int target, vector<int> a, int N){
    int start = 0, end = N - 1, mid;
    while (start < end)
    {
        mid = (start + end) / 2;
        if(target < a[mid]) end = mid;
        else start = mid + 1;
    }
    return end;
}
