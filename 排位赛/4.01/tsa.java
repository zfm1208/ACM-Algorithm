import java.util.Scanner;
import java.math.BigInteger;
public class tsa {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while(in.hasNextBigInteger()){
            BigInteger a = in.nextBigInteger();
            BigInteger b = in.nextBigInteger();
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