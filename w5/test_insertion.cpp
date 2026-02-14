#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Simulate insertionHelperTest line 72
    cout << right << setfill('_') << setw(3) << 47;  // M (MARK)
    cout << ": ";
    cout << "F";  // G (GRADE) without setw
    cout << ", ";
    cout << fixed << setprecision(1) << setw(3) << 3.1;  // P (GPA)
    cout << endl;
    
    // Same with setw for GRADE
    cout << right << setfill('_') << setw(3) << 47;  // M (MARK)
    cout << ": ";
    cout << left << setfill(' ') << setw(3) << "F";  // G (GRADE) with setw
    cout << ", ";
    cout << fixed << setprecision(1) << setw(3) << 3.1;  // P (GPA)
    cout << endl;
    
    return 0;
}
