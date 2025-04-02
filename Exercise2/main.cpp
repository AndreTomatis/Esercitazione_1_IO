#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;



long double map(long double x){
    return -1.0 + ((x - 1.0) * 3.0) / 4.0;
}



int readFile(const string& filename){
    ifstream ifs(filename);
    ofstream ofs("./result.txt");
    
    if (ifs.fail() || !ofs.is_open()) {
        cerr << "Can't open " << filename << std::endl;
        return 1;
    }
    

    int N = 0;
    
    long double value = 0,
           sum = 0,
           mean = 0;

    ofs << "# N Mean" << endl;

    while (ifs >> value) {
        value = map(value);
        sum += value;
        N++;    
        mean = sum / (long double)N;
        ofs << N << " " << scientific << mean << endl;
    }

    ifs.close();
    ofs.close();

    
    return 0;
}


int main()
{
    string fn = "./data.txt";

    if (readFile(fn)==0){
        cout << "operation completed successfully" << endl;
    }else{
        cout << "An error occurred" << endl;
    }

    return 0;
}
