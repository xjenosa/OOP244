#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Simulate displayTest line 46-48
    cout << right << setfill('_') << setw(3) << 3;  // MARK
    cout << " - ";
    cout << fixed << setprecision(1) << setw(3) << 0.1;  // GPA
    cout << " - ";
    cout << "F";  // GRADE without setw
    cout << endl;
    
    // Same but with setw for GRADE
    cout << right << setfill('_') << setw(3) << 3;  // MARK
    cout << " - ";
    cout << fixed << setprecision(1) << setw(3) << 0.1;  // GPA
    cout << " - ";
    cout << left << setw(3) << "F";  // GRADE with setw but no setfill reset
    cout << endl;
    
    // Same but with setfill reset for GRADE
    cout << right << setfill('_') << setw(3) << 3;  // MARK
    cout << " - ";
    cout << fixed << setprecision(1) << setw(3) << 0.1;  // GPA
    cout << " - ";
    cout << left << setfill(' ') << setw(3) << "F";  // GRADE with setw and setfill reset
    cout << endl;
    
    return 0;
}
