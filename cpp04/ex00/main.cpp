#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "\n=== Constructors ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "\n=== Types ===" << std::endl;
    std::cout << "dog type: " << dog->getType() << std::endl;
    std::cout << "cat type: " << cat->getType() << std::endl;
    std::cout << "animal type: " << meta->getType() << std::endl;

    std::cout << "\n=== Sounds (polymorphism test) ===" << std::endl;
    dog->makeSound(); // Dog sound
    cat->makeSound(); // Cat sound
    meta->makeSound(); // Generic Animal sound

    std::cout << "\n=== Copy constructors and assignment ===" << std::endl;
    Dog dog1;
    Dog dog2(dog1); // Copy constructor
    Dog dog3;
    dog3 = dog1; // Assignment operator

    Cat cat1;
    Cat cat2(cat1);
    Cat cat3;
    cat3 = cat1;

    std::cout << "\n=== Destructors ===" << std::endl;
    delete meta;
    delete dog;
    delete cat;

    std::cout << "\n=== Array of Animals (polymorphic destruction) ===" << std::endl;
    const Animal* animals[4];
    for (int i = 0; i < 4; ++i) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n=== Sounds in array ===" << std::endl;
    for (int i = 0; i < 4; ++i) {
        animals[i]->makeSound();
    }

    std::cout << "\n=== Deleting array ===" << std::endl;
    for (int i = 0; i < 4; ++i) {
        delete animals[i];
    }

    std::cout << "\n=== End of program ===" << std::endl;
    return 0;
}
