package utils;

import monitoring.Benchmark;

public class SortUtils {
    public static void swap(int[] array, int i, int j) {
        Benchmark.addOperation(3);
        
        int aux = array[i];
        array[i] = array[j];
        array[j] = aux;
    }

    public static void print(int[] array) {
        for(int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        } 
        System.out.println("\n");
    }
}
 