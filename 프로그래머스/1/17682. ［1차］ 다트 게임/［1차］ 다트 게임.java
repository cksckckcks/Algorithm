import java.lang.Math;

class Solution {
    public int solution(String dartResult) {
        int answer = 0;
        int[] score = new int[3];
        int scoreIndex = -1;
        
        for (int i = 0; i < dartResult.length(); i++) {
            char c = dartResult.charAt(i);
            if (c == '1' && dartResult.charAt(i + 1) == '0') {
                score[++scoreIndex] = 10;
                i++;
            }
            else if (c >= '0' && c <= '9')
                score[++scoreIndex] = c - '0';
            else if (c == 'D')
                score[scoreIndex] = score[scoreIndex] * score[scoreIndex];
            else if (c == 'T')
                score[scoreIndex] = score[scoreIndex] * score[scoreIndex] * score[scoreIndex];
            else if (c == '#')
                score[scoreIndex] *= -1;
            else if (c == '*' && scoreIndex == 0)
                score[scoreIndex] *= 2;
            else if (c == '*') {
                score[scoreIndex - 1] *= 2;
                score[scoreIndex] *= 2;
            }    
        }
        
        answer = score[0] + score[1] + score[2];
        
        return answer;
    }
}