class Solution { 
    int[] answer = {0, 0};
    private boolean check(int[][] arr, int x, int y, int length) {
        int n = arr[x][y];
        
        for (int i = x; i < x + length; i++)
            for (int j = y; j < y + length; j++)
                if (n != arr[i][j]) return false;

        return true;
    }
    
    private void dc(int[][] arr, int x, int y, int len) {
        if (check(arr, x, y, len) == true) {
            answer[arr[x][y]]++;
            return;
        }
        else {
            len /= 2;
            dc(arr, x, y, len);
            dc(arr, x, y + len, len);
            dc(arr, x + len, y, len);
            dc(arr, x + len, y + len, len);
        }
    }
    
    public int[] solution(int[][] arr) {
        int len = arr.length;
        
        dc(arr, 0, 0, len);
    
        return answer;
    }
}