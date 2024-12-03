import java.util.*;

public class B_Minimize_Inversions
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
            Pair[] list = new Pair[n];
            for(int i=0;i<n;i++){
                Pair nn = new Pair(1,2);
                nn.value=sc.nextInt();
                list[i]=nn;
            }
            for(int i=0;i<n;i++){
                list[i].index=sc.nextInt();
            }
            s.helper(list,n);
        }
        sc.close();
    }
}

class Pair{
    int value;
    int index;
    public Pair(int value,int index){
        this.value=value;
        this.index=index;
    }
}

class MyComp implements Comparator<Pair>{
    @Override
    public int compare(Pair o1, Pair o2) {
        if(o1.value<o2.value) return -1;
        else if(o1.value>o2.value) return 1;
        else return 0;
    }
}

class Solution {
    public void helper(Pair[] list,int n)
    {
        Arrays.sort(list,new MyComp());
        for(int i=0;i<n;i++){
            System.out.print(list[i].value+" ");
        }
        System.out.println();
        for(int i=0;i<n;i++){
            System.out.print(list[i].index+" ");
        }
        System.out.println();
        return;
    }
}