// { Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class Sorting
{
    public static void main (String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        long t = sc.nextLong();
        
        while(t-- > 0)
        {
            long n = sc.nextLong();
            long arr[] = new long[(int)n];
            
            for(long i = 0; i < n; i++)
             arr[(int)i] = sc.nextLong();
             
            System.out.println(new Solution().inversionCount(arr, n));
            
        }
    }
}
// } Driver Code Ends

//User function Template for Java

class Solution
{
    // arr[]: Input Array
    // N : Size of the Array arr[]
    //Function to count inversions in the array.
    static long inversionCount(long arr[], long N)
    {
        long result = sortAndCount(arr, 0, N-1);
        
        return result; 
    } 
    
    static long sortAndCount(long arr[], long start, long end) {
        long count = 0;
        
        if(start < end) {
            long mid = (end + start) / 2;
            
            count += sortAndCount(arr, start, mid);
            count += sortAndCount(arr, mid+1, end);
            count += mergeAndCount(arr, start, mid, end);
        }
        
        return count;
    }
    
    static long mergeAndCount(long arr[], long start, long mid, long end) {
        // copy array left
        long[] left = Arrays.copyOfRange(arr, (int)start, (int)mid+1);
        
        // copy arrtay right 
        long[] right = Arrays.copyOfRange(arr, (int)mid+1 , (int)end+1);
        
        long i = 0; // left index
        long j = 0; // right index
        long k = start; // auxiliary index
        long swaps = 0; // couting swaps
        
        while(i < left.length && j < right.length) {
            if(left[(int)i] <= right[(int)j]) {
                arr[(int)k] = left[(int)i];
                k = k + 1L;
                i = i + 1L;
            } else {
                arr[(int)k] = right[(int)j];
                k = k + 1L;
                j = j + 1L;
                swaps += (mid + 1) - (start + i);
            }
        }
        
        while(i < left.length) {
            arr[(int)k] = left[(int)i];
            k = k + 1L;
            i = i + 1L;
        }
            
        while(j < right.length) { 
            arr[(int)k] = right[(int)j];
            k = k + 1L;
            j = j + 1L;
        }

        return swaps;
    } 
}