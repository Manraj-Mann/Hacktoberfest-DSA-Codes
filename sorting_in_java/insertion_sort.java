// Java program to sort an array
// using insertion sort
import java.util.*;
import java.util.Collections; 
//INSERTION SORT
public static void insertionSort(int[] array) {
    for (int i = 1; i < array.length; i++) {
        int current = array[i];
        int j = i - 1;
        while(j >= 0 && current < array[j]) {
            array[j+1] = array[j];
            j--;
        }
        // at this point we've exited, so j is either -1
        // or it's at the first element where current >= a[j]
        array[j+1] = current;
    }
}

// Driver code
    public static void main(String args[])
    {
        float array[] = { 8, 13,1, 9,21, 2};
  
        int n = array.length;
        insertionSort(array, n);
  
        System.out.println("Sorted array is ");
        for (float el : array) {
            System.out.print(el + " ");
        }
    }