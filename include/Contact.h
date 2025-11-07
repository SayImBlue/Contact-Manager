#pragma once
#include <string>
#include <vector>

class Contact {
private:
    std::string name;
    std::string phone;
    std::string email;
    int creationIndex;

public:
    Contact(std::string n, std::string p, std::string m, int c);

    // Getters
    const std::string& getName() const;
    const std::string& getPhone() const;
    const std::string& getMail() const;
    int getIndex() const;

    // Setters
    void setName(std::string n);
    void setPhone(std::string p);
    void setMail(std::string m);
    void setIndex(int c);

    // Helpers
    void display() const;

    // Operators
    bool operator<(const Contact &other) const;
};

// ---- Global function declarations ----
bool loadContacts(std::vector<Contact>& contacts, int& id);
bool saveContact(const std::vector<Contact>& contacts);
void addContact(std::vector<Contact>& contacts, int& id);
void delContact(std::vector<Contact>& contacts);
void updContact(std::vector<Contact>& contacts);
void sortContacts(std::vector<Contact>& contacts);
void searchContact(const std::vector<Contact>& contacts);
