import java.util.regex.Pattern;

public class SMTPValidator {
    private static final Pattern emailPattern = Pattern.compile("^[^@\\s]+@[^@\\s]+\\.[^@\\s]+$");

    public static boolean isValidEmail(String email) {
        return email != null && emailPattern.matcher(email).matches();
    }
}
