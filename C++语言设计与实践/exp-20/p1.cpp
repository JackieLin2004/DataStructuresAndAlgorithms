#include <iostream>

using namespace std;

extern void p1dispG();
extern void p2dispG();
extern void p2dispg();
static int G = 0, g = 0;

int main() {
    p2dispG();
    p2dispg();
    p1dispG();

    cout << "in p G=" << G << endl;
    cout << "in p g=" << g <<endl;
    return 0;
}