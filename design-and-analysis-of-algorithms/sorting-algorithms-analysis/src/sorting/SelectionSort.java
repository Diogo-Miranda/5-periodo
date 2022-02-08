package sorting;

import domain.sorting.Sort;
import utils.SortUtils;

public class SelectionSort implements Sort {
    
    public void sort(int[] array) {
        for(int i = 0; i < array.length-1; i++) {
            int minIndex = i;
            for(int j = i+1; j < array.length; j++) {
                if(array[j] < array[minIndex]) 
                    minIndex = j;
            }

            SortUtils.swap(array, i, minIndex);
        }
    }

}
