#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Test fill persistence
    cout << right << setfill('_') << setw(3) << 47;
    cout << " : ";
    cout << left << setw(3) << "F";
    cout << endl;
    
    // Test with explicit setfill(' ')
    cout << right << setfill('_') << setw(3) << 47;
    cout << " : ";
    cout << left << setfill(' ') << setw(3) << "F";
    cout << endl;
    
    return 0;
}
