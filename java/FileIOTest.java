import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Stack;
import java.io.FileWriter;

public class FileIOTest {
    public void main(String[] args) throws IOException {
        String fileIn = "test.in";
        String fileOut = "test.out";
        BufferedReader in = new BufferedReader(new FileReader(fileIn));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(fileOut)));

        Stack<String> stk = new Stack<>();

        String line;
        while ((line = in.readLine()) != null) {
            stk.push(line);
        }

        while(!stk.isEmpty()) {
            String top = stk.pop();
            out.println(top);
        }

        in.close();
        out.close();
    }
}
