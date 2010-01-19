#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    ofstream fout("ran.txt");
    for (int n = 0; n < 1000; ++n)
        fout << rand()/(double)RAND_MAX << " " << rand()/(double)RAND_MAX << "\n";
    fout.close();
    return 0;
}

