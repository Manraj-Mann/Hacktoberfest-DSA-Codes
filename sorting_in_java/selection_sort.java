// Java program to sort an array
// using selection sort
import java.util.*;
import java.util.Collections;
//SELECTION SORT
public static void selectionSort(int[] array) {
    for (int i = 0; i < array.length; i++) {
        int min = array[i];
        int minId = i;
        for (int j = i+1; j < array.length; j++) {
            if (array[j] < min) {
                min = array[j];
                minId = j;
            }
        }
        // swapping
        int temp = array[i];
        array[i] = min;
        array[minId] = temp;
    }
}

// Driver code
    public static void main(String args[])
    {
        float array[] = { 8, 13,1, 9,21, 2};
  
        int n = array.length;
        selectionSort(array, n);
  
        System.out.println("Sorted array is ");
        for (float el : array) {
            System.out.print(el + " ");
        }
    }