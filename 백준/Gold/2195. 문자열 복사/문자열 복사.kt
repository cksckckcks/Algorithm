import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
 
 
 
val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))


fun main() {
    val s = br.readLine()
    val p = br.readLine()

    var ans = 0

    var i = 0 // for 문은 무조건 val임

    while(i < p.length) {
        var maxLen = 0

        for (j: Int in 0 .. s.length) {
            var cnt = 0

            while (i + cnt < p.length && j + cnt < s.length && p[i + cnt] == s[j + cnt])
                cnt++
            
            maxLen = if (maxLen < cnt) cnt else maxLen
        }

        i += maxLen
        ans++
    }

    bw.write("$ans")


    br.close()
    bw.flush()
    bw.close()
}