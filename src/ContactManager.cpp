#include "Contact.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<Contact> contacts;
    int id = 0;

    loadContacts(contacts, id);

    while (true) {
        cout << "\n===== Contact Manager =====\n";
        cout << "1. Add Contact\n2. Delete Contact\n3. Update Contact\n";
        cout << "4. Sort Contacts\n5. Search Contact\n6. Show All\n7. Save & Exit\n";
        cout << "Choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: addContact(contacts, id); break;
        case 2: delContact(contacts); break;
        case 3: updContact(contacts); break;
        case 4: sortContacts(contacts); break;
        case 5: searchContact(contacts); break;
        case 6:
            for (const auto &c : contacts) c.display();
            break;
        case 7:
            saveContact(contacts);
            cout << "Contacts saved. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
}
