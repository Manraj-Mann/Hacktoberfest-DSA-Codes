//GFG
//Write a program to cyclically rotate an array by one.


//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main(String[] args) throws IOException
	{
	        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t =
            Integer.parseInt(br.readLine().trim()); // Inputting the testcases
        while(t-->0)
        {
            long n = Long.parseLong(br.readLine().trim());
            long a[] = new long[(int)(n)];
            // long getAnswer[] = new long[(int)(n)];
            String inputLine[] = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                a[i] = Long.parseLong(inputLine[i]);
            }
            
            Compute obj = new Compute();
            obj.rotate(a, n);
            
            StringBuilder output = new StringBuilder();
            for(int i=0;i<n;i++)
                output.append(a[i]+" ");
            System.out.println(output);
            
        }
	}
}

// } Driver Code Ends


//User function Template for Java

class Compute {
    
    public void rotate(long arr[], long n)
    {
        int m = arr.length;
        int temp[] = new int[m - 1];
        for (int i = 0; i < m - 1; i++) {
            temp[i] = (int) arr[i];
           
        }
        arr[0]=arr[m-1];
        for (int i = 1; i <m ; i++) {
            arr[i]=temp[i-1];
        }
        //temp=arr[0];
    }
}
