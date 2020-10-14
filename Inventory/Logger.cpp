#include "Logger.h"



void Logger::writeLogW(std::wstring msg)
{
	std::wstring Log;
	Log += msg;
	Log += __FILEW__;
	Log += L" Line : ";
	Log += static_cast<uint32_t>(__LINE__);
	OutputDebugStringW(Log.c_str());
}
void Logger::writeLog(std::string msg)
{
	std::string Log;
	Log += msg;
	Log += __FILE__;
	Log += " Line : ";
	Log += static_cast<uint32_t>(__LINE__);
	OutputDebugStringA(Log.c_str());
}
