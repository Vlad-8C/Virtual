#include <iostream>
#include <string>

// Базовый класс
class Parents 
{
public:
    std::string name;
public:
    Parents(std::string name_) : name(name_) {}

    virtual void printInfo() const {
        std::cout << "Parent: " << name << std::endl;
    }
    virtual ~Parents() = default;
};

// Производный класс 1
class ChildMan : public Parents {
public:
    int age;
public:
    ChildMan(std::string name_, int age_) : Parents(name_), age(age_) {};

    void printInfo() const override {
        std::cout << "ChildMan: " << name << ", age: " << age << std::endl;
    }
};

// Производный класс 2
class ChildWomen : public Parents {
public:
    bool hasChildren;

public:
    ChildWomen(std::string name_, bool hasChildren_) : Parents(name_), hasChildren(hasChildren_) {}
    
    void printInfo() const override {
        std::cout << "ChildWomen: " << name << ", has children: "
            << (hasChildren ? "yes" : "no") << std::endl;
    }
};

int main() {
    // Создаём массив указателей на базовый класс
    const int arraySize = 3;
    Parents* family[arraySize];

    // Заполняем массив объектами разных производных классов
    family[0] = new ChildMan{ "John", 25 };
    family[1] = new ChildWomen{ "Alice", true };
    family[2] = new ChildMan{ "Bob", 30 };

    // Используем полиморфизм — вызываем виртуальные методы
    for (int i = 0; i < arraySize; ++i) {
        family[i]->printInfo();
    }

    // Освобождаем память
    for (int i = 0; i < arraySize; ++i) {
        delete family[i];
    }

    return 0;
}