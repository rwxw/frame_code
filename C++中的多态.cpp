
/***********多态：相同的消息给予不同的对象可能会触发不同的行为************/

#include <iostream>

class Animal {
public:
    virtual void makeSound() {
        std::cout << "Animal makes a sound." << std::endl;
    } 
};

class Dog : public Animal {
public:
      void makeSound() override {
        std::cout << "Dog barks." << std::endl;
      }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Cat meows." << std::endl;
    }
};

int main()
{
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    animal1->makeSound();
    animal2->makeSound();

    return 0;
}