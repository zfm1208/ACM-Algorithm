import java.util.Scanner;
import java.math.BigInteger;
public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger x = sc.nextBigInteger();
        BigInteger ans = BigInteger.ONE;
        BigInteger cnt = BigInteger.ONE;
        while(!ans.remainder(x).equals(BigInteger.ZERO)){
            cnt = cnt.add(BigInteger.ONE);
            ans = ans.multiply(BigInteger.TEN).add(BigInteger.ONE);
        }
        System.out.println(ans.divide(x) + " " + cnt);
    }
}