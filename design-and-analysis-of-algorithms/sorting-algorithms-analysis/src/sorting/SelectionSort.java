package sorting;

import domain.sorting.Sort;
import monitoring.Benchmark;
import utils.SortUtils;

public class SelectionSort implements Sort {
    
    public void sort(int[] array) {
        for(int i = 0; i < array.length-1; i++) {
            Benchmark.addOperation(4);

            int minIndex = i;
            Benchmark.addOperation(1);

            for(int j = i+1; j < array.length; j++) {
                Benchmark.addOperation(4);

                Benchmark.addOperation(1);
                if(array[j] < array[minIndex]) { 
                    minIndex = j;
                    Benchmark.addOperation(1);
                }
            }

            SortUtils.swap(array, i, minIndex);
        }
    }

}
