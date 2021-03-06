#pragma once
#include "uart/ProtocolSender.h"
/*
*此文件由GUI工具生成
*文件功能：用于处理用户的逻辑相应代码
*功能说明：
*========================onButtonClick_XXXX
当页面中的按键按下后系统会调用对应的函数，XXX代表GUI工具里面的[ID值]名称，
如Button1,当返回值为false的时候系统将不再处理这个按键，返回true的时候系统将会继续处理此按键。比如SYS_BACK.
*========================onSlideWindowItemClick_XXXX(int index) 
当页面中存在滑动窗口并且用户点击了滑动窗口的图标后系统会调用此函数,XXX代表GUI工具里面的[ID值]名称，
如slideWindow1;index 代表按下图标的偏移值
*========================onSeekBarChange_XXXX(int progress) 
当页面中存在滑动条并且用户改变了进度后系统会调用此函数,XXX代表GUI工具里面的[ID值]名称，
如SeekBar1;progress 代表当前的进度值
*========================ogetListItemCount_XXXX() 
当页面中存在滑动列表的时候，更新的时候系统会调用此接口获取列表的总数目,XXX代表GUI工具里面的[ID值]名称，
如List1;返回值为当前列表的总条数
*========================oobtainListItemData_XXXX(ZKListView::ZKListItem *pListItem, int index)
 当页面中存在滑动列表的时候，更新的时候系统会调用此接口获取列表当前条目下的内容信息,XXX代表GUI工具里面的[ID值]名称，
如List1;pListItem 是贴图中的单条目对象，index是列表总目的偏移量。具体见函数说明
*========================常用接口===============
*LOGD(...)  打印调试信息的接口
*mTextXXXPtr->setText("****") 在控件TextXXX上显示文字****
*mButton1Ptr->setSelected(true); 将控件mButton1设置为选中模式，图片会切换成选中图片，按钮文字会切换为选中后的颜色
*mSeekBarPtr->setProgress(12) 在控件mSeekBar上将进度调整到12
*mListView1Ptr->refreshListView() 让mListView1 重新刷新，当列表数据变化后调用
*mDashbroadView1Ptr->setTargetAngle(120) 在控件mDashbroadView1上指针显示角度调整到120度
*
* 在Eclipse编辑器中  使用 “alt + /”  快捷键可以打开智能提示
*/

#include "utils/TimeHelper.h"
#include "base_types.h"

extern "C"{
typedef enum {
	START_PLAY_MUSIC = 5,
	STOP_PLAY_MUSIC = 8,
	ALL_APP_CMD
} AppCmd_e;

typedef void* (*VoiceAnalyzeCallback)(int);

HANDLE SSTAR_VoiceDetectInit();
int SSTAR_VoiceDetectDeinit(HANDLE hDSpotter);
int SSTAR_VoiceDetectStart(HANDLE hDSpotter, VoiceAnalyzeCallback pfnCallback);
void SSTAR_VoiceDetectStop();

int SSTAR_StartPlayAudioFile(const char *WavAudioFile, int aoVolume);
int SSTAR_StopPlayAudioFile(void);
void SSTAR_setVolume(int vol);
}

#define WORD_COUNT			32
#define sub(x,y) ((x>y)?(x-y):(y-x))

const int dayTab[]={31,28,31,30,31,30,31,31,30,31,30,31,30};
static HANDLE g_hDSpotter = NULL;

/**
 * 注册定时器
 * 填充数组用于注册定时器
 * 注意：id不能重复
 */
static S_ACTIVITY_TIMEER REGISTER_ACTIVITY_TIMER_TAB[] = {
	{0,  30}, //定时器id=0, 时间间隔6秒
	{1,  1000},
};

static int targetPos = 0, curPos = 0;
static bool sIsSeled[WORD_COUNT];
static int uipos[]={
		0,
		-480,
		-960,
		-1440,
		-1920,
		-2400,
		-2880
};

static void EnterToPlayerPage()
{
	LayoutPosition layout = mWindow1Ptr->getPosition();
	curPos = -1920;
	targetPos = curPos;
	layout.mTop = curPos;
	mWindow1Ptr->setPosition(layout);
}

static void* onVoiceAnalyzeCallback(int commandID) {
	LOGD("CommandID: %d\n", commandID);
	if (commandID == START_PLAY_MUSIC)
	{
		EnterToPlayerPage();
		SSTAR_StartPlayAudioFile("/customer/res/8K_16bit_MONO.wav", 2);
		printf("start playing music\n"); // do start playing music
		mButtonPlayPtr->setSelected(1);
	}
	else if (commandID == STOP_PLAY_MUSIC)
	{
		EnterToPlayerPage();
		SSTAR_StopPlayAudioFile();
		printf("stop playing music\n"); // do stop playing music
		mButtonPlayPtr->setSelected(0);
	}

	return NULL;
}


static void initTimerDisp(){

	struct tm *t = TimeHelper::getDateTime();
	int year = t->tm_year+1900;
	int month = t->tm_mon+1;
	int day = t->tm_mday;
	int hour = t->tm_hour;
	int minute = t->tm_min;

	if(year < 2010) year = 2010;

	if(year == 2010){
		mListviewYearPtr->setSelected(80);
	}else{
		mListviewYearPtr->setSelection(year-2010-1);
	}

	if(month < 2){
		mListviewmonthPtr->setSelection(month-2+12);
	}else{
		mListviewmonthPtr->setSelection(month-2);
	}


	int index = mListviewmonthPtr->getFirstVisibleItemIndex()+1;
	index = index%12;
	int size = dayTab[index];
	if(index == 1){
		int index = mListviewYearPtr->getFirstVisibleItemIndex()+2011;
		if(index%4 == 0){
			size = 29;
		}
	}

	if(day < 2){
		mListviewDayPtr->setSelection(day-2+size);
	}else{
		mListviewDayPtr->setSelection(day-2);
	}

	if(hour < 1){
		mListviewHourPtr->setSelection(23);
	}else{
		mListviewHourPtr->setSelection(hour-1);
	}

	if(minute < 1){
		mListviewMinPtr->setSelection(59);
	}else
		mListviewMinPtr->setSelection(minute-1);

}

/**
 * 当界面构造时触发
 */
static void onUI_init(){
    //Tips :添加 UI初始化的显示代码到这里,如:mText1Ptr->setText("123");
	printf("onUi init\n");

	// init voice detect
	memset(sIsSeled, 0, sizeof(sIsSeled));
	g_hDSpotter = SSTAR_VoiceDetectInit();
	if (!g_hDSpotter)
	{
		printf("Voice detect init failed\n");
		return;
	}

	SSTAR_VoiceDetectStart(g_hDSpotter, onVoiceAnalyzeCallback);

	//curPos = mWindow1Ptr->getPosition().mTop;
	curPos = 0;
	LayoutPosition layout = mWindow1Ptr->getPosition();
	layout.mTop = curPos;
	mWindow1Ptr->setPosition(layout);

	printf("curPos is %d\n", curPos);
	mSeekbar1Ptr->setProgress(0);
	initTimerDisp();
}

/**
 * 当切换到该界面时触发
 */
static void onUI_intent(const Intent *intentPtr) {
    if (intentPtr != NULL) {
        //TODO
    }

    printf("onUi intent\n");
}

/*
 * 当界面显示时触发
 */
static void onUI_show() {
	printf("onUi show\n");
}

/*
 * 当界面隐藏时触发
 */
static void onUI_hide() {

}

/*
 * 当界面完全退出时触发
 */
static void onUI_quit() {
	printf("onUi quit\n");
	SSTAR_VoiceDetectStop();
	SSTAR_VoiceDetectDeinit(g_hDSpotter);
}

/**
 * 串口数据回调接口
 */
static void onProtocolDataUpdate(const SProtocolData &data) {

}

/**
 * 定时器触发函数
 * 不建议在此函数中写耗时操作，否则将影响UI刷新
 * 参数： id
 *         当前所触发定时器的id，与注册时的id相同
 * 返回值: true
 *             继续运行当前定时器
 *         false
 *             停止运行当前定时器
 */
