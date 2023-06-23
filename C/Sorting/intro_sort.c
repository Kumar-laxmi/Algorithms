#include <stdio.h>
#include <math.h>
#define max(a, b) (a > b) ? a : b
#define min(a, b) (a < b) ? a : b
int a[20], n;
void swap(int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void maxHeap(int i, int b, int hn)
{
    int tmp, c;
    tmp = a[b + i - 1];
    while (i <= hn / 2)
    {
        c = 2 * i;
        if (c < hn && a[b + c - 1] < a[b + c])
            c++;
        if (tmp >= a[b + c - 1])
            break;
        a[b + i - 1] = a[b + c - 1];
        i = c;
    }
    a[b + i - 1] = tmp;
}
void heap(int b, int e, int hn)
{
    int i;
    for (i = hn / 2; i >= 1; i--)
        maxHeap(i, b, hn);
}
void heapSort(int b, int e)
{
    int i, hn;
    hn = e - b;
    heap(b, e, hn);
    for (i = hn; i >= 1; i--)
    {
        swap(b, b + i);
        maxHeap(1, i, b);
    }
}
void insertion(int l, int r)
{
    int i, j, k;
    for (i = l; i <= r; i++)
    {
        k = a[i];
        j = i;
        while (j > l && a[j - 1] > k)
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = k;
    }
}
int pivotFind(int a1, int b1, int c1)
{
    int mn, mx, median;
    mx = max(max(a[a1], a[b1]), a[c1]);
    mn = min(min(a[a1], a[b1]), a[c1]);
    median = mx ^ mn ^ a[a1] ^ a[b1] ^ a[c1];
    if (median == a[a1])
        return a1;
    if (median == a[b1])
        return b1;
    return c1;
}
int partition(int l, int h)
{
    int i, j, pivot;
    pivot = a[h];
    i = (l - 1);
    for (j = l; j <= h - 1; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(i, j);
        }
    }
    swap(i + 1, h);
    return (i + 1);
}
void introsort(int b, int e, int d)
{
    int p, pivot;
    if (e - b > 16)
    {
        if (d == 0)
        {
            heapSort(b, e);
            return;
        }
        d = d - 1;
        pivot = pivotFind(b, b + ((e - b) / 2) + 1, e);
        swap(pivot, e);
        p = partition(b, e);
        introsort(b, p - 1, d);
        introsort(p + 1, e, d);
    }
    else
    {
        insertion(b, e);
    }
}
void sort()
{
    int d;
    d = (int)(2 * floor(log(n) / log(2)));
    introsort(0, n - 1, d);
}
void display()
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
int main()
{
    int i;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    printf("\nEnter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort();
    printf("\nThe sorted array is: ");
    display();
}
