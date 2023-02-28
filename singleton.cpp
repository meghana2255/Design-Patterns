/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/* 
Singleton classes:
	1.Singleton
Singleton functions:
	1. static function to get the instance
Singleton instance:
	1. static instance - single instance
Private constructor - so it cannot be called outside and other agents cannot instantiate it.
	
*/
#include <iostream>
using namespace std;

class Singleton {
    public:
    	static Singleton* getInstance();
    	~Singleton(){}
    	void setState(int x) { state = x;}
    	int getState() const{ return state; }
    
    private:
        Singleton(){};
        static Singleton _instance;
        int state;
};

Singleton*
Singleton::getInstance() { 
    static Singleton _instance;
	return &_instance;
}
    
class Exp {
    public:
        Exp() {
            singleStateObject = Singleton::getInstance();
            cout << "state of this object: " << singleStateObject->getState() << endl;
        }
        Singleton* singleStateObject;
};
int main()
{
    Singleton* sin = Singleton::getInstance();
    sin->setState(5);
    cout << "state:" << sin->getState() << endl;
    Exp x = Exp();
    return 0;
}
