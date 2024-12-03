import java.util.*;

public class C_Make_Them_Equal
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
            String sa = sc.next();
            char a=sa.charAt(0);
            sc.nextLine();
            String str=sc.next();
            s.helper(n,str,a);
		}
        sc.close();
	}
}

class Solution {
    private boolean checkMultipleNeeded(HashSet<Long> required,int n,int i){
        long j=1;
        while((j*i)<=(long)n){
            if(required.contains(j*i)){
                return false;
            }
            else j++;
        }
        return true;
    }

    public void helper(int n,String s,char a)
    {
        HashSet<Long> required = new HashSet<>();
        int allSame=1;
        int count=0;
        for(int i=0;i<n;i++){
            if(s.charAt(i)!=a){
                allSame=0;
                count++;
                required.add((long)i+1);
            }
        }
        if(allSame==1){
            System.out.println(0);
            return;
        }
        if(count==1){
            System.out.println(1);
            if(s.charAt(n-1)==a){
                System.out.println(n);
            }
            else System.out.println(n-1);
            return;
        }
        for(int i=1;i<=n;i++){
            if(checkMultipleNeeded(required, n, i)){
                System.out.println(1);
                System.out.println(i);
                return;
            }
        }
        System.out.println(2);
        System.out.print(n+" ");
        System.out.print(n-1);
        System.out.println();
        return;
    }
}