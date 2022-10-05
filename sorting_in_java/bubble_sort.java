// Java program to sort an array
// using bubble sort
import java.util.*;
import java.util.Collections;
//BUBBLE SORT
public static void bubbleSort(int[] a) {
    boolean sorted = false;
    int temp;
    while(!sorted) {
        sorted = true;
        for (int i = 0; i < array.length - 1; i++) {
            if (a[i] > a[i+1]) {
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                sorted = false;
            }
        }
    }
}

// Driver code
    public static void main(String args[])
    {
        float array[] = { 8, 13,1, 9,21, 2};
  
        int n = array.length;
        bubbleSort(array, n);
  
        System.out.println("Sorted array is ");
        for (float el : array) {
            System.out.print(el + " ");
        }
    }