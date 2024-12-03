import java.util.*;

public class D_Friends_and_the_Restaurant
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
		    int n=sc.nextInt();
            long[] a = new long[n];
            long[] b = new long[n];
            for(int i=0;i<n;i++){
                a[i]=sc.nextLong();
            }
            for(int i=0;i<n;i++){
                b[i]=sc.nextLong();
            }
            s.helper(a,b,n);
		}
	}
}

class Solution {
    public void helper(long[] a,long[] b,int n)
    {
        long[] diff = new long[n];
        for(int i=0;i<n;i++){
            diff[i]=b[i]-a[i];
        } 
        List<Long> pos = new ArrayList<>();
        TreeMap<Long,Long> neg = new TreeMap<>();
        List<Long> zero = new ArrayList<>();
        for(int i=0;i<n;i++){
            if(diff[i]>0){
                pos.add(Math.abs(diff[i]));
            }
            else if(diff[i]<0){
                if(neg.containsKey(Math.abs(diff[i]))){
                    long val = neg.get(Math.abs(diff[i]));
                    neg.put(Math.abs(diff[i]),val+1);
                }
                else neg.put(Math.abs(diff[i]),1L);
            }
            else{
                zero.add(1L);
            }
        }
        Collections.sort(pos);
        // System.out.println(neg);
        // System.out.println(neg);
        long count = 0;
        long positive = 0;
        // count+=(zero.size()/2);
        for(int i=0;i<pos.size();i++){
            if(neg.containsKey(pos.get(i)) && neg.get(pos.get(i))>0){
                count++;
                long val = neg.get(pos.get(i));
                val--;
                positive++;
                if(val<=0){
                    neg.remove(pos.get(i));
                }
                else neg.put(pos.get(i),val);
            }
            else{
                if(neg.lowerKey(pos.get(i))!=null){
                    long upperBoundKey = neg.lowerKey(pos.get(i));
                    if(neg.get(upperBoundKey)>0){
                        long val = neg.get(upperBoundKey);
                        val--;
                        if(val<=0){
                            neg.remove(upperBoundKey);
                        }
                        else neg.put(upperBoundKey,val);
                        positive++;
                        count++;
                    }
                    else{
                        continue;
                    }
                }
            }
        }
        long rem = pos.size() - positive;
        long countOfZero = zero.size();
        count+=((rem+countOfZero)/2);
        System.out.println(count);
    }
}
//4 5 2 7 3
//3 5 3 2 5
//-1 0 1 -5 2