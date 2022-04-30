#include "stringtool.h"
#include <locale>
#include <codecvt>
namespace tools{
	std::string AsciiStringWideToChar(const std::wstring& src)
	{
		return std::string(src.begin(), src.end());
	}
	std::wstring AsciiStringCharToWide(const std::string& src)
	{
		return std::wstring(src.begin(), src.end());
	}

    std::wstring Utf8ToWstring(const std::string& str)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
		return myconv.from_bytes(str);
	}
	std::string WstringToUtf8(const std::wstring& str)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
		return myconv.to_bytes(str);
	}
}
