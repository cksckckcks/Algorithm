import java.util.ArrayList;

class Solution { 
    public String solution(String number, int k) {
        String answer = "";
        int answerSize = number.length() - k;
        ArrayList<Character> al = new ArrayList<>(answerSize);
    
        for (int i = 0; i < number.length(); i++) {
            char c = number.charAt(i);
            
            while (!al.isEmpty() && k != 0 && al.get(al.size() - 1) < c) {
                al.remove(al.size() - 1);
                k--;
            }
            
            al.add(c);
        }
        
        while (k-- != 0)
            al.remove(al.size() - 1);
        
        for (int i = 0; i < al.size(); i++)
            answer += al.get(i);
        
        return answer;
    }
}