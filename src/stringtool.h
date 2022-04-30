#include <string>

namespace tools{
	std::string AsciiStringWideToChar(const std::wstring& src);
	std::wstring AsciiStringCharToWide(const std::string& src);
    std::wstring Utf8ToWstring(const std::string& str);
	std::string WstringToUtf8(const std::wstring& str);

    template<typename T>
	void ReplaceStr(T &szContent,const T &szSrc,const T &szDst)
	{
		size_t pos = 0;
		while ((pos = szContent.find(szSrc, pos)) != T::npos) {
			szContent.replace(pos, szSrc.size(), szDst);
			pos++;
		}
	}
}
