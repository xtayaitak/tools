
#include <ctime>
#include <string>
namespace tools{
    bool GetTimeFromString(const std::string & s ,time_t & ret_time)
	{
		struct std::tm tm = { 0 };
		if (6 != sscanf(s.c_str(), "%d-%d-%d %d:%d:%d",
			&tm.tm_year, &tm.tm_mon, &tm.tm_mday,
			&tm.tm_hour, &tm.tm_min, &tm.tm_sec))
			return false;
		tm.tm_year -= 1900;
		tm.tm_mon -= 1;
		ret_time = mktime(&tm);
		if (-1 == ret_time)
			return false;
		else
			return true;
	}
}