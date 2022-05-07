import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger start = sc.nextBigInteger();
        BigInteger end = sc.nextBigInteger();

        BigInteger result;
        result = end.divide(BigInteger.valueOf(3)).subtract(start.divide(BigInteger.valueOf(3)));
        System.out.println(result);
    }
}