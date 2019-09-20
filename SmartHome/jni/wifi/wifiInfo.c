/*
 * wifiInfo.c
 *
 *  Created on: 2019年8月15日
 *      Author: koda.xu
 */
#include <string.h>
#include "wifiInfo.h"

static bool isWifiSupport = true;
static bool isWifiEnable = true;
static bool isSsidSaved = false;	// if exsit saved ssid&passwd
static bool isConnected = false;
static WLAN_HANDLE wlanHdl = -1;
static MI_WLAN_ConnectParam_t stConnectParam;

bool getWifiSupportStatus()
{
	return isWifiSupport;
}

void setWifiSupportStatus(bool enable)
{
	isWifiSupport = enable;
}

bool getWifiEnableStatus()
{
	return isWifiEnable;
}

void setWifiEnableStatus(bool enable)
{
	isWifiEnable = enable;
}

bool getSsidSavedStatus()
{
	return isSsidSaved;
}

void setSsidSavedStatus(bool enable)
{
	isSsidSaved = enable;
}

bool getConnectionStatus()
{
	return isConnected;
}

void setConnectionStatus(bool enable)
{
	isConnected = enable;
}

WLAN_HANDLE getWlanHandle()
{
	return wlanHdl;
}

void setWlanHandle(WLAN_HANDLE handle)
{
	wlanHdl = handle;
}

MI_WLAN_ConnectParam_t * getConnectParam()
{
	return &stConnectParam;
}

void saveConnectParam(MI_WLAN_ConnectParam_t *pConnParam)
{
	memset(&stConnectParam, 0, sizeof(MI_WLAN_ConnectParam_t));
	memcpy(&stConnectParam, pConnParam, sizeof(MI_WLAN_ConnectParam_t));
}
