public class Solution {
    public ArrayList<String> anagrams(String[] strs) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<String> ans = new ArrayList<String>();
        HashMap<String, ArrayList<String>> map = new HashMap<String, ArrayList<String>>();
        for(String e : strs ){
            char[] chare1 = e.toCharArray();
            Arrays.sort(chare1);
            String chare = new String(chare1);
            if(map.keySet().contains(chare)){
                map.get(chare).add(e);
            }else{
                ArrayList<String> al = new ArrayList<String>();
                al.add(e);
                map.put(chare, al);
            }
        }
        for(String e : map.keySet()){
            if(map.get(e).size()>1){
                 ans.addAll(map.get(e));
            }
        }

        return ans;
    }

}