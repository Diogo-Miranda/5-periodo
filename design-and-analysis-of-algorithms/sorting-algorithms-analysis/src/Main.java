import sorting.SelectionSort;
import utils.SortUtils;

public class Main {

    public static void main(String[] args) {
        int[] array = {1, 21, 10, 13, 2, -1};
        
        System.out.println("Before... ");
        SortUtils.print(array);
        
        var algorithm = new SelectionSort();
        
        algorithm.sort(array);
        
        System.out.println("After... ");
        SortUtils.print(array);
    }
}