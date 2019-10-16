/**
 * 
 *  Abstract Factory Pattern, A creational pattern. Implements a factory of factories class. 
 *  From this factory, other factories are created.
 * 
 *  Original example implemented with Java on TutorialsPoint
 * 
 * **/

#include <iostream>

using namespace std;

//Shape Interface
class Shape {
    public:
        //A virtual function
        virtual void draw() = 0;
};

//Rounded Square
class RoundedSquare: public Shape {
    void draw(){
        cout << "Inside RoundedSquare::draw() method" << endl;
    }
};

//Rounded Rectangle
class RoundedRectangle: public Shape {
    void draw() {
        cout << "Inside RoundedRectangle::draw() method" << endl;
    }
};

//Rectangle
class Rectangle: public Shape {
    void draw() {
        cout << "Inside Rectangle::draw() method" << endl;
    }
};

//Square
class Square: public Shape {
    void draw() {
        cout << "Inside Square::draw() method" << endl;
    }
};

//AbstractFactory Interface

/*
** This Interface is the Factory of factories, and allows us create other factories.
*/
class AbstractFactory {
    public:
        //virtual function, implements an interface
        virtual Shape* getShape(string shapeType) = 0; 
};

//Shape Factory
class ShapeFactory: public AbstractFactory {
    public:
        Shape* getShape(string shapeType) {
            if(shapeType == "RECTANGLE"){
                return new Rectangle();
            } else if(shapeType == "SQUARE"){
                return new Square();
            } else return NULL;
        }
};

//Rounded shape factory
class RoundedShapeFactory: public AbstractFactory {
    public:
        Shape* getShape(string shapeType) {
            if(shapeType == "RECTANGLE") {
                return new RoundedRectangle();
            }else if(shapeType == "SQUARE"){
                return new RoundedSquare();
            } else return NULL;
        }
};

//Factory Producer
class FactoryProducer {
    public:
        static AbstractFactory* getFactory(bool rounded) {
            if(rounded) {
                return new RoundedShapeFactory();
            }else{
                return new ShapeFactory();
            }
        }
};

int main() {

    FactoryProducer factoryProducer;

    //rounded = false, Normal shapes
    AbstractFactory* shapeFactory = factoryProducer.getFactory(false);

    //shape1 is an instance of a normal rectangle
    Shape* shape1 = shapeFactory->getShape("RECTANGLE");

    shape1->draw();
    
    //shape2 is an instance of a square
    Shape* shape2 = shapeFactory->getShape("SQUARE");

    shape2->draw();

    //rounded = true, Rounded shapes
    AbstractFactory* ShapeFactory1 = factoryProducer.getFactory(true);

    //shape3 is an instance of a rounded rectangle
    Shape* shape3 = ShapeFactory1->getShape("RECTANGLE");

    shape3->draw();

    //shape4 is an instance of a rounded square
    Shape* shape4 = ShapeFactory1->getShape("SQUARE");

    shape4->draw();

    return 0;
}