class Solution {
    var answer = 0
    
    fun solution(numbers: IntArray, target: Int): Int {
        dfs(numbers, target)
        
        return answer
    }
    
    fun dfs(numbers: IntArray, target: Int, cnt: Int = 0) {
        if (cnt == numbers.size) {
            if (numbers.sum() == target)
                answer++
            return
        }
        
        dfs(numbers, target, cnt + 1)

        numbers[cnt] *= -1

        dfs(numbers, target, cnt + 1)
    }
}