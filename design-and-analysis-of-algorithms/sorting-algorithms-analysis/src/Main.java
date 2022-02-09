import monitoring.Benchmark;
import sorting.BubbleSort;
import sorting.SelectionSort;
import utils.SortUtils;

public class Main {

    public static void main(String[] args) {
        int[] array = {1, 21, 10, 13, 2, -1};

        selectionSort(array);
        Benchmark.restart();
        bubbleSort(array);

        SortUtils.print(array);
    
    }

    public static void selectionSort(int[] array) {
        int[] clone = array.clone();

        System.out.println("Selection Sort");

        System.out.println("Before... ");
        SortUtils.print(clone);
        
        var algorithm = new SelectionSort();
        
        algorithm.sort(clone);
        
        System.out.println("After... ");
        SortUtils.print(clone);

        System.out.println("Logging benchmark...");
        Benchmark.printOperations();
    }

    public static void bubbleSort(int[] array) {
        int[] clone = array.clone();

        System.out.println("Bubble Sort");

        System.out.println("Before... ");
        SortUtils.print(clone);
        
        var algorithm = new BubbleSort();
        
        algorithm.sort(clone);
        
        System.out.println("After... ");
        SortUtils.print(clone);

        System.out.println("Logging benchmark...");
        Benchmark.printOperations();
    }
}