#include <iostream>
#include <cstring>

class Person {
private:
    char* fullName;
    int age;

public:
    // ����������� �� �������������
    Person() : fullName(nullptr), age(0) {}

    // ����������� � �����������
    Person(const char* name, int age) {
        this->age = age;
        fullName = new char[strlen(name) + 1];
        strcpy_s(fullName, strlen(name) + 1, name);
    }

    // ����������� ���������
    Person(const Person& other) {
        age = other.age;
        fullName = new char[strlen(other.fullName) + 1];
        strcpy_s(fullName, strlen(other.fullName) + 1, other.fullName);
    }

    // ����������
    ~Person() {
        delete[] fullName;
    }

    // ��������� ���������� ��� ������
    void display() const {
        std::cout << "Name: " << fullName << ", Age: " << age << std::endl;
    }

    // ������ ��� ����
    const char* getName() const {
        return fullName;
    }
};

class Apartment {
private:
    Person* residents;
    int residentCount;

public:
    // ����������� �� �������������
    Apartment() : residents(nullptr), residentCount(0) {}

    // ����������� � ������� ���������
    Apartment(int count) : residentCount(count) {
        residents = new Person[residentCount];
    }

    // ����������� ���������
    Apartment(const Apartment& other) {
        residentCount = other.residentCount;
        residents = new Person[residentCount];
        for (int i = 0; i < residentCount; i++) {
            residents[i] = other.residents[i];
        }
    }

    // ����������
    ~Apartment() {
        delete[] residents;
    }

    // ��������� ��������
    void addResident(const Person& person, int index) {
        if (index >= 0 && index < residentCount) {
            residents[index] = person;
        }
    }

    // ��������� ��������� ��������
    void displayResidents() const {
        for (int i = 0; i < residentCount; i++) {
            residents[i].display();
        }
    }

    int getResidentCount() const {
        return residentCount;
    }
};

class House {
private:
    Apartment* apartments;
    int apartmentCount;

public:
    // ����������� �� �������������
    House() : apartments(nullptr), apartmentCount(0) {}

    // ����������� � ������� �������
    House(int count) : apartmentCount(count) {
        apartments = new Apartment[apartmentCount];
    }

    // ����������� ���������
    House(const House& other) {
        apartmentCount = other.apartmentCount;
        apartments = new Apartment[apartmentCount];
        for (int i = 0; i < apartmentCount; i++) {
            apartments[i] = other.apartments[i];
        }
    }

    // ����������
    ~House() {
        delete[] apartments;
    }

    // ��������� ��������
    void addApartment(const Apartment& apartment, int index) {
        if (index >= 0 && index < apartmentCount) {
            apartments[index] = apartment;
        }
    }

    // ��������� ���������� ��� �� ��������
    void displayHouseInfo() const {
        for (int i = 0; i < apartmentCount; i++) {
            std::cout << "Apartment " << i + 1 << " has "
                << apartments[i].getResidentCount() << " residents:" << std::endl;
            apartments[i].displayResidents();
        }
    }
};

int main() {
    // ��������� �����
    Person person1("Ivan Ivanov", 30);
    Person person2("Petro Petrov", 25);
    Person person3("Olena Shevchenko", 40);

    // ��������� �������� ��� 2 ���������
    Apartment apartment1(2);
    apartment1.addResident(person1, 0);
    apartment1.addResident(person2, 1);

    // ��������� �������� ��� 1 ��������
    Apartment apartment2(1);
    apartment2.addResident(person3, 0);

    // ��������� ������� � 2 ����������
    House house(2);
    house.addApartment(apartment1, 0);
    house.addApartment(apartment2, 1);

    // �������� ���������� ��� �������
    house.displayHouseInfo()
        
        
        ;

    system("pause");
    return 0;
}
