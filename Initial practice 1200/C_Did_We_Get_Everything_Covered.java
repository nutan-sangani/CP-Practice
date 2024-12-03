import java.util.*;

public class C_Did_We_Get_Everything_Covered
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
            int n,k,m;
            n=sc.nextInt();
            k=sc.nextInt();
            m=sc.nextInt();
            String str = sc.next();
            s.helper(n,k,m,str);
        }
    }
}

class Solution {
    public void helper(int n,int k,int m,String s)
    {
        int uniqueCount=0;
        Set<Character> set = new HashSet<>();
        List<Integer> boundary = new ArrayList<>();
        for(int i=m-1;i>=0;i--){
            if(!set.contains(s.charAt(i))){
                uniqueCount++;
                set.add(s.charAt(i));
                if(uniqueCount==k){
                    boundary.add(i);
                    uniqueCount=0;
                    set.clear();
                }
            }
        }
        set.clear();
        Collections.sort(boundary,Comparator.naturalOrder());
        if(boundary.size()>=n){
            System.out.println("YES");
            return;
        }
        int i;
        System.out.println("NO");


        if(boundary.size()>1 && boundary.get(0)!=0)
            i=boundary.get(0)-1;
        else i=m-1;
        for(;i>=0;i--){
            set.add(s.charAt(i));
        }
        for(int j=0;j<k;j++){
            if(!set.contains((char)('a'+j))){
                String ans = "";
                for(int z=0;z<n;z++){
                    ans=ans+(char)('a'+j);
                }  
                System.out.println(ans);
                return; 
            }
        }
    }
}