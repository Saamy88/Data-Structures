#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    cout << "Have " << argc << " arguments: " << endl;
    
    for(int i = 0; i < argc; ++i)
    {
       cout << argv[i] << endl;
    }
    
    system("PAUSE");
    return 0;
    
}
