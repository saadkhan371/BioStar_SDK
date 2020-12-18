#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <sstream>
#include "BS_API.h"


#define BITMAP_SIGNATURE			0x4D42
#define BITMAP_SIGNATURE_SIZE		14


typedef struct __BITMAPINFOHEADER
{
	unsigned long	biSize;
	long			biWidth;
	long			biHeight;
	unsigned short	biPlanes;
	unsigned short	biBitCount;
	unsigned long	biCompression;
	unsigned long	biSizeImage;
	long			biXPelsPerMeter;
	long			biYPelsPerMeter;
	unsigned long	biClrUsed;
	unsigned long	biClrImportant;
} BITMAPINFOHEADER_;

typedef struct __RGBQUAD
{
	unsigned char	rgbBlue;
	unsigned char	rgbGreen;
	unsigned char	rgbRed;
	unsigned char	rgbReserved;
} RGBQUAD_;

typedef struct __BITMAPINFO
{
	BITMAPINFOHEADER_   bmiHeader;
	RGBQUAD_            bmiColors[1];
} BITMAPINFO_;


template <typename T>
struct ArrayDeleter
{
	void operator() (T* ptr) { delete[] ptr; }
};


class Utility
{
public:
	template <typename T>
	static T getInput(std::string msg);
	static std::string getLine(std::string msg);

	static std::string getIPAddress(uint32_t ip);
	static std::string convertTimeUTC2String(uint32_t utcTime);
	static uint32_t convertTimeString2UTC(std::string time);
	static uint32_t getResourceSize(std::string file);
	static bool getResourceFromFile(std::string file, std::shared_ptr<uint8_t> buffer, uint32_t size = 0);
	static bool setResourceToFile(std::string file, std::shared_ptr<uint8_t> buffer, uint32_t size);

	static std::string replaceSlashToPeriod(const std::string& source);

	static std::vector<std::string> tokenizeString(const std::string& data, const char delimiter = ' ');
	template <typename T>
	static std::vector<T> tokenizeInteger(const std::string& data, const char delimiter = ' ');
	template <typename T>
	static T str2int(const std::string& data);

	static std::string getEventString(BS2_DEVICE_ID id, const BS2Event& event, int32_t timezone);
	static std::string getEventStringWithThermal(BS2_DEVICE_ID id, const BS2Event& event, int32_t timezone, BS2_TEMPERATURE temperature);

	static std::string getHexaString(const uint8_t* data, uint32_t size);
	static int saveBMP(FILE* fp, unsigned char* data, int width, int height);

	static BS2_BOOL isYes(std::string msg);
	static BS2_BOOL isNo(std::string msg);

private:
	static void writeBMPSign(unsigned char* buf, unsigned short type, unsigned long size, unsigned long off_bits);
};

template <typename T>
inline T Utility::getInput(std::string msg)
{
	std::cout << "==> " << msg << " ";
	T value;
	std::cin >> value;

	return value;
}

template <typename T>
inline std::vector<T> Utility::tokenizeInteger(const std::string& data, const char delimiter)
{
	std::vector<T> result;
	std::string tokenized;
	std::stringstream ss(data);
	while (std::getline(ss, tokenized, delimiter))
	{
		T tok = str2int<T>(tokenized);
		result.push_back(tok);
	}

	return result;
}

template <typename T>
inline T Utility::str2int(const std::string& data)
{
	if (data.size() == 0)
		return (T)0;

	return static_cast<T>(atoi(data.c_str()));
}