// Java program to sort an array
// using quick sort
import java.util.*;
import java.util.Collections;
    
    //QUICK SORT
static int partition(int[] array, int begin, int end) {
    int pivot = end;

    int counter = begin;
    for (int i = begin; i < end; i++) {
        if (array[i] < array[pivot]) {
            int temp = array[counter];
            array[counter] = array[i];
            array[i] = temp;
            counter++;
        }
    }
    int temp = array[pivot];
    array[pivot] = array[counter];
    array[counter] = temp;

    return counter;
}

public static void quickSort(int[] array, int begin, int end) {
    if (end <= begin) return;
    int pivot = partition(array, begin, end);
    quickSort(array, begin, pivot-1);
    quickSort(array, pivot+1, end);
}

// Driver code
    public static void main(String args[])
    {
        float array[] = { 8, 13,1, 9,21, 2};
  
        int n = array.length;
        quickSort(array, n);
  
        System.out.println("Sorted array is ");
        for (float el : array) {
            System.out.print(el + " ");
        }
    }
    
