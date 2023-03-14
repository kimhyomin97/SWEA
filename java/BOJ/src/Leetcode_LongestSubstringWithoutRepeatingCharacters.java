// https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
    int ans = 0;
    public void recur(HashMap<Character, Boolean> map, String s, int left, int right){
        if(ans < right - left) ans = right-left;
        if(left == s.length() || right == s.length()) return;
        if(map.containsKey(s.charAt(right))){
            map.remove(s.charAt(left));
            recur(map, s, left+1, right);
        }
        else{
            map.put(s.charAt(right), true);
            recur(map, s, left, right+1);
        }
    }
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Boolean> map = new HashMap<>();
        recur(map, s, 0, 0);
        return ans;
    }
}