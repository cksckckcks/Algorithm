class Solution {
    fun check(signals: Array<IntArray>, sec: Int): Boolean {
        for (arr in signals) {
            val tmp = sec % (arr[0] + arr[1] + arr[2])

            if (tmp !in arr[0] + 1 .. arr[0] + arr[1]) {
                return false
            }
        }
        
        return true
    }
    
    fun solution(signals: Array<IntArray>): Int {
        var answer: Int = -1
        
        for (i in 1 until 3200000) {
            if (check(signals, i)) {
                answer = i
                
                break
            }
        }
        
        return answer
    }
}