#include<iostream>
#include<sstream>

using namespace std;

class Cat {

public:
    enum Type {  // внутреннее перечисление типа кота
        Bald,
        Hairy
    };
    string name;  // свойство имя
    string color;  // свойство цвет

    Cat(string name, int age, string color, int weight, Type type) {  // конструктор, он нужен чтобы создавать новых котиков
        this->name = name;  // this нужен чтобы обратиться к текущему котику
        this->age = age;
        this->color = color;
        this->weight = weight;
        this->type = type;
    }
    
    ~Cat() {  // деструктор, нужен чтобы избавляться от котиков
    }
    
    void setWeight(int weight) {  // сеттер, метод устанавливающий вес кота
        if (weight > 0) {
            this->weight = weight;
        }
    }
    
    string toString() const {  // метод для преобразования котика в строку
        stringstream ss;
        ss << "Name: " << this->name << "\nWeight: " << this->weight;
        return ss.str();
    }
    
    friend ostream &operator<<(ostream &output, const Cat &c ) {  // перегружаем оператор вывода, чтобы выводить котика в консоль
        output << c.toString();
        return output;            
    }
    
private:
    const static int modelVersion = 1;  // версия модели, увеличиваем версию когда меняется структура класса кот
    int age;  // свойство возвраст
    int weight;  // свойство вес
    Type type;  // свойство тип
};

class FatCat : public Cat {  // наследуемся от класса Cat 
    
public:
    FatCat(string name, int age, string color) : Cat(name, age, color, 1000000, Cat::Type::Bald) {  // вызываем конструктор класса от которого наследуемся (супер-конструктор)
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