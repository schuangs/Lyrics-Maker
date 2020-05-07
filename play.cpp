// This is a program for displaying .lrc file with rolling lyrics at console

# include <iostream>
# include <string>
# include <fstream>
# include <chrono>
# include <vector>
# include <sstream>
# include <windows.h>

using namespace std;

using my_clock = std::chrono::steady_clock;
using time_unit = std::chrono::milliseconds;
using time_point_t = std::chrono::time_point<my_clock, time_unit>;

// Convert from time shaft format to number of milliseconds
unsigned toMillisecond(const string& s) {
    string new_s = s.substr(0, s.size()-1);
    string m = new_s.substr(1,2);
    int n = 0, tot = 0;
    stringstream ss;
    ss << m;
    ss >> n;
    tot += n*60*1000;
    m = new_s.substr(4, 2);
    ss.clear();
    ss << m;
    ss >> n;
    tot += n*1000;
    m = new_s.substr(7);
    ss.clear();
    ss << m;
    ss >> n;
    tot += n;
    return tot;
}

int main() {
    // Chinese language support
    SetConsoleOutputCP(65001);
    cout << "Enter the .lrc file (with time rolls):" << endl;
    string file_name, line;
    cin >> file_name;
    getline(cin, line);
    vector<unsigned> times;
    vector<string> lyrics;
    ifstream file(file_name);

    // Convert from .lrc format to lyrics and its time
    cout << "Format converting..." << endl;
    while (getline(file, line)) {
        if (isdigit(line[1])) {
            unsigned divide = line.find(']', 0);
            times.push_back(toMillisecond(line.substr(0, divide+1)));
            lyrics.push_back(line.substr(divide+1));
        }
    }
    file.close();

    // Ready to play
    cout << "Press enter to start play:" << flush;
    getline(cin, line);
    time_point_t start = chrono::time_point_cast<time_unit>(my_clock::now());
    unsigned index = 0;
    while (index < times.size()) {
        time_point_t now = chrono::time_point_cast<time_unit>(my_clock::now());
        if ((now-start).count() >= times[index])
            cout << lyrics[index++] << endl;
    }
    return 0;
}