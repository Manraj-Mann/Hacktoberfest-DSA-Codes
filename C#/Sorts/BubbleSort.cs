using System;

public class BubbleSort
{
    // Sample Data
    private readonly int[] items = { 4, 100, 2, 23, 18, 1};
    
    public static void Main(string[] args)
    {
        var bubbleSort = new BubbleSort();
        var newItems = bubbleSort.Sort(bubbleSort.items);
        
        foreach (int item in newItems)
        {
            Console.WriteLine(item + " ");
        }
    }
 
    private int[] Sort(int[] list)
    {
        int temp;
        
        for (int i = 0; i <= list.Length - 2; i++) {
            for (int j = 0; j <= list.Length - 2; j++) {
               if (list[j] > list[j + 1]) {
                  temp = list[j + 1];
                  list[j + 1] = list[j];
                  list[j] = temp;
               }
            }
        }
        
        return list;
    }
}
