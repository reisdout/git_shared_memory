#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
    cout << "Making the difference!" << endl;

    string str_model_file = "/proc/icc_vegas_driver";

    if (argc < 2)
    {
        cout << "Consumer or Prodicer?" << endl;
        return 0;
    }

    if(string(argv[1]) == string("consumer"))
    {
        
        cout << "consuming from kernel!" << endl;
        string line;
        ifstream myfile (str_model_file.c_str());
        if (myfile.is_open())
        {

            myfile >> line;
            int value = 'B' - line[0]; 
            cout << value << endl;
            myfile.close();
        }
      
        else cout << "Unable to open file"; 
      

    }

    else if (string(argv[1]) == string("producer"))
    {

        cout << "Producing to kernel!" << endl;
        ofstream myfile (str_model_file.c_str());
        if (myfile.is_open())
        {
          myfile << "C";
          myfile.close();
        }
        else cout << "Unable to open file";

    }
    
    else
    {
        cout << "Unusual type!" << endl;
    }

    return 0;
}