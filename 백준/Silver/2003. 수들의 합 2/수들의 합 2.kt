fun main() {
    val (n, m) = readln().split(" ").map { it.toInt() }
    val numbers = readln().split(" ").map { it.toInt() }


    var sum = numbers[0]
    var cnt = 0
    
    var left = 0
    var right = 1

    while (true) {
        if (sum < m) {
            if (right == n) 
                break
            sum += numbers[right++]
        } else if (sum == m) {
            sum -= numbers[left++]
            cnt++
        } else {
            sum -= numbers[left++]
        }
    }

    print(cnt)
}