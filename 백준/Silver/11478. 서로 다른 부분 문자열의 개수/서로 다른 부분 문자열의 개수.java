// 22012122 정찬
import java.io.*;
import java.util.HashSet;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        HashSet<String> s = new HashSet<>();
        String S;

        S = br.readLine();

        for (int i = 0; i < S.length(); i++) {
            for (int j = i + 1; j <= S.length(); j++) {
                String tmpS = S.substring(i, j);
                s.add(tmpS);
            }
        }

        bw.write(s.size() + "");
        bw.flush();
    }
}