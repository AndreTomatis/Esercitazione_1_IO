#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to calculate S = N (N + 1)(2N + 1) / 6
int computeSumOfSquaresFormula(int N) {
    return (N * (N + 1) * (2 * N + 1)) / 6;
}

// Function to read integers from file and compute sum of squares
int computeSumOfSquaresFromFile(const string& filename, int& N) {
        
    ifstream ifs(filename);
    if (ifs.fail()) {
        cerr << "Can't open " << filename << std::endl;
        return 1;
    }
    

    int sumOfSquares = 0,
        number = 0;

    string line;
    getline(ifs, line);     

    while (ifs >> number) {
        sumOfSquares += number*number;
        N++;    
    }

    ifs.close();
    
    return sumOfSquares;
}

int main() {
    string filename = "data.txt";
    int N = 0;
    
    // Compute sum of squares from file
    int sumFromFile = computeSumOfSquaresFromFile(filename, N);
    if (sumFromFile == -1) {
        return 1;
    }
    
    // Compute sum of squares using formula
    int sumFromFormula = computeSumOfSquaresFormula(N);
    
    // Output the results
    cout << "Sum of squares from file: " << sumFromFile << endl;
    cout << "Sum of squares from formula: " << sumFromFormula << endl;
    
    // Compare results
    if (sumFromFile == sumFromFormula) {
        cout << "The results match!" << endl;
    } else {
        cout << "The results do not match." << endl;
    }
    
    return 0;
}
