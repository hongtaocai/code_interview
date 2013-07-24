/**
*/
import java.util.ArrayList;
import java.util.Collections;

public class Solution {
   public ArrayList<ArrayList<Integer>> threeSum(int[] num) {
        // Start typing your Java solution below
        // DO NOT write main() function

        ArrayList<Integer> numArr = new ArrayList<Integer>();
        for(int i=0;i<num.length;i++){
            numArr.add(num[i]);
        }
        Collections.sort(numArr);
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer> >();
        for(int i=0;i<numArr.size();i++){
            if(numArr.get(i)>0) break;
            int j,k;
            j = i+1;
            k = numArr.size()-1;
            while(j<k){
                int tmpSum = numArr.get(i)+numArr.get(j)+numArr.get(k);
                if(tmpSum<0){
                    j++;

                }else if(tmpSum>0){
                    k--;
                }else{
                    ArrayList<Integer> tmpArray = new ArrayList<Integer>();

                    tmpArray.add(numArr.get(i));
                    tmpArray.add(numArr.get(j));
                    tmpArray.add(numArr.get(k));
                    result.add(tmpArray);


                    j++;
                    k--;
                }
            }
        }
        HashSet<ArrayList<Integer>> tmpset = new HashSet<ArrayList<Integer>>(result);
        result = new ArrayList<ArrayList<Integer>>(tmpset);

        return result;
    }

}