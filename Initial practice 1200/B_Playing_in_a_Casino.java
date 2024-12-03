import java.util.*;

public class B_Playing_in_a_Casino
{
    public static void main(String[] args) {
        long t=0;
        Scanner sc = new Scanner(System.in);
        Solution s = new Solution();
        t = sc.nextInt();
        sc.nextLine();
        while(t>0)
        {
            t--;
            long n,m;
            n=sc.nextInt();
            m=sc.nextInt();
            Long[][] cards = new Long[(int)m][(int)n];
            long[] row = new long[(int)m];
            for(long i=0;i<n;i++){
                for(long j=0;j<m;j++){
                    row[(int)j]=sc.nextInt();
                }
                for(long j=0;j<m;j++){
                    cards[(int)j][(int)i]=row[(int)j];
                }
            }
            s.helper(n,m,cards); //cards is m*n
        }
    }
}

class Solution {
    public void helper(long n,long m,Long[][] cards)
    {
        long ans=0;
        for(int i=0;i<m;i++){
            Arrays.sort(cards[i],Comparator.reverseOrder());
        }
        long[][] prefixSum = new long[(int)m][(int)n];
        for(int i=0;i<m;i++)
        {
            long sum=0;
            for(long j=n-1;j>=0;j--){
                prefixSum[i][(int)j]=sum;
                sum+=cards[i][(int)j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                long remTerm = n-j-1;
                long firstTerm = (remTerm*1L)*cards[i][j];
                long secondTerm = prefixSum[i][j];
                long difference = firstTerm - secondTerm;
                ans+=difference;
            }
        }
        System.out.println(ans);
    }
}