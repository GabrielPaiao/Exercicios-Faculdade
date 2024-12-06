public class SMTPCommandProcessor {
    private final String serverName;
    private String senderEmail = null;
    private String recipientEmail = null;
    private boolean readyForData = false;

    public SMTPCommandProcessor(String serverName) {
        this.serverName = serverName;
    }

    public String processCommand(String command) {
        if (command.startsWith("HELO")) {
            return "250 " + serverName + " Hello";
        } else if (command.startsWith("MAIL FROM:")) {
            senderEmail = extractEmail(command);
            if (SMTPValidator.isValidEmail(senderEmail)) {
                return "250 Sender <" + senderEmail + "> OK";
            } else {
                return "501 Syntax error in parameters or arguments";
            }
        } else if (command.startsWith("RCPT TO:")) {
            recipientEmail = extractEmail(command);
            if (SMTPValidator.isValidEmail(recipientEmail)) {
                return "250 Recipient <" + recipientEmail + "> OK";
            } else {
                return "501 Syntax error in parameters or arguments";
            }
        } else if (command.equals("DATA")) {
            readyForData = true;
            return "354 End data with <CR><LF>.<CR><LF>";
        } else if (readyForData) {
            if (command.equals(".")) {
                readyForData = false;
                return "250 Message accepted for delivery";
            }
            return ""; // Accepting data lines
        } else if (command.equals("QUIT")) {
            return "221 " + serverName + " Service closing transmission channel";
        } else {
            return "500 Syntax error, command unrecognized";
        }
    }

    private String extractEmail(String command) {
        int start = command.indexOf('<');
        int end = command.indexOf('>');
        if (start != -1 && end != -1 && start < end) {
            return command.substring(start + 1, end);
        }
        return null;
    }
}