static bool onUI_Timer(int id){
	switch (id) {
	case 0:

		if(targetPos != curPos){
			//LOGD("Timer0: targetPos %d,curPos:%d",targetPos,curPos);
			if(sub(targetPos,curPos) > 5){
				if(targetPos > curPos){
					curPos += (targetPos-curPos)/2;
					LayoutPosition layout = mWindow1Ptr->getPosition();
					layout.mTop = curPos;
					mWindow1Ptr->setPosition(layout);
				}else{
					curPos -= (curPos-targetPos)/2;
					LayoutPosition layout = mWindow1Ptr->getPosition();
					layout.mTop = curPos;
					mWindow1Ptr->setPosition(layout);
				}
			}else{
				LayoutPosition layout = mWindow1Ptr->getPosition();
				curPos = targetPos;
				layout.mTop = curPos;
				mWindow1Ptr->setPosition(layout);
			}
		}
		break;
	case 1: // 1000s;
		mSeekbar1Ptr->setProgress(0);
		break;
		default:
			break;
	}
    return true;
}


/**
 * 有新的触摸事件时触发
 * 参数：ev
 *         新的触摸事件
 * 返回值：true
 *            表示该触摸事件在此被拦截，系统不再将此触摸事件传递到控件上
 *         false
 *            触摸事件将继续传递到控件上
 */
static bool onmainActivityTouchEvent(const MotionEvent &ev) {
    switch (ev.mActionStatus) {
		case MotionEvent::E_ACTION_DOWN://触摸按下
			break;
		case MotionEvent::E_ACTION_MOVE://触摸滑动
			break;
		case MotionEvent::E_ACTION_UP:  //触摸抬起
			break;
		default:
			break;
	}
	return false;
}
static int getListItemCount_Listview1(const ZKListView *pListView) {
    //LOGD("getListItemCount_Listview1 !\n");
    return 6;
}
static int listSel = 0;
static const char* IconText[]={
		"0","a",
		"1","b",
		"2","c",
		"3","d",
		"4","e",
		"5","f",
		"6","g",
		"1","b"
};
static void obtainListItemData_Listview1(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ Listview1  !!!\n");
	ZKListView::ZKListSubItem* item = pListItem->findSubItemByID(ID_MAIN_SubItem1);
	if(listSel == index){
		item->setText(IconText[index*2+1]);
	}else{
		item->setText(IconText[index*2]);
	}
}

static void onListItemClick_Listview1(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ Listview1, index is %d  !!!\n", index);
	listSel = index;
	targetPos = uipos[index];
}
static bool onButtonClick_Button1(ZKButton *pButton) {
    //LOGD(" ButtonClick Button1 !!!\n");
    return false;
}

static bool onButtonClick_Button2(ZKButton *pButton) {
    //LOGD(" ButtonClick Button2 !!!\n");
    return false;
}
static bool onButtonClick_Button3(ZKButton *pButton) {
    //LOGD(" ButtonClick Button3 !!!\n");
    return false;
}

static void onProgressChanged_Seekbar1(ZKSeekBar *pSeekBar, int progress) {
    //LOGD(" ProgressChanged Seekbar1 %d !!!\n", progress);
}
static int lamplistSel = 0;

const char* const LampName[] = {
		"客厅灯",
		"氛围灯",
		"筒灯",
		"饭厅灯",
		"电视灯",
		"房间1",
		"房间2",
		"走廊灯",
		"阳台灯",
		"吊顶灯",
		"射灯",
};
static int getListItemCount_Listview2(const ZKListView *pListView) {
    //LOGD("getListItemCount_Listview2 !\n");
    return 9;

}

static void obtainListItemData_Listview2(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ Listview2  !!!\n");

	ZKListView::ZKListSubItem* subitem= pListItem->findSubItemByID(ID_MAIN_SubItem2);
	if(lamplistSel & (1<< index)){
		subitem->setSelected(true);
	}else{
		subitem->setSelected(false);
	}
	pListItem->setText(LampName[index]);
}

static void onListItemClick_Listview2(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ Listview2  !!!\n");
	if(lamplistSel & (1<< index)){
		lamplistSel &= ~(1<< index);
	}else{
		lamplistSel |= (1<< index);
	}
	//sendProtocol(cmdID, pData, len)
}
static const char* TempTab[]={
		"  ",
		"Lo",
		"16",
		"17",
		"18",
		"19",
		"20",
		"21",
		"22",
		"23",
		"24",
		"25",
		"26",
		"27",
		"28",
		"29",
		"Hi",
		" ",
		" ",
};
static int getListItemCount_ListviewTempture(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListviewTempture !\n");
    return sizeof(TempTab)/sizeof(char*);
}

static void obtainListItemData_ListviewTempture(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListviewTempture  !!!\n");
	pListItem->setText(TempTab[index]);
	int first = pListView->getFirstVisibleItemIndex();
	if(index == first+1){
		pListItem->setSelected(true);
	}else{
		pListItem->setSelected(false);
	}
}

static void onListItemClick_ListviewTempture(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListviewTempture  !!!\n");
	pListView->setSelection(index-1);

}
static bool onButtonClick_Button4(ZKButton *pButton) {
    //LOGD(" ButtonClick Button4 !!!\n");
    return false;
}

static bool onButtonClick_Button5(ZKButton *pButton) {
    //LOGD(" ButtonClick Button5 !!!\n");
    return false;
}

static bool onButtonClick_Button6(ZKButton *pButton) {
    //LOGD(" ButtonClick Button6 !!!\n");
    return false;
}

static bool onButtonClick_Button7(ZKButton *pButton) {
    //LOGD(" ButtonClick Button7 !!!\n");
    return false;
}

static bool onButtonClick_Button8(ZKButton *pButton) {
    //LOGD(" ButtonClick Button8 !!!\n");
    return false;
}

static bool onButtonClick_Button9(ZKButton *pButton) {
    //LOGD(" ButtonClick Button9 !!!\n");
    return false;
}
static bool onButtonClick_ButtonPlay(ZKButton *pButton) {
    //LOGD(" ButtonClick ButtonPlay !!!\n");
    return false;
}
static const char* modeTab[]{
		"0","影院模式",
		"1","娱乐模式",
		"2","在家模式",
		"3","阅读模式",
		"4","离家模式",
		"5","温馨模式"
};
static int selMode = 0;
static int getListItemCount_ListViewMode(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListViewMode !\n");
    return 6;
}

static void obtainListItemData_ListViewMode(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListViewMode  !!!\n");
	pListItem->setText(modeTab[index*2+1]);
	ZKListView::ZKListSubItem* subitem = pListItem->findSubItemByID(ID_MAIN_SubItem3);
	subitem->setText(modeTab[index*2]);
	if(selMode ==  index){
		pListItem->setBackgroundColor(0x00009789);
	}else{
		pListItem->setBackgroundColor(0x00607E8C);
	}
}

static void onListItemClick_ListViewMode(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListViewMode  !!!\n");
	selMode = index;
	mTextviewModePtr->setText(modeTab[index*2]);
}
static bool onButtonClick_Button10(ZKButton *pButton) {
    //LOGD(" ButtonClick Button10 !!!\n");
    return false;
}

static void onProgressChanged_Seekbar2(ZKSeekBar *pSeekBar, int progress) {
    //LOGD(" ProgressChanged Seekbar2 %d !!!\n", progress);
}

static int getListItemCount_ListviewHour(const ZKListView *pListView) {
    //LOGD(" getListItemCount_ ListviewHour  !!!\n");
    return 24;
}
static bool ontimeActivityTouchEvent(const MotionEvent& ev){
	return false;
}
static void obtainListItemData_ListviewHour(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListviewHour  !!!\n");
	pListItem->setText(index);
	int first = pListView->getFirstVisibleItemIndex();
	if((first == pListView->getListItemCount()-1) && (index == 0)){
		pListItem->setSelected(true);
	}else if(index == first+1){
		pListItem->setSelected(true);
	}else{
		pListItem->setSelected(false);
	}
}

static void onListItemClick_ListviewHour(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListviewHour  !!!\n");
	if(index == 0) index = 24;
	else if(index == 24) index = 1;
	pListView->setSelection(index-1);
}

static int getListItemCount_ListviewMin(const ZKListView *pListView) {
    //LOGD(" getListItemCount_ ListviewMin  !!!\n");
    return 60;
}

static void obtainListItemData_ListviewMin(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListviewMin  !!!\n");
	pListItem->setText(index);
	int first = pListView->getFirstVisibleItemIndex();
	if((first == pListView->getListItemCount()-1) && (index == 0)){
		pListItem->setSelected(true);
	}else if(index == first+1){
		pListItem->setSelected(true);
	}else{
		pListItem->setSelected(false);
	}
}

