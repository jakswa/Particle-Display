#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sys/time.h>

using namespace std;

int main()
{
    clock_t c1 = clock();
    vector<double> coords;
    double coord;
    //coords.reserve(sizeof(coord) * 2000000);
    
    ifstream fin("ran.txt");
    if (fin.is_open()) {
        while(fin >> coord) {
            coords.push_back(coord);
        }
    } else {
        cout << "error opening file";
    }
    cout << "done. " << coords.size()/2 << " coords read.\n";
    cout << "took " << (clock() - c1)/(double)CLOCKS_PER_SEC << " seconds." << endl;
    return 0;
}

