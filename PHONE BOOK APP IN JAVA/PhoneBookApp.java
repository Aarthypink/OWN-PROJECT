import java.util.Scanner;

public class PhoneBookApp {
    private static PhoneBook phoneBook = new PhoneBook();
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        boolean exit = false;
        
        while (!exit) {
            System.out.println("Phone Book Menu:");
            System.out.println("1. Add Contact");
            System.out.println("2. Search Contact");
            System.out.println("3. List Contacts");
            System.out.println("4. Delete Contact");
            System.out.println("5. Edit Contact");
            System.out.println("6. Exit");
            System.out.print("Choose an option: ");
            
            int choice = scanner.nextInt();
            scanner.nextLine();  // consume newline

            switch (choice) {
                case 1:
                    addContact();
                    break;
                case 2:
                    searchContact();
                    break;
                case 3:
                    listContacts();
                    break;
                case 4:
                    deleteContact();
                    break;
                case 5:
                    editContact();
                    break;
                case 6:
                    exit = true;
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }

    private static void addContact() {
        System.out.print("Enter name: ");
        String name = scanner.nextLine();
        System.out.print("Enter phone number: ");
        String phoneNumber = scanner.nextLine();
        phoneBook.addContact(name, phoneNumber);
        System.out.println("Contact added successfully.");
    }

    private static void searchContact() {
        System.out.print("Enter name to search: ");
        String name = scanner.nextLine();
        Contact contact = phoneBook.searchContact(name);
        if (contact != null) {
            System.out.println("Contact found: " + contact);
        } else {
            System.out.println("Contact not found.");
        }
    }

    private static void listContacts() {
        System.out.println("Listing all contacts:");
        for (Contact contact : phoneBook.listContacts()) {
            System.out.println(contact);
        }
    }

    private static void deleteContact() {
        System.out.print("Enter name to delete: ");
        String name = scanner.nextLine();
        if (phoneBook.deleteContact(name)) {
            System.out.println("Contact deleted successfully.");
        } else {
            System.out.println("Contact not found.");
        }
    }

    private static void editContact() {
        System.out.print("Enter the current name of the contact: ");
        String oldName = scanner.nextLine();
        System.out.print("Enter the new name: ");
        String newName = scanner.nextLine();
        System.out.print("Enter the new phone number: ");
        String newPhoneNumber = scanner.nextLine();
        if (phoneBook.editContact(oldName, newName, newPhoneNumber)) {
            System.out.println("Contact updated successfully.");
        } else {
            System.out.println("Contact not found.");
        }
    }
}