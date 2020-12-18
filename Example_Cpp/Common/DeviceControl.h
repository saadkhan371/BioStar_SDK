#pragma once

#include <vector>
#include <string>
#include "BS_API.h"


class DeviceControl
{
public:
	DeviceControl(void* sdkContext);
	virtual ~DeviceControl();


public:
	int getDeviceInfo(BS2_DEVICE_ID id);
	int getDeviceInfo(BS2_DEVICE_ID id, BS2SimpleDeviceInfo& info);
	int getDeviceInfoEx(BS2_DEVICE_ID id);
	int getSpecifiedDeviceInfo(BS2_DEVICE_ID id);
	int getDeviceTime(BS2_DEVICE_ID id);
	int setDeviceTime(BS2_DEVICE_ID id);
	int clearDatabase(BS2_DEVICE_ID id);
	int factoryReset(BS2_DEVICE_ID id);
	int rebootDevice(BS2_DEVICE_ID id);
	int lockDevice(BS2_DEVICE_ID id);
	int unlockDevice(BS2_DEVICE_ID id);
	int upgradeFirmware(BS2_DEVICE_ID id);
	int updateResource(BS2_DEVICE_ID id);

	int getAuthOperatorLevelEx(BS2_DEVICE_ID id);
	int setAuthOperatorLevelEx(BS2_DEVICE_ID id);
	int removeAuthOperatorLevelEx(BS2_DEVICE_ID id);
	int getAllAuthOperatorLevelEx(BS2_DEVICE_ID id);
	int removeAllAuthOperatorLevelEx(BS2_DEVICE_ID id);
	int extractTemplateFaceEx(BS2_DEVICE_ID id, BS2TemplateEx& templateEx);


private:
	void print(const BS2SimpleDeviceInfo& info);
	void print(const BS2SimpleDeviceInfoEx& info);
	void print(const BS2IPv6DeviceInfo& info);
	void print(const BS2AuthOperatorLevel& opr);
	void print(const BS2TemplateEx& templateEx);
	static void onUpgrade(BS2_DEVICE_ID id, uint32_t percent);


private:
	static void* context_;
};
