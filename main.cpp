#include <iostream>
#include <cstring>

class Person {
private:
    char* fullName;
    int age;

public:
    // Конструктор за замовчуванням
    Person() : fullName(nullptr), age(0) {}

    // Конструктор з параметрами
    Person(const char* name, int age) {
        this->age = age;
        fullName = new char[strlen(name) + 1];
        strcpy_s(fullName, strlen(name) + 1, name);
    }

    // Конструктор копіювання
    Person(const Person& other) {
        age = other.age;
        fullName = new char[strlen(other.fullName) + 1];
        strcpy_s(fullName, strlen(other.fullName) + 1, other.fullName);
    }

    // Деструктор
    ~Person() {
        delete[] fullName;
    }

    // Виведення інформації про людину
    void display() const {
        std::cout << "Name: " << fullName << ", Age: " << age << std::endl;
    }

    // Геттер для імені
    const char* getName() const {
        return fullName;
    }
};

class Apartment {
private:
    Person* residents;
    int residentCount;

public:
    // Конструктор за замовчуванням
    Apartment() : residents(nullptr), residentCount(0) {}

    // Конструктор з кількістю мешканців
    Apartment(int count) : residentCount(count) {
        residents = new Person[residentCount];
    }

    // Конструктор копіювання
    Apartment(const Apartment& other) {
        residentCount = other.residentCount;
        residents = new Person[residentCount];
        for (int i = 0; i < residentCount; i++) {
            residents[i] = other.residents[i];
        }
    }

    // Деструктор
    ~Apartment() {
        delete[] residents;
    }

    // Додавання мешканця
    void addResident(const Person& person, int index) {
        if (index >= 0 && index < residentCount) {
            residents[index] = person;
        }
    }

    // Виведення мешканців квартири
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
    // Конструктор за замовчуванням
    House() : apartments(nullptr), apartmentCount(0) {}

    // Конструктор з кількістю квартир
    House(int count) : apartmentCount(count) {
        apartments = new Apartment[apartmentCount];
    }

    // Конструктор копіювання
    House(const House& other) {
        apartmentCount = other.apartmentCount;
        apartments = new Apartment[apartmentCount];
        for (int i = 0; i < apartmentCount; i++) {
            apartments[i] = other.apartments[i];
        }
    }

    // Деструктор
    ~House() {
        delete[] apartments;
    }

    // Додавання квартири
    void addApartment(const Apartment& apartment, int index) {
        if (index >= 0 && index < apartmentCount) {
            apartments[index] = apartment;
        }
    }

    // Виведення інформації про всі квартири
    void displayHouseInfo() const {
        for (int i = 0; i < apartmentCount; i++) {
            std::cout << "Apartment " << i + 1 << " has "
                << apartments[i].getResidentCount() << " residents:" << std::endl;
            apartments[i].displayResidents();
        }
    }
};

int main() {
    // Створюємо людей
    Person person1("Ivan Ivanov", 30);
    Person person2("Petro Petrov", 25);
    Person person3("Olena Shevchenko", 40);

    // Створюємо квартиру для 2 мешканців
    Apartment apartment1(2);
    apartment1.addResident(person1, 0);
    apartment1.addResident(person2, 1);

    // Створюємо квартиру для 1 мешканця
    Apartment apartment2(1);
    apartment2.addResident(person3, 0);

    // Створюємо будинок з 2 квартирами
    House house(2);
    house.addApartment(apartment1, 0);
    house.addApartment(apartment2, 1);

    // Виводимо інформацію про будинок
    house.displayHouseInfo()
        
        
        ;

    system("pause");
    return 0;
}
