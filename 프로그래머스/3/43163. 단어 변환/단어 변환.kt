import kotlin.collections.ArrayDeque

class Solution {
    fun solution(begin: String, target: String, words: Array<String>): Int {
        var answer = 0
        
        if (words.contains(target) == false) return 0
        
        val visited = Array(words.size) { false }
        
        val q = ArrayDeque<Pair<String, Int>>()
        q.add(Pair(begin, 0))
        
        while (q.isNotEmpty()) {
            val (s, cnt) = q.removeFirst()
            if (s == target) {
                return cnt
            }
            
            for (i in 0 until words.size) {
                if (!visited[i] && checkCount(s, words[i])) {
                    visited[i] = true
                    q.add(Pair(words[i], cnt + 1))
                }
            }
        }
        
        return answer
    }
    
    fun checkCount(a: String, b: String): Boolean {
        var diffrentCount = 0

        for (i in a.indices) {
            if (a[i] != b[i]) diffrentCount++
        }

        return diffrentCount == 1
    }
}