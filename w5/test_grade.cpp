#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Test 1: Direct output with setw
    cout << "Test 1: setw(3) for single char:" << endl;
    cout << "|" << left << setw(3) << setfill(' ') << "F" << "|" << endl;
    cout << "|" << left << setw(3) << setfill(' ') << "B+" << "|" << endl;
    
    // Test 2: At end of line
    cout << "Test 2: At end of line:" << endl;
    cout << "Value: " << left << setw(3) << setfill(' ') << "F" << endl;
    
    return 0;
}
