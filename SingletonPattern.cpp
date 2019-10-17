
#include <iostream>

using namespace std;

class SingleObject {
    private:
        SingleObject(){};

    public:
        static SingleObject* getInstance(){
            return (!my_singleton) ? 
                my_singleton = new SingleObject :
                my_singleton;
        };

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