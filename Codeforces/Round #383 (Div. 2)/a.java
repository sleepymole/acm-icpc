import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int a = 1378, r = 1;
        while (n > 0) {
            if (n % 2 == 1) r = r * a % 10;
            a = a * a % 10;
            n >>= 1;
        }
        System.out.println(r);
    }
}