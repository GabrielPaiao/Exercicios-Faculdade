import java.io.*;
import java.net.Socket;

public class SMTPClientHandler implements Runnable {
    private final Socket clientSocket;
    private final String serverName = "SimpleSMTPServer";

    public SMTPClientHandler(Socket clientSocket) {
        this.clientSocket = clientSocket;
    }

    @Override
    public void run() {
        try (BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
             BufferedWriter out = new BufferedWriter(new OutputStreamWriter(clientSocket.getOutputStream()))) {

            out.write("220 " + serverName + " Simple Mail Transfer Service Ready\r\n");
            out.flush();

            SMTPCommandProcessor processor = new SMTPCommandProcessor(serverName);
            String line;

            while ((line = in.readLine()) != null) {
                String response = processor.processCommand(line.trim());
                out.write(response + "\r\n");
                out.flush();

                if (response.startsWith("221")) {
                    break;
                }
            }
        } catch (IOException e) {
            System.err.println("Error handling client: " + e.getMessage());
        }
    }
}
