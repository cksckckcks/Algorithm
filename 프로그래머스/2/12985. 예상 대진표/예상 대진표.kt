class Solution {
    fun solution(n: Int, a: Int, b: Int): Int {
        var answer = 0
        
        var aa = a
        var bb = b
        
        while (aa != bb) {
            answer++
            
            aa = (aa + 1) / 2
            bb = (bb + 1) / 2
        }
        
        return answer
    }
}