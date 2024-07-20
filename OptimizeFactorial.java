package CoolCodeGit;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

public class OptimizeFactorial{

    public static BigInteger factorial(long n) {

        BigInteger answer=BigInteger.ONE;
        boolean oddn=((n&1)==1);
        long tempn=n;
        if(oddn){
            tempn=n-1;
            }

        long nextSum = tempn;
        long nextMulti = tempn;
        while (nextSum >= 2){
            answer=answer.multiply(BigInteger.valueOf(nextMulti));
            nextSum -= 2;
            nextMulti += nextSum;
        //  long product=(tempn-i+1L)*i;

        }
        if(oddn){
            answer=answer.multiply(BigInteger.valueOf(n));
        }
        return answer;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number:");
        //BigInteger n = new BigInteger(sc.nextLine()).abs();
        //BigInteger negative_one = new BigInteger("-1");
        long n = sc.nextLong();
        long startTime = System.nanoTime();
        BigInteger result = factorial(n); 
        // Stop measuring execution time
        long endTime = System.nanoTime();
        long executionTime = (endTime - startTime) / 1000000;
 
        System.out.println("Calculating "+n+" factorial takes "
                           + executionTime + "ms");
        try {
            File answer = new File("answer.txt");
            if (answer.createNewFile()) {
                System.out.println("File created: " + answer.getName());
            } else {
                System.out.println("File already exists.");
            }
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
        try {
            FileWriter myWriter = new FileWriter("answer.txt");
            myWriter.write(result.toString());
            myWriter.close();
            System.out.println("Successfully wrote to the file.");
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

        sc.close();
    }

}
