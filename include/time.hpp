# ifndef TIME_HPP
# define TIME_HPP

# include <string>
# include <chrono>

/*
 * Number of digit used in time tag format for each part
 */
const unsigned NUM_MILLI = 2;
const unsigned NUM_SEC  = 2;
const unsigned NUM_MINUTE = 2;

/* offset : which is added to the total milliseconds at each time point */
const unsigned OFFSET = 0;

/*
 * clock used and time unit of the it
 */
using my_clock = std::chrono::steady_clock;
using time_unit = std::chrono::milliseconds;
using time_point_t = std::chrono::time_point<my_clock, time_unit>;

/* 
* fillzero adds '0's ahead of the input integer n
*/
std::string fillzero(unsigned, unsigned);

/*
* return a string of time tag format
*/
std::string time_format(unsigned);

/*
 * Convert from time shaft format to number of milliseconds
 */
unsigned toMillisecond(std::string);

/*
 * Convert unsigned int to std::string using sstream
 */
std::string unsigned2string(unsigned);

/*
 * Convert std::string to unsigned int using sstream
 */
unsigned string2unsigned(std::string);

# endif