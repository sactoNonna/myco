#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <string.h>

#define True    1
#define False   0
#define SUCCESS 0
#define ERROR   -1

void displayTime(time_t t, char *string) {
    printf("%s", string);
    printf("%s", asctime(gmtime(&t)));
}

void displayRuntime(time_t t1, time_t t2) {

    double elapsedTime;
    int hours, minutes, seconds;

    elapsedTime = difftime(t2, t1);
    hours = elapsedTime/3600;
    elapsedTime -= hours*3600;
    minutes = elapsedTime/60;
    seconds = (int)elapsedTime % 60;

    // Print the elapsed time in HH:MM:SS format
    printf("\n\t\tElapsed Time: %02d:%02d:%02d\n", hours, minutes, seconds);
}

int main(int argc, char *argv[]) {
    //int maxBuf = atoi(argv[1]);
    int maxBuf = 1000000;
    int *arr, *brr, *crr, *newArr;
    time_t t = 0, t1, t2;
    void displayTime(time_t t, char *s);
    void displayRuntime(time_t t1, time_t t2);
    int i, bStart, bEnd;
    void selectionSort(int *arr, int bStart, int bEnd);
    void bubbleSort(int *arr, int bStart, int bEnd); 
    void mergeSort(int *newArr, int *arr, int bStart, int bEnd);
    void merge(int *newArr, int *arr, int lStart, int lEnd, int rStart, int rEnd);
    void quickSort(int *arr, int bStart, int bEnd);
    void swap(int *px, int *py); 
    void arrCpy(int *dest, int *src, int bStart, int bEnd);
    int arrCmp(int *dest, int *src, int bStart, int bEnd);
    void printArr(int *arr, int bStart, int bEnd);
    void jvQuicksort(arr, bStart, bEnd);

    srand((unsigned int)t = time(NULL));

    if ((arr = malloc(maxBuf*sizeof(int))) == NULL)
       return ERROR;
    if ((brr = malloc(maxBuf*sizeof(int))) == NULL) {
        free(arr);        
        return ERROR;
    }
    if ((crr = malloc(maxBuf*sizeof(int))) == NULL) {
        free(arr);
        free(brr);
        return ERROR;
    }

    bStart = 0;
    bEnd = maxBuf-1;
    for (i = 0; i < maxBuf; i++)
        arr[i] = (int)rand() % (bEnd - bStart + 1);

    arrCpy(brr, arr, bStart, bEnd);
    printf("\nArray for %u(0x%08x) elements created.\n",(bEnd-bStart+1),(bEnd-bStart+1));
    //printArr(brr, bStart, bEnd);

// quickSort() - 1: The last element as pivot

    printf("\n\nQuickSort1 - The last element as pivot:");
    //printArr(arr, bStart, bEnd);
    t1 = time(NULL);
    displayTime((time_t)t1, "\n\t\tStart Time: ");
    jvQuicksort(arr, bStart, bEnd);
    t2 = time(NULL);
    displayTime((time_t)t2, "\t\tEnd Time: ");
    displayRuntime(t1, t2);
    //printArr(arr, bStart, bEnd);
    arrCpy(crr, arr, bStart, bEnd);
    arrCpy(arr, brr, bStart, bEnd);

// quickSort() - 2: The middle element as pivot    

    printf("\n\nQuickSort2 - The middle element as pivot:"); 
    arrCpy(arr, brr, bStart, bEnd);
    t1 = time(NULL);
    displayTime((time_t)t1, "\n\t\tStart Time: ");
    quickSort(arr, bStart, bEnd);
    t2 = time(NULL);
    displayTime((time_t)t2, "\t\tEnd Time: ");
    displayRuntime(t1, t2);

    if (arrCmp(crr, arr, bStart, bEnd) == False) 
        return(printf ("ERROR: The results from QuickSort1 and QuickSort2 are different!\n"));
    else
        printf ("SUCCESS: The results from QuickSort1 and QuickSort2 are the same.\n");

// mergeSort()

    arrCpy(arr, brr, bStart, bEnd);
    if ((newArr = malloc(maxBuf*sizeof(int))) == NULL) {
        printf("malloc error - exiting...\n");
        return ERROR;    
    }
    printf("\n\nMergeSort:");
    //printArr(arr, bStart, bEnd);
    t1 = time(NULL);
    displayTime((time_t)t1, "\n\t\tStart Time: ");   
    mergeSort(newArr, arr, bStart, bEnd);
    t2 = time(NULL);
    displayTime((time_t)t2, "\t\tEnd Time: ");
    displayRuntime(t1, t2);

    if (arrCmp(crr, newArr, bStart, bEnd) == False) 
        return(printf ("ERROR: The result from MergeSort is different from others!\n"));
    else
        printf ("SUCCESS: The result from MergeSort is the same as others.\n");

// selectionSort()

    printf("\n\nSelectionSort:");
    //printArr(arr, bStart, bEnd);
    t1 = time(NULL);
    displayTime((time_t)t1, "\n\t\tStart Time: ");
    selectionSort(arr, bStart, bEnd);
    t2 = time(NULL);
    displayTime((time_t)t2, "\t\tEnd Time: ");
    displayRuntime(t1, t2);

    if (arrCmp(crr, arr, bStart, bEnd) == False) 
        return(printf ("ERROR: The result from SelectionSort is different from others!\n"));
    else
        printf ("SUCCESS: The result from SelectionSort is the same as others.\n");

// bubbleSort()

    arrCpy(arr, brr, bStart, bEnd);
    printf("\n\nBubbleSort:");
    //printArr(arr, bStart, bEnd);
    t1 = time(NULL);
    displayTime((time_t)t1, "\n\t\tStart Time: ");
    bubbleSort(arr, bStart, bEnd);
    t2 = time(NULL);
    displayTime((time_t)t2, "\t\tEnd Time: ");
    displayRuntime(t1, t2);

    if (arrCmp(crr, arr, bStart, bEnd) == False) 
        return(printf ("ERROR: The result from BubbleSort is different from others!\n"));
    else
        printf ("SUCCESS: The result from BubbleSort is the same as others.\n");

    free(arr);
    free(brr);
    free(crr);
}

void jvQuicksort (int* array, int lowIndex, int highIndex) {
    void jvSwap(int *array, int index1, int index2);

    if (lowIndex >= highIndex) {
      return;
    }

    int pivot = array[highIndex];

    int leftPointer = lowIndex;
    int rightPointer = highIndex;

    while (leftPointer < rightPointer) {
        while (array[leftPointer] <= pivot && leftPointer < rightPointer) {
            leftPointer++;
        }
        while (array[rightPointer] >= pivot && leftPointer < rightPointer) {
            rightPointer--;
        }
        jvSwap(array, leftPointer, rightPointer);
    }
    jvSwap(array, leftPointer, highIndex);

    jvQuicksort(array, lowIndex, leftPointer - 1);
    jvQuicksort(array, leftPointer + 1, highIndex);

    // This is different from what the video has, and fixes an issue where the last value could potentially be out of order. 
    // Thanks to viewer Wilson Barbosa for suggesting the fix!
    //if(array[leftPointer] > array[highIndex]) {
    //  jvSwap(array, leftPointer, highIndex);
    //}
    //else {
    //  leftPointer = highIndex;
}

void jvSwap(int *array, int index1, int index2) {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void selectionSort (int *arr, int bStart, int bEnd) {
    int i, j, iMin;
    unsigned long loopCount = 0;

    for (i = bStart; i <= bEnd; i++) {
        iMin = i;
        for (j = i+1; j <= bEnd; j++) {
            loopCount += 1;
            if (arr[j] < arr[iMin])
                iMin = j;
        }
        swap(&arr[i], &arr[iMin]);
    }
    printf("\n    loopCount = %lu", loopCount);
}

void mergeSort (int *newArr, int *arr, int bStart, int bEnd) {
    int bufSize, lStart, lEnd, rStart, rEnd;

    bufSize = bEnd - bStart + 1;
    if (bufSize == 1) {
        return;
    }

    lStart = bStart;
    rStart = bStart + (int) (bufSize/2);
    lEnd = rStart - 1;
    rEnd = bEnd;

    mergeSort(newArr, arr, lStart, lEnd) ;
    mergeSort(newArr, arr, rStart, rEnd) ;
    merge(newArr, arr, lStart, lEnd, rStart, rEnd);
}

void merge(int *newArr, int *arr, int lStart, int lEnd, int rStart, int rEnd) {
    int ll = lStart;
    int rr = rStart;
    int i = lStart;

    while (True) {
        if (arr[ll] < arr[rr])
            newArr[i++] = arr[ll++];
        else 
            newArr[i++] = arr[rr++];

        if (ll > lEnd) {
            if (rr > rEnd)
                break;
            arrCpy(newArr+i, arr+rr, 0, rEnd-rr);
            break;
        }
        else if (rr > rEnd) {
            arrCpy(newArr+i, arr+ll, 0, lEnd-ll);
            break;
        }
    }
    arrCpy(arr, newArr, lStart, rEnd);
}

void quickSort (int *arr, int left, int right) {
	int i, last;
	void qswap(int *arr, int i, int j);

	if (left >= right)
		return;
	qswap(arr, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (arr[i] < arr[left])
			qswap(arr, ++last, i);
	qswap(arr, left, last);
	quickSort(arr, left, last - 1);
	quickSort(arr, last + 1, right);
}

void bubbleSort (int *arr, int bStart, int bEnd) {
    int j, swapCount = True;
    unsigned long loopCount = 0;

    while (swapCount) {
        swapCount = False;
        for (j = bStart; j <= bEnd - 1; j++) {
            loopCount += 1;
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swapCount = True;
            }
        }
        if (swapCount == False) {
            //printf("\n    loopCount = %lu", loopCount);
            //return;
            break;
        }
    }
    printf("\n    loopCount = %lu", loopCount);
    return;
}

void qswap(int *arr, int i, int j)
{
	int temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void swap (int *px, int *py) {
    int tmp;
    tmp = *px;
    *px = *py;
    *py = tmp;
}

void arrCpy(int *dest, int *src, int bStart, int bEnd) {
    int i;

    for (i = bStart; i <= bEnd; i++)
        dest[i] = src[i];       
}

int arrCmp(int *dest, int *src, int bStart, int bEnd) {
    int i;

    for (i = bStart; i <= bEnd; i++)
        if (dest[i] != src[i])
            return False;
    return True;
}

void printArr (int *arr, int bStart, int bEnd) {
    int i;

    return;

    for (i = bStart; i <= bEnd; i++)
        printf("%i ", arr[i]);
    printf("\n");
}
