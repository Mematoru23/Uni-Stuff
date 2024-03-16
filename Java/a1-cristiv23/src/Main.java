import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int min = findMin(args);

        if (min == Integer.MAX_VALUE) {
            System.out.println("no valid integers");
        } else {
            System.out.println("min value: " + min);
        }
    }

    private static int findMin(String[] args) {
        if (args.length > 0) {
            return findMinFromArray(args);
        } else {
            return findMinFromUserInput();
        }
    }

    private static int findMinFromArray(String[] args) {
        int min = Integer.MAX_VALUE;
        for (String arg : args) {
            try {
                int num = Integer.parseInt(arg);
                min = Math.min(min, num);
            } catch (NumberFormatException e) {}
        }
        return min;
    }

    private static int findMinFromUserInput() {
        Scanner scanner = new Scanner(System.in);
        int min = Integer.MAX_VALUE;

        while (true) {
            System.out.print("enter integers: ");
            String input = scanner.nextLine();
            String[] inputArgs = input.split("\\s+");

            boolean validInput = false;
            for (String arg : inputArgs) {
                try {
                    int num = Integer.parseInt(arg);
                    min = Math.min(min, num);
                    validInput = true;
                } catch (NumberFormatException e) {

                }
            }

            if (validInput) {
                break;
            } else {
                System.out.println("invalid input. ENTER INTEGERS");
            }
        }

        scanner.close();
        return min;
    }
}