#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    string address;
public:
    Person() : name(""), address("") {}
    Person(const string& name, const string& address) : name(name), address(address) {}
    Person(const Person& other) : name(other.name), address(other.address) {}
    ~Person() {}

    string getName() const {
        return name;
    }

    string getAddress() const {
        return address;
    }
};

class Apartment {
private:
    Person* residents;
    int numResidents;
public:
    Apartment() : residents(nullptr), numResidents(0) {}
    Apartment(int numResidents) : numResidents(numResidents) {
        residents = new Person[numResidents];
    }
    Apartment(const Apartment& other) : numResidents(other.numResidents) {
        residents = new Person[numResidents];
        for (int i = 0; i < numResidents; i++) {
            residents[i] = other.residents[i];
        }
    }
    ~Apartment() {
        delete[] residents;
    }

    void addResident(const Person& person) {
        Person* newResidents = new Person[numResidents + 1];
        for (int i = 0; i < numResidents; i++) {
            newResidents[i] = residents[i];
        }
        newResidents[numResidents] = person;
        delete[] residents;
        residents = newResidents;
        numResidents++;
    }

    void removeResident(int index) {
        if (index < 0 || index >= numResidents) {
            cout << "Resident not found!" << endl;
            return;
        }
        Person* newResidents = new Person[numResidents - 1];
        for (int i = 0, j = 0; i < numResidents; i++) {
            if (i != index) {
                newResidents[j++] = residents[i];
            }
        }
        delete[] residents;
        residents = newResidents;
        numResidents--;
    }

    void setResident(int index, const Person& person) {
        if (index >= 0 && index < numResidents) {
            residents[index] = person;
        }
    }

    Person getResident(int index) const {
        if (index >= 0 && index < numResidents) {
            return residents[index];
        }
        return Person();
    }

    int getNumResidents() const {
        return numResidents;
    }
};

class House {
private:
    Apartment* apartments;
    int numApartments;
public:
    House() : apartments(nullptr), numApartments(0) {}
    House(int numApartments) : numApartments(numApartments) {
        apartments = new Apartment[numApartments];
    }
    House(const House& other) : numApartments(other.numApartments) {
        apartments = new Apartment[numApartments];
        for (int i = 0; i < numApartments; i++) {
            apartments[i] = other.apartments[i];
        }
    }
    ~House() {
        delete[] apartments;
    }

    void setApartment(int index, const Apartment& apartment) {
        if (index >= 0 && index < numApartments) {
            apartments[index] = apartment;
        }
    }

    Apartment getApartment(int index) const {
        if (index >= 0 && index < numApartments) {
            return apartments[index];
        }
        return Apartment();
    }

    int getNumApartments() const {
        return numApartments;
    }
};

void interactWithUser(House& house) {
    int choice;
    do {
        cout << "\n1. Add resident\n";
        cout << "2. Remove resident\n";
        cout << "3. Display all residents in the house\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int apartmentIndex;
            string name, address;
            cout << "Enter the apartment number: ";
            cin >> apartmentIndex;
            if (apartmentIndex < 0 || apartmentIndex >= house.getNumApartments()) {
                cout << "Invalid apartment number!\n";
                continue;
            }
            cout << "Enter resident's name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter resident's address: ";
            getline(cin, address);
            Person newResident(name, address);
            house.getApartment(apartmentIndex).addResident(newResident);
            cout << "Resident added!\n";
        }
        else if (choice == 2) {
            int apartmentIndex, residentIndex;
            cout << "Enter the apartment number: ";
            cin >> apartmentIndex;
            if (apartmentIndex < 0 || apartmentIndex >= house.getNumApartments()) {
                cout << "Invalid apartment number!\n";
                continue;
            }
            cout << "Enter the resident number to remove: ";
            cin >> residentIndex;
            house.getApartment(apartmentIndex).removeResident(residentIndex);
            cout << "Resident removed!\n";
        }
        else if (choice == 3) {
            for (int i = 0; i < house.getNumApartments(); i++) {
                Apartment apartment = house.getApartment(i);
                for (int j = 0; j < apartment.getNumResidents(); j++) {
                    cout << "Apartment " << i << ", Resident " << j << ": " << apartment.getResident(j).getName() << ", Address: " << apartment.getResident(j).getAddress() << endl;
                }
            }
        }
    } while (choice != 0);
}
int main() {
    Person person1("John Doe", "123 Main St");
    Person person2("Jane Smith", "456 Elm St");
    Person person3("Bob Johnson", "789 Oak St");

    Apartment apartment1(1);
    apartment1.setResident(0, person1);

    Apartment apartment2(2);
    apartment2.setResident(0, person2);
    apartment2.setResident(1, person3);

    House house(2);
    house.setApartment(0, apartment1);
    house.setApartment(1, apartment2);

    interactWithUser(house);

	system("pause");
    return 0;
}
