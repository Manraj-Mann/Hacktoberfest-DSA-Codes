// Java program to sort an array
// using bucket sort
import java.util.*;
import java.util.Collections;
  
class bucket {
  
    // Function to sort array[] of size n
    // using bucket sort
    static void bucketSort(float array[], int n)
    {
        if (n <= 0)
            return;
  
        // Create n empty buckets
        Vector<Float>[] buckets = new Vector[n];
  
        for (int i = 0; i < n; i++) {
            buckets[i] = new Vector<Float>();
        }
  
        //Put the array elements in different buckets
        for (int i = 0; i < n; i++) {
            float ind = array[i] * n;
            buckets[(int)ind].add(array[i]);
        }
  
        //Sorting individual buckets
        for (int i = 0; i < n; i++) {
            Collections.sort(buckets[i]);
        }
  
        //Concatenate all buckets into array[]
        int index = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < buckets[i].size(); j++) {
                array[index++] = buckets[i].get(j);
            }
        }
    }
  
    // Driver code
    public static void main(String args[])
    {
        float array[] = { (float)0.897, (float)0.565,
                        (float)0.656, (float)0.1234,
                        (float)0.665, (float)0.3434 };
  
        int n = array.length;
        bucketSort(array, n);
  
        System.out.println("Sorted array is ");
        for (float el : array) {
            System.out.print(el + " ");
        }
    }
}