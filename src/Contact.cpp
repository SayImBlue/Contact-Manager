#include "Contact.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cctype>
#include <numeric>

using namespace std;

Contact::Contact(string n, string p, string m, int c)
    : name(move(n)), phone(move(p)), email(move(m)), creationIndex(c) {}

bool Contact::operator<(const Contact &other) const {
    return this->name < other.name;
}

const string& Contact::getName() const { return name; }
const string& Contact::getPhone() const { return phone; }
const string& Contact::getMail() const { return email; }
int Contact::getIndex() const { return creationIndex; }

void Contact::setName(string n) { name = move(n); cout << "Changed name successfully\n"; }
void Contact::setPhone(string p) { phone = move(p); cout << "Changed phone successfully\n"; }
void Contact::setMail(string m) { email = move(m); cout << "Changed email successfully\n"; }
void Contact::setIndex(int c) { creationIndex = c; cout << "Changed creation index successfully\n"; }

void Contact::display() const {
    cout << "- Contact -\n"
         << " * Name : " << name
         << "\n * Phone : " << phone
         << "\n * Email : " << email
         << "\n * Index : " << creationIndex << "\n";
}

bool loadContacts(vector<Contact> &contacts, int &id) {
    fstream file("data/contacts.txt", ios::in);
    if (!file.is_open()) {
        cerr << "Error: could not open contacts.txt\n";
        return false;
    }

    string line;
    vector<string> infos;
    while (getline(file, line)) {
        infos.push_back(line);
        if (infos.size() == 4) {
            int index = stoi(infos[0]);
            contacts.emplace_back(infos[1], infos[2], infos[3], index);
            infos.clear();
        }
    }
    file.close();

    id = 0;
    for (const auto &c : contacts)
        id = max(id, c.getIndex());

    return true;
}

bool saveContact(const vector<Contact> &contacts) {
    fstream file("data/contacts.txt", ios::out | ios::trunc);
    if (!file.is_open()) {
        cerr << "Error while opening file for saving!\n";
        return false;
    }

    for (const auto &c : contacts) {
        file << c.getIndex() << "\n";
        file << c.getName() << "\n";
        file << c.getPhone() << "\n";
        file << c.getMail() << "\n";
    }

    file.close();
    return true;
}

void addContact(vector<Contact> &contacts, int &id) {
    string n, p, m;
    cout << "- New Contact -\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (true) {
        cout << "* Name: ";
        getline(cin, n);
        auto it = find_if(contacts.begin(), contacts.end(),
                          [&](const Contact &c) { return c.getName() == n; });
        if (it == contacts.end()) break;
        cout << "Name already exists. Try another.\n";
    }

    cout << "* Phone: ";
    cin >> p;
    cout << "* Email: ";
    cin >> m;

    contacts.emplace_back(n, p, m, ++id);
    cout << "Contact added successfully.\n";
}

void delContact(vector<Contact> &contacts) {
    string n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter the name of the contact to delete: ";
    getline(cin, n);

    auto it = remove_if(contacts.begin(), contacts.end(),
                        [&](const Contact &c) { return c.getName() == n; });

    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        cout << "Contact deleted successfully.\n";
    } else {
        cout << "Contact not found.\n";
    }
}

void updContact(vector<Contact> &contacts) {
    string n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter contact name to update: ";
    getline(cin, n);

    auto it = find_if(contacts.begin(), contacts.end(),
                      [&](const Contact &c) { return c.getName() == n; });

    if (it == contacts.end()) {
        cout << "Contact not found.\n";
        return;
    }

    while (true) {
        int choice;
        cout << "\nUpdate Menu:\n1. Name\n2. Phone\n3. Email\n4. Exit\nChoice: ";
        cin >> choice;

        string v;
        if (choice == 4) break;

        switch (choice) {
        case 1:
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "New name: ";
            getline(cin, v);
            it->setName(v);
            break;
        case 2:
            cout << "New phone: ";
            cin >> v;
            it->setPhone(v);
            break;
        case 3:
            cout << "New email: ";
            cin >> v;
            it->setMail(v);
            break;
        default:
            cout << "Invalid option.\n";
        }
    }
}

void sortContacts(vector<Contact> &contacts) {
    int c;
    cout << "Sort type:\n1. Alphabetically\n2. By Creation Order\nChoice: ";
    cin >> c;

    if (c == 1)
        sort(contacts.begin(), contacts.end());
    else
        sort(contacts.begin(), contacts.end(),
             [](const Contact &a, const Contact &b) {
                 return a.getIndex() < b.getIndex();
             });

    cout << "Contacts sorted successfully.\n";
}

void searchContact(const vector<Contact> &contacts) {
    string n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Search name: ";
    getline(cin, n);

    string query = n;
    transform(query.begin(), query.end(), query.begin(), ::tolower);

    cout << "Results:\n";
    for (const auto &c : contacts) {
        string lower = c.getName();
        transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
        if (lower.find(query) != string::npos) c.display();
    }
}
