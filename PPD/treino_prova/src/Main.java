public class Main {
    public static void main(String[] args) {
        int port = 2525;
        SMTPServer server = new SMTPServer(port);
        server.start();
    }
}
