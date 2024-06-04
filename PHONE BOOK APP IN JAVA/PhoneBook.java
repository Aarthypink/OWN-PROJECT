import java.util.ArrayList;
import java.util.List;

public class PhoneBook {
    private List<Contact> contacts;

    public PhoneBook() {
        contacts = new ArrayList<>();
    }

    public void addContact(String name, String phoneNumber) {
        contacts.add(new Contact(name, phoneNumber));
    }

    public Contact searchContact(String name) {
        for (Contact contact : contacts) {
            if (contact.getName().equalsIgnoreCase(name)) {
                return contact;
            }
        }
        return null;
    }

    public List<Contact> listContacts() {
        return contacts;
    }

    public boolean deleteContact(String name) {
        Contact contact = searchContact(name);
        if (contact != null) {
            contacts.remove(contact);
            return true;
        }
        return false;
    }

    public boolean editContact(String oldName, String newName, String newPhoneNumber) {
        Contact contact = searchContact(oldName);
        if (contact != null) {
            contacts.remove(contact);
            contacts.add(new Contact(newName, newPhoneNumber));
            return true;
        }
        return false;
    }
}