/*
 * Adding time tags onto each line of lyrics in your lyrics file.
 * 
 */

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <regex>

# include "../../include/time.hpp"

using namespace std;
/*
 * main function for adding tags to lines of lyrics
 */ 
int main(int argc, char **argv) {

    /* local variables */
    string file_name, line, waste, song_name, author, album, you;
    time_point_t start_time, this_time;
    bool start = false;

    if (argc < 2)
    {
        cerr << "No file input" << endl;
        return -1;
    }
    /* file name/path is passed to main as the second argument */
    file_name = argv[1];

    
    /*
     * Get song's name via cin
     */
    cout << "Enter the song's name:" << endl;
    getline(cin, song_name);
    std::regex spaces("\\s+");
    std::regex_replace(song_name, spaces, "_");

    /*
     * Get other imformation via cin
     */
    cout << "Enter the song's author:" << endl;
    getline(cin, author);

    cout << "Enter the song's album:" << endl;
    getline(cin, album);

    cout << "Enter your signature:" << endl;
    getline(cin, you);


    /* open the file and create output file*/
    ifstream file(file_name, ios::in);
    ofstream out(song_name + ".lrc");

    /* add auxiliary informations to output file */
    out << "[ti:" << song_name << "]" << endl;
    out << "[ar:" << author << "]" << endl;
    out << "[al:" << album << "]" << endl;
    out << "[by:" << you << "]" << endl;

    /* read input file line by line */
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
    /* the end of main */
}
