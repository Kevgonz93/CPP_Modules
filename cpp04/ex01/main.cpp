#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

int main ()
{
    std::cout << "\n=== Array of Animals (polymorphic destruction) ===" << std::endl;
    const Animal* animals[10];
    for(int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            std::cout << "Creating Dog at index " << i << std::endl;
            animals[i] = new Dog();
        }
        else
        {
            std::cout << "Creating Cat at index " << i << std::endl;
            animals[i] = new Cat();
        }
    }
    std::cout << "\n=== Sounds in array ===" <<  std::endl;
    for(int i = 0; i < 10; i++)
    {
        std::cout << "Animal at index " << i << " makes sound: ";
        animals[i]->makeSound();
    }
   
    std::cout << "\n=== Deleting array ===" <<  std::endl;
    for(int i = 0; i < 10; i++)
        delete animals[i];
    return 0;
}
