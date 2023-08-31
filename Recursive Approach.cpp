//Question: How to generate all possible bit strings of a given length using a recursive approach without any constraints on the number of bit changes? 
//Given that the algorithm recursively considers all combinations of appending '0' and '1' to a growing prefix, it uses the Exhaustive Search method. 

#include <iostream>
#include <string>
using namespace std;

void generateBitStrings(int n, string prefix) {
    // Base case: if n is 0, we have generated a complete bit string
    if (n == 0) {
        cout << prefix << endl;
    } else {
        // Recursive case: generate bit strings of length n-1
        generateBitStrings(n-1, prefix + "0");
        generateBitStrings(n-1, prefix + "1");
    }
}

int main() {
    int n;
    cout << "Length of the bit strings to be generated: ";
    cin >> n;
    generateBitStrings(n, "");
    return 0;
}
