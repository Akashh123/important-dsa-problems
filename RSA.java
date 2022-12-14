import java.math.BigInteger;
import java.util.Random;
import java.io.*;

public class RSA {
    private BigInteger p;
    private BigInteger q;
    private BigInteger N;
    private BigInteger phi;
    private BigInteger e;
    private BigInteger d;
    private int bitlength = 1024;
    private int blocksire = 256;

    // blocksize in byte
    private Random r;

    public RSA() {
        r = new Random();
        p = BigInteger.probablePrime(bitlength, r);
        q = BigInteger.probablePrime(bitlength, r);
        N = p.multiply(q);
        phi = p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));
        e = BigInteger.probablePrime(bitlength / 2, r);
        while (phi.gcd(e).compareTo(BigInteger.ONE) > 0 && e.compareTo(phi) < 0) {
            e.add(BigInteger.ONE);
        }
        d = e.modInverse(phi);
    }

    public RSA(BigInteger e, BigInteger d, BigInteger N) {
        this.e = e;
        this.d = d;
        this.N = N;
    }

    public static void main(String[] args) throws IOException {
        RSA rsa = new RSA();
        DataInputStream in = new DataInputStream(System.in);
        BufferedReader d = new BufferedReader(new InputStreamReader(in));
        String teststring;
        System.out.println("Enter the plain text:\n");

        teststring = d.readLine();

        System.out.println("Encrypting String:\n" + teststring + "\n");

        System.out.println("\nString in Bytes:\n\n" + bytesToString(teststring.getBytes()));
        byte[] encrypted = rsa.encrypt(teststring.getBytes());
        System.out.println("\nEncrypted String in Bytes:\n\n" + bytesToString(encrypted));
        byte[] decrypted = rsa.decrypt(encrypted);
        System.out.println("\nDecrypted String in Bytes:\n\n" + bytesToString(decrypted));
        System.out.println("\nDecrypted String\n\n" + new String(decrypted));
    }

    private static String bytesToString(byte[] encrypted) {
        String test = "";
        for (byte b : encrypted) {
            test += Byte.toString(b);
        }
        return test;
    }

    public byte[] encrypt(byte[] message) {
        return (new BigInteger(message)).modPow(e, N).toByteArray();
    }

    public byte[] decrypt(byte[] message) {
        return (new BigInteger(message)).modPow(d, N).toByteArray();
    }

}