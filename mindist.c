#include <string.h>
#include <stdio.h>

int min_dist(int *arr1, int len1, int *arr2, int len2)
{
    if (arr1 == NULL || arr2 == NULL)
        return 0;

    int p1 = 0; // ptr arr1  
    int p2 = 0; // ptr arr2  

    int min = 9999999;
    while (p1 < len1 && p2 < len2)
    {
        int diff = 9999999;
        if (arr1[p1] <= arr2[p2])
        {
            diff = arr2[p2] - arr1[p1];
            p1++;
        }
        else
        {
            diff = arr1[p1] - arr2[p2];
            p2++;
        }

        if (diff < min)
            min = diff;
    }

    return min;
}

int main()
{
    int arr1[] = {1, 6, 7};
    int arr2[] = {4, 8, 9};
    int diff = min_dist(arr1, 3, arr2, 3);
    printf("%d\n", diff);
}
