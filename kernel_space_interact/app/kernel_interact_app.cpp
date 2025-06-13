#include <string>
#include <iostream>
#include <fstream>
using namespace std;


int sqrt_aprox( int x)
 {
    int lower_limit = 1;
    int upper_limit = 1;
    //bool upper_limit_done = false;

    for(int i=1; i < x; i++)
    {
        if(i*i >= x)
        {
            upper_limit = i;
            break;
        }
        lower_limit = i;
    }

    cout << "lower_limit: " << lower_limit << endl;

    cout << "upper_limit: " << upper_limit << endl;

    if((x-lower_limit*lower_limit) < (upper_limit*upper_limit-x))
    {
        cout << "returning " << lower_limit << endl;
        return lower_limit;
    }
    cout << "returning " << upper_limit << endl;
    return upper_limit;

 
}



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
      
        else cout << "Unable to open file\n"; 
      

    }

    else if (string(argv[1]) == string("producer"))
    {

        cout << "Producing to kernel!" << endl;
        ofstream myfile (str_model_file.c_str());
        if (myfile.is_open())
        {
            if(string(argv[2]) == "1")
                myfile << "A";
            else
                myfile << "B";
            myfile.close();
        }
        else cout << "Unable to open file\n";

    }

    else if (string(argv[1]) == string("sqrt"))
    {

        int cwnd_sqrt = sqrt_aprox(stoi(string(argv[2])));
        int new_SegCwnd = cwnd_sqrt*sqrt_aprox(cwnd_sqrt);
        cout <<  new_SegCwnd << endl;

    }
    
    else
    {
        cout << "Unusual type!" << endl;
    }

    return 0;
}