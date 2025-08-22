class Solution {
    fun solution(elements: IntArray): Int {
        var ansSet = mutableSetOf<Int>()
        var dp = elements.toMutableList()

        ansSet.addAll(dp)

        for(i in 1 until elements.size) {
            for(j in dp.indices) {
                val tmp = i + j
                
                if(tmp < elements.size)
                    dp[j] = dp[j] + elements[tmp]
                else
                    dp[j] = dp[j] + elements[tmp - elements.size]
                
            }
            
            ansSet.addAll(dp)
        }

        return ansSet.size
    }
}