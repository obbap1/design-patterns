/**
 * I think the intention of the singleton pattern, is to ensure we cant create instances of a particular class explicitly,
 *  so we can just access the public methods.
*/

#include <iostream>

using namespace std;

//Singleton Class
class SingleObject {
    private:
        //Make the constructor private, so instances of the class will be forbidden.
        SingleObject(){};

    public:
        //return an instance of the class
        static SingleObject* getInstance(){
            return (!my_singleton) ? 
                my_singleton = new SingleObject :
                my_singleton;
        };
        //A public method
        void showMessage(){
            cout << "Hello World!" << endl;
        };

        static SingleObject *my_singleton;
        
};

SingleObject* SingleObject::my_singleton = nullptr;

int main(){
    SingleObject* sing;
    
    SingleObject* singleton = sing->getInstance();

    singleton->showMessage();

    return 0;
}