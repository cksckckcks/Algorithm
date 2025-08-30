import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
 
 
 
val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

fun main() {
    val N = br.readLine().toInt()

    var set = HashSet<Int>()

    repeat(N) {
        val input = br.readLine().split(" ")
        var n = 0

        
        if (input[0] != "all" && input[0] != "empty")
            n = input[1].toInt()

        when (input[0]) {
            "add" -> {
                set.add(n)
            }
            "check" -> {
                if (set.contains(n))
                    bw.write("1\n")
                else
                    bw.write("0\n")
                
            }
            "remove" -> {
                if (set.contains(n))
                    set.remove(n)
            }
            "toggle" -> {
                if (set.contains(n))
                    set.remove(n)
                else
                    set.add(n)
            }
            "all" -> {
                for (i in 1..20)
                    if (!set.contains(i))
                        set.add(i)
            }
            "empty" -> {
                set.clear()
            }
        }
    }

    bw.flush()
    bw.close()
}