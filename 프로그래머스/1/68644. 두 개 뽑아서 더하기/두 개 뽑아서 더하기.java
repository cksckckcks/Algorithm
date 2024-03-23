class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = {};
        int[] countArray = new int[201];

        int count = 0;
        for (int i = 0; i < numbers.length; i++) {
            for (int j = i + 1; j < numbers.length; j++) {
                if (countArray[numbers[i] + numbers[j]] == 0) {
                    countArray[numbers[i] + numbers[j]]++;
                    count++;
                }
            }
        }

        answer = new int[count];
        int idx = 0;
        for (int i= 0; i < 201; i++)
            if (countArray[i] > 0)
                answer[idx++] = i;

        return answer;
    }
}