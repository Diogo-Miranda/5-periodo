package sorting;

import domain.sorting.Sort;
import monitoring.Benchmark;
import utils.SortUtils;

public class BubbleSort implements Sort {
    
    public void sort(int[] array) {
        for(int i = 0; i < array.length-1; i++) {
            Benchmark.addOperation(4);
            for(int j = 0; j < array.length-i-1; j++) {
                Benchmark.addOperation(5);
                
                Benchmark.addOperation(1);
                if(array[j] > array[i]) {
                    SortUtils.swap(array, i, j);
                }
            }
        }
    } 
}
