import java.math.BigInteger;
import java.util.*;

public class D_Plus_Minus_Permutation
{
    public static void main(String[] args) {
        int t=0;
        Scanner sc = new Scanner(System.in);
        Solution s = new Solution();
        t = sc.nextInt();
        sc.nextLine();
        while(t>0)
        {
            t--;
            long n,x,y;
            n=sc.nextLong();
            x=sc.nextLong();
            y=sc.nextLong();
            s.helper(n,x,y);
        }
        sc.close();
    }
}

class Solution {

    private long getSumOfNaturalNumbers(long n)
    {
        long N = n*1L;
        return (N*(N+1)*1L)/(2*1L);
    }

    private long gcd(long a,long b)
    {
        if(b==0) return a;
        else{
            long remainder = a%b;
            return gcd(b,remainder);
        }
    }

    public void helper(long n,long x,long y)
    {
        if(x==y)
        {
            System.out.println(0);
            return;
        }
        long sum=0L;
        long commonMultiple = 0;

        long max,min;
        max = Math.max(x, y);
        min = Math.min(x, y);
        long gcdVal = gcd(max, min);
        commonMultiple = (x*y+0L)/(gcdVal+0L);

        long countOfCommonDivisor =(n*1L/commonMultiple*1L);
        long countOfXDivisor = n/x - countOfCommonDivisor;
        long countOfYDivisor = n/y - countOfCommonDivisor;
        long sumOfX = getSumOfNaturalNumbers(n) - getSumOfNaturalNumbers(n-countOfXDivisor);
        long sumOfY = getSumOfNaturalNumbers(countOfYDivisor);
        sum = sumOfX - sumOfY;
        System.out.println(sum);
        return;
    }
}