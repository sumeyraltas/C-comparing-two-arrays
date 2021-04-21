#include <stdio.h>
#define SIZE 500

// reads numbers from the standard input into arr,
// and stores the number of read elements in the memory cell pointed to by nPtr
void readInput(int arr[], int *nPtr);


// prints the elements in arr[0..(n-1)]
void printNumbers(const int arr[], int n);


// Let n be the minimum of n1 and n2 where n1 and n2 are the number of elements in
// arr1 and arr2, respectively.
// Compare corresponding elements of arr1 and arr2 at each of the first n positions.
//
// If arr1 and arr2 has the same value in each position:
// Return 0 if n1 == n2
// Return 1 if n1 > n2
// Return -1 if n1 < n2
//
// If arr1 has a larger value than arr2 considering the first position from the
// beginning at which arr1 and arr2 have a different value:
// Return 1
//
// If arr1 has a smaller value than arr2 considering the first position from the
// beginning at which arr1 and arr2 have a different value:
// Return -1
int compareTwoArrays(const int arr1[], const int arr2[], int n1, int n2);

int main()
{
    int arr1[SIZE];
    int n1;

    int arr2[SIZE];
    int n2;

    readInput(arr1, &n1);
    printNumbers(arr1, n1);

    readInput(arr2, &n2);
    printNumbers(arr2, n2);

    int result = compareTwoArrays(arr1, arr2, n1, n2);

    if (result == 0)
        printf("\nEqual\n");
    else if (result == -1)
        printf("\nLess than\n");
    else if (result == 1)
        printf("\nGreater than\n");

    return 0;
}

void readInput(int arr[], int *nPtr)
{
    printf("Enter the number of elements: \n");
    scanf("%d", &*nPtr);
    printf("Enter %d elements: \n", *nPtr);
    for (int i = 0; i < *nPtr; i++)
      scanf("%d", &arr[i]);
}

void printNumbers(const int arr[], int n)
{

     printf("Array elements: ");
     for(int i = 0; i < n; i++)
      printf("%d ", arr[i]);
     printf("\n");
}

int compareTwoArrays(const int arr1[], const int arr2[], int n1, int n2)
{
    int i,a,b;
    if(n1 < n2) b=n2;
    if(n2 < n1) b=n1;

    for(i = 0; i < b ; i++ ){
    if(arr1[i] == arr2[i]){
      a = 0;
        if(n1 < n2) a=-1;
        if(n2 < n1) a=1;
    }
    if(arr1[i] > arr2[i]){
      a = 1;
    break;
    }
    if(arr1[i] < arr2[i]){
      a = -1;
    break;
    }
    }
    if(n1 == 0) a =-1;
    if(n2 == 0) a = 1;
    if(n1 ==0  && n2== 0) a= 0;

    return a;
}