static void onListItemClick_ListviewMin(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListviewMin  !!!\n");
	pListView->setSelection(index-1);
}
static int daysize = 0;
static int getListItemCount_ListviewDay(const ZKListView *pListView) {
    //LOGD(" getListItemCount_ ListviewDay  !!!\n");
	int index = mListviewmonthPtr->getFirstVisibleItemIndex()+1;
	index = index%12;
	int size = dayTab[index];
	if(index == 1){
		int index = mListviewYearPtr->getFirstVisibleItemIndex()+2011;
		if(index%4 == 0){
			size = 29;
		}
	}
	daysize = size;
    return size;
}

static void obtainListItemData_ListviewDay(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListviewDay  !!!\n");
	pListItem->setText(index +1);
	int first = pListView->getFirstVisibleItemIndex();
	if((first == pListView->getListItemCount()-1) && (index == 0)){
		pListItem->setSelected(true);
	}else if(index == first+1){
		pListItem->setSelected(true);
	}else{
		pListItem->setSelected(false);
	}
}

static void onListItemClick_ListviewDay(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListviewDay  !!!\n");
	if(index == 0) index = daysize;
	else if(index == daysize) index = 1;
	pListView->setSelection(index-1);
}

static int getListItemCount_Listviewmonth(const ZKListView *pListView) {
    //LOGD(" getListItemCount_ Listviewmonth  !!!\n");
    return 12;
}

static void obtainListItemData_Listviewmonth(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ Listviewmonth  !!!\n");
	pListItem->setText(index +1);
	int first = pListView->getFirstVisibleItemIndex();
	if((first == pListView->getListItemCount()-1) && (index == 0)){
		pListItem->setSelected(true);
	}else if(index == first+1){
		pListItem->setSelected(true);
	}else{
		pListItem->setSelected(false);
	}
}

static void onListItemClick_Listviewmonth(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ Listviewmonth  !!!\n");
	if(index == 0) index = 12;
	else if(index == 12) index = 1;
	pListView->setSelection(index-1);
}

static int getListItemCount_ListviewYear(const ZKListView *pListView) {
    //LOGD(" getListItemCount_ ListviewYear  !!!\n");
    return 80;
}

static void obtainListItemData_ListviewYear(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListviewYear  !!!\n");
	pListItem->setText(index +2010);
	int first = pListView->getFirstVisibleItemIndex();
	if((first == pListView->getListItemCount()-1) && (index == 0)){
		pListItem->setSelected(true);
	}else if(index == first+1){
		pListItem->setSelected(true);
	}else{
		pListItem->setSelected(false);
	}
}

static void onListItemClick_ListviewYear(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListviewYear  !!!\n");
	if(index == 0) index = 80;
	else if(index == 80) index = 1;
	pListView->setSelection(index-1);
}
static bool onButtonClick_ButtonSave(ZKButton *pButton) {
    //LOGD(" ButtonClick ButtonSave !!!\n");
	int year = mListviewYearPtr->getFirstVisibleItemIndex()+2011;
	int month = mListviewmonthPtr->getFirstVisibleItemIndex()+2;
	int day = mListviewDayPtr->getFirstVisibleItemIndex()+2;
	int hour = mListviewHourPtr->getFirstVisibleItemIndex()+1;
	int minute = mListviewMinPtr->getFirstVisibleItemIndex()+1;

	struct tm t;
	if(year > 2089){
		year =year-2089+2010;
	}
	t.tm_year = year-1900;
	if(month > 12){
		month -= 12;
	}
	t.tm_mon = month - 1;

	int index = mListviewmonthPtr->getFirstVisibleItemIndex()+1;
	index = index%12;
	int size = dayTab[index];
	if(index == 1){
		int index = mListviewYearPtr->getFirstVisibleItemIndex()+2011;
		if(index%4 == 0){
			size = 29;
		}
	}
	if(day > size){
		day -= size;
	}

	t.tm_mday = day;
	if(hour > 23){
		hour = 0;
	}
	t.tm_hour = hour;
	if(minute > 59){
		minute = 0;
	}
	t.tm_min = minute;
	t.tm_sec = 1;

	LOGD("tm_year:%d",t.tm_year);
	LOGD("t.tm_mon:%d",t.tm_mon);
	LOGD("t.tm_mday:%d",t.tm_mday);
	LOGD("t.tm_hour:%d",t.tm_hour);
	LOGD("t.tm_min:%d",t.tm_min);
	LOGD("t.tm_sec:%d",t.tm_sec);

	TimeHelper::setDateTime(&t);

    return false;
}
