import java.util.Scanner;
import java.math.BigInteger;
public class tsa {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextBigInteger()){
            BigInteger a = sc.nextBigInteger();
            BigInteger b = sc.nextBigInteger();
            BigInteger ans = a.divide(b);
            if(a.signum() * b.signum() < 0){
                BigInteger r = a.remainder(b);
                if(!r.equals(BigInteger.ZERO))
                    ans = ans.subtract(BigInteger.ONE);
            }
            System.out.println(ans);
        }
    }
}