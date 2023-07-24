#include <iostream>

class Animal {
public:
    virtual ~Animal() {}

    virtual void makeSound() const = 0;
};

class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Meow!" << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Woof!" << std::endl;
    }
};
class Veterinarian {
public:
    void treatAnimal(const Animal* animal) const {
        if (const Cat* cat = dynamic_cast<const Cat*>(animal)) {
            cat->makeSound();
        }
        else if (const Dog* dog = dynamic_cast<const Dog*>(animal)) {
            dog->makeSound();
        }
        else {
            std::cout << "Unknown animal!" << std::endl;
        }
    }
};
int main() {
    Animal* animal1 = new Cat();
    Animal* animal2 = new Dog();

    Veterinarian vet;
    vet.treatAnimal(animal1);
    vet.treatAnimal(animal2);

    delete animal1;
    delete animal2;

    return 0;
}
