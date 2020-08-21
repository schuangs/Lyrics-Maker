/* 
 * This file contains functions for making time tags
 *
 */

# include <iostream>
# include <vector>
# include <string>
# include <chrono>
# include <fstream>
# include <sstream>

# include "../include/time.hpp"

using namespace std;

/*
 * function:    fillzero()
 * 
 * Purpose
 * =======
 * 
 * fillzero adds '0's ahead of the input integer n if n < 10.
 * 
 * Arguments
 * =========
 * 
 * n        (input)             unsigned
 *      input integer which represents second/minute count
 * 
 * width    (input)             unsigned
 *      width of the returned string, which should be no s-
 *      maller than width of n
 * 
 * Return
 * ======
 * 
 *                              std::string
 * string which contains the format filled with '0' is nec-
 * essary
 * 
 * --------------------------------------------------------
 */
string fillzero(unsigned n, unsigned width)
{
    /*
     * convert unsigned n into string
     */
    string s = unsigned2string(n);

    /*
     * fill zeros ahead of the string
     */
    while (s.size() < width) 
    {
        s = string("0") + s;
    }

    return s;
}

/*
 * function:    time_format()
 * 
 * Purpose
 * =======
 * 
 * return a string of time tag format
 * 
 * Arguments
 * =========
 * 
 * n        (input)             unsigned
 *      total number of milliseconds elapsed
 * 
 * Return
 * ======
 * 
 *                              std::string
 * string in standard time tag format
 * 
 * --------------------------------------------------------
 */
string time_format(unsigned n)
{
    /* add offset */
    n += OFFSET;
    /*
     * calculate the counting integers
     */
    unsigned milli = n % 1000;
    unsigned rest = n / 1000;
    unsigned second = rest % 60;
    unsigned minute = rest / 60;

    /*
     * form the format
     */
    string format = string("[") +  fillzero(minute, NUM_MINUTE) 
            + ":" + fillzero(second, NUM_SEC) + ".";

    /*
     * millisecond need be coped with specifically
     */
    if (NUM_MILLI == 2) 
    {
        milli /= 10;
    } 
    
    return format + fillzero(milli, NUM_MILLI) + "]";
}

/* 
 * function:    toMillisecond()
 * 
 * Purpose
 * =======
 * 
 * Convert from time shaft format to number of milliseconds
 * 
 * Arguments
 * =========
 * 
 * s    (input)                 const string &
 *      string in time tag format, eg: "[03:21.90]"
 * 
 * Return
 * ======
 * 
 * total number of milliseconds is returned
 * 
 * --------------------------------------------------------
 */
unsigned toMillisecond(std::string s) {
    string new_s = s.substr(0, s.size()-1);

    /* convert minute string into integer of milliseconds*/
    string m = new_s.substr(1,NUM_MINUTE);
    int n = string2unsigned(m), tot = 0;
    tot += n*60*1000;

    /* convert second string into integer of milliseconds */
    m = new_s.substr(NUM_MINUTE + 2, NUM_SEC);
    n = string2unsigned(m);
    tot += n*1000;

    /* convert millisecond string into integer of milliseconds */
    m = new_s.substr(NUM_MINUTE + NUM_SEC + 3);
    n = string2unsigned(m);
    tot += n;

    return tot;
}


/*
 * Convert unsigned int to std::string using sstream
 */
std::string unsigned2string(unsigned n) 
{
    string s;
    stringstream ss;
    ss << n;
    ss >> s;
    return s;
}

/*
 * Convert std::string to unsigned int using sstream
 */
unsigned string2unsigned(std::string s)
{
    unsigned n = 0;
    stringstream ss;
    ss << s;
    ss >> n;
    return n;
}