// This is a program for making .lrc lyrics file

# include <iostream>
# include <vector>
# include <string>
# include <chrono>
# include <fstream>
# include <sstream>

using namespace std;

using my_clock = std::chrono::steady_clock;
using time_unit = std::chrono::milliseconds;

// fill zero at the front of digits
string fillzero(unsigned n) {
    stringstream ss;
    string s;
    ss << n;
    ss >> s;
    return (n >= 10) ? s : string("0")+s;
}

// return the time shaft format
string time_format(unsigned n) {
    unsigned milli = n % 1000;
    unsigned rest = n / 1000;
    unsigned second = rest % 60;
    unsigned minute = rest / 60;
    return string("[") +  fillzero(minute) + ":" + fillzero(second) + "." + fillzero(milli/10) + "]";
}

int main() {
    using time_point_t = std::chrono::time_point<my_clock, time_unit>;
    cout << "Enter the file path:" << endl;
    string file_name, line, waste;
    time_point_t start_time, this_time;
    bool start = false;
    getline(cin, file_name);
    ifstream file(file_name, ios::in);
    ofstream out("new.lrc");
    while (getline(file, line)) {
        if (line[0] != '['){
            if (!start) {
                cout << "Press enter to start record:" << flush;
                getline(cin, waste);
                start_time = std::chrono::time_point_cast<time_unit>(my_clock::now());
                cout << "In the next, press enter to signal the start of each line of lyrics" << endl;
                start = true;
            } 
            cout << line << flush;
            getline(cin, waste);
            this_time = std::chrono::time_point_cast<time_unit>(my_clock::now());
            string time_point = time_format((this_time-start_time).count());
            out << time_point;
        }
        out << line << endl;
    }
    file.close();
    out.close();
    return 0;
}