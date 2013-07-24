/**
 */

package com.leetcode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;

public class Solution {
    class TwoSum{

        public int index1,index2,sum;
        public TwoSum(int index1, int index2, int sum){
            this.index1 = index1;
            this.index2 = index2;
            this.sum = sum;
        }
    }

    ArrayList<TwoSum> ts = new ArrayList<TwoSum>();

    public ArrayList<ArrayList<Integer>> fourSum(int[] num, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ts.clear();
        HashSet<ArrayList<Integer>> s = new HashSet<ArrayList<Integer>>();
        ArrayList<Integer> tmp = new ArrayList<Integer>();
        for(int i=0;i<num.length-1;i++){
            for(int j=i+1;j<num.length;j++){
                ts.add(new TwoSum(i,j,num[i]+num[j]));
            }
        }
        Collections.sort(ts,new Comparator<TwoSum>() {
            @Override
            public int compare(TwoSum twoSum, TwoSum twoSum1) {
                return twoSum.sum-twoSum1.sum;
            }
        });
        int i=0;
        int j=ts.size()-1;
        while(i<j){
            if(ts.get(i).sum+ts.get(j).sum<target){
                i++;
            }
            else if(ts.get(i).sum+ts.get(j).sum>target){
                j--;
            }else{
                tmp.clear();
                tmp.add(ts.get(i).index1);
                tmp.add(ts.get(i).index2);
                tmp.add(ts.get(j).index1);
                tmp.add(ts.get(j).index2);
                Collections.sort(tmp);
                if(tmp.get(0).equals(tmp.get(1))
                        || tmp.get(1).equals(tmp.get(2))
                        || tmp.get(2).equals(tmp.get(3)) )
                {

                }
                else{
                    ArrayList<Integer> tmparr = new ArrayList<Integer>();
                    tmparr.add(num[tmp.get(0)]);
                    tmparr.add(num[tmp.get(1)]);
                    tmparr.add(num[tmp.get(2)]);
                    tmparr.add(num[tmp.get(3)]);
                    Collections.sort(tmparr);
                    s.add(tmparr);
                }
                if(ts.get(i).sum == ts.get(i+1).sum && i+1<j){
                    i++;
                }
                else if(ts.get(j).sum == ts.get(j-1).sum && i+1<j){
                    j--;
                }else{
                    i++;
                    j--;
                }

            }
        }
        return new ArrayList<ArrayList<Integer>>(s);
    }

    public static void main(String args[]){
        int[] kkk = {};
        System.out.println(new Solution().fourSum(kkk, 0).size());
    }

}