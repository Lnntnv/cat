#include<iostream>
#include<sstream>

using namespace std;

class Cat {

public:
    enum Type { 
        Bald,
        Hairy
    };
    string name;  
    string color; 

    Cat(string name, int age, string color, int weight, Type type) {  
        this->name = name;  
        this->age = age;
        this->color = color;
        this->weight = weight;
        this->type = type;
    }
    
    ~Cat() {  
    }
    
    void setWeight(int weight) {  
        if (weight > 0) {
            this->weight = weight;
        }
    }
    
    string toString() const {  
        stringstream ss;
        ss << "Name: " << this->name << "\nWeight: " << this->weight;
        return ss.str();
    }
    
    friend ostream &operator<<(ostream &output, const Cat &c ) {  
        output << c.toString();
        return output;            
    }
    
private:
    const static int modelVersion = 1;  
    int age; 
    int weight;  
 
    Type type;  
};

class FatCat : public Cat {  
    
public:
    FatCat(string name, int age, string color) : Cat(name, age, color, 1000000, Cat::Type::Bald) {  
    }
};

int main() {
    // создаем котов
    Cat *dacota = new Cat("Дакота", 1, "серая", 3724, Cat::Type::Bald);
    Cat *senya = new Cat("Сеня", 10, "белый", 1000, Cat::Type::Hairy);
    Cat *kirill = new FatCat("Кирилл", 2, "черный");
    
    // меняем кота
    senya->name = "Кирилл";
    senya->setWeight(10000000);
    
    // выводим кота
    cout << *kirill;
    return 0;
}
