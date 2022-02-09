package monitoring;

public class Benchmark {
    public static int operations = 0;

    public static void printOperations() {
        System.out.println("Actual counting " + operations + " operations.");
    }

    public static void addOperation(int number) {
        operations += number;
    }

    public static void restart() {
        operations = 0;
    }
}
