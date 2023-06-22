#include <stdio.h>
// // bài 1
// int main()
// {
//     int x, y, z;
//     int *ptr;
//     printf("Enter three integers: ");
//     scanf("%d %d %d", &x, &y, &z);
//     printf("\nThe three integers are:\n");
//     ptr = &x;
//     printf("x = %d\n", *ptr);
//     ptr = &y;
//     printf("y = %d\n", *ptr);
//     ptr = &z;
//     printf("z = %d\n", *ptr);
//     return 0;
// }

// // bài 2
// int main()
// {
//     int a[7] = {13, -355, 235, 47, 67, 943, 1222};
//     printf("address of first five elements in memory.\n");
//     for (int i = 0; i < 5; i++)
//         printf("\t\ta[%d] ", i);
//     printf("\n");
//     for (int i = 0; i < 5; i++)
//         printf("\t%d ",&a[i]);
//     printf("\t%d ",%a);
//     return 0;
// }

// // bài 3
// int main()
// {
//     int x, y, z;
//     int *ptr;
//     scanf("%d %d %d", &x, &y, &z);
//     printf("Here are the values of x, y, and z:\n");
//     printf("%d %d %d\n", x, y, z);
//     ptr = &x;
//     *ptr = *ptr+100;
//     ptr = &y;
//     *ptr = *ptr+100;
//     ptr = &z;
//     *ptr = *ptr+100;
//     printf("Once again, here are the values of x, y, and z:\n");
//     printf("%d %d %d\n", x, y, z);
//     return 0;
// }

// // bai 4
// int counteven(int *arr, int size)
// {
//     int count = 0;
//     for (int i = 0; i < size; i++)
//     {
//         if(arr[i] %2 == 0) count++;
//     }
//     return count;
// }
// int main()
// {
//     int arr[] = {1, 2,11,12,21,22};
//     int arrSize = sizeof(arr) / sizeof(arr[0]);
//     printf("%d\n", counteven(arr, arrSize));
//     return 0;
// }

// // bai 5
// double *maximum(double *a, int size)
// {
//     double *max;
//     max = a;
//     if (a == NULL)
//         return NULL;
//     for (int i = 0; i < size; i++)
//     {
//         if (a[i] > *max)
//             max = &a[i];
//     }
//     return max;
// }
// int main()
// {
//     double arr[] = {1.0, 2, 11, 12, 21, 22};
//     int arrSize = sizeof(arr) / sizeof(arr[0]);
//     printf("%lf", *maximum(arr, arrSize));
//     return 0;
// }

// // bai 6
// void reversearray(int arr[], int size)
// {
//     int l = 0, r = size - 1, tmp;
//     while(l<r)
//     {
//     tmp = arr[l];
//     arr[l] = arr[r];
//     arr[r] = tmp;
//     l++;
//     r--;
// }
// }
// void ptr_reversearray(int *arr, int size)
// {
//     int l = 0, r = size - 1, tmp;
//     while(l<r)
//     {
//         int *ptrFirst = &arr[l];
//         int *ptrLast = &arr[r];
//         tmp = *ptrLast;
//         *ptrLast = *ptrFirst;
//         *ptrFirst = tmp;
//         l++;
//          r--;
//     }
// }
// int main()
// {
//     int arr[] = {2, 11, 12, 21, 22};
//     int arrSize = sizeof(arr) / sizeof(arr[0]);
//     ptr_reversearray(arr, arrSize);
//     for (int i = 0; i < arrSize; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }

// bai 7
#include <stdlib.h>
int *a;
int n, tmp;
int main()
{
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    // #Allocate memory
    a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", (a + i));
    printf("The input array is: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    // #Sort array
    int arrSize = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (*(a + j) > *(a + j + 1))
            {
                tmp = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = tmp;
            }
        }
    }
    printf("The sorted array is: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    // delete[] a;
    return 0;
}
