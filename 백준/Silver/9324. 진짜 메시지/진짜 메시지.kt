fun main() {
    val n = readln().toInt()
    
    repeat(n) {
        val str = readln()

        val check = IntArray(26)
        val ans = StringBuilder()
        var i = 0
        while (i < str.length) {
            ans.append(str[i])
            check[str[i] - 'A']++

            if (check[str[i] - 'A'] == 3) {
                ans.append(str[i])
                check[str[i] - 'A'] = 0

                i++
            }
            i++
        }

        println(if (ans.toString() == str) "OK" else "FAKE")
    }

}