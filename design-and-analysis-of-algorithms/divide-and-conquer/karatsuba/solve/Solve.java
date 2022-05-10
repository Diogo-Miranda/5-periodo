package solve;

class Solve {
    public static void main(String[] args) {
        int x = 1010;
        int y = 1010;
        
        int result = (int) karatsuba(x, y);

        System.out.println(result);
    }

    // XY = a1*b1*10^n + [(a1*b2+a2*b1)-a1*b1-a2*b2]*10^n/2 + a2*b2 
    // n = length
    static int karatsuba(int x, int y) {
        if(x <= 10 || y <= 10) {
            return x * y;
        }

        int n = 4;
        int half = n/2;

        int a = (int) ( x / ((int) Math.pow(10,half)) ); // left part of number x
        int b = (int) ( x % ((int) Math.pow(10, half)) ); // right part of number x
        int c = (int) ( y / ((int) Math.pow(10, half)) ); // left part of number y
        int d = (int) ( y % ((int) Math.pow(10, half)) ); // right part of number y
        int ac = (int) karatsuba(a, c);
        int bd = (int) karatsuba(b, d);
        int adPlusBc = (int) karatsuba(a+b, c+d)-ac-bd;
        return (int) ( ac * ( Math.pow(10, (2*half)) ) + (adPlusBc * ( Math.pow(10, half))) + bd );
    }
}