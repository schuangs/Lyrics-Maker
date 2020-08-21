// This is a program for displaying .lrc file with rolling lyrics at console

# include <iostream>
# include <string>
# include <fstream>
# include <chrono>
# include <vector>
# include <sstream>

# include "../../include/time.hpp"

using namespace std;



int main(int argc, char **argv) {

    /* local variables */
    string file_name, line;
    vector<unsigned> times;
    vector<string> lyrics;
    unsigned index = 0, offset = 0;

    /* offset may be passed through main */
    if (argc >= 3)
    {
        offset = string2unsigned(std::string(argv[2]));
    }
    else if (argc < 2) 
    {
        cerr << "No file input" << endl;
        return -1;
    } else
    {
        /* file name is passed through console as main argument as well */
        file_name = argv[1];
    }
    
    getline(cin, line);
    ifstream file(file_name);

    /* Convert from .lrc format to lyrics and its time */
    cout << "Format converting..." << endl;
    while (getline(file, line)) {
        if (isdigit(line[1])) {
            unsigned divide = line.find(']', 0);
            times.push_back(toMillisecond(line.substr(0, divide+1)));
            lyrics.push_back(line.substr(divide+1));
        }
    }
    file.close();

    /* Ready to play */
    cout << "Press enter to start play:" << flush;
    getline(cin, line);
    time_point_t start = chrono::time_point_cast<time_unit>(my_clock::now());
    while (index < times.size()) {
        time_point_t now = chrono::time_point_cast<time_unit>(my_clock::now());
        if ((now-start).count() >= times[index] + offset)
            cout << lyrics[index++] << endl;
    }
    return 0;
}