/***********************************************
/gen auto by zuitools
***********************************************/
#include "mainActivity.h"

/*TAG:GlobalVariable全局变量*/
static ZKTextView* mTextview6Ptr;
static ZKTextView* mTextview12Ptr;
static ZKButton* mButtonSavePtr;
static ZKListView* mListviewMinPtr;
static ZKListView* mListviewHourPtr;
static ZKListView* mListviewDayPtr;
static ZKListView* mListviewmonthPtr;
static ZKListView* mListviewYearPtr;
static ZKWindow* mWindow7Ptr;
static ZKTextView* mTextview18Ptr;
static ZKTextView* mTextview17Ptr;
static ZKButton* mButton10Ptr;
static ZKButton* mButton1Ptr;
static ZKTextView* mTextview11Ptr;
static ZKTextView* mTextview3Ptr;
static ZKWindow* mWindow4Ptr;
static ZKListView* mListview2Ptr;
static ZKTextView* mTextview10Ptr;
static ZKTextView* mTextview1Ptr;
static ZKWindow* mWindow3Ptr;
static ZKTextView* mTextview16Ptr;
static ZKTextView* mTextview15Ptr;
static ZKTextView* mTextview14Ptr;
static ZKButton* mButton9Ptr;
static ZKButton* mButton8Ptr;
static ZKButton* mButton7Ptr;
static ZKButton* mButton6Ptr;
static ZKButton* mButton5Ptr;
static ZKButton* mButton4Ptr;
static ZKTextView* mTextview13Ptr;
static ZKListView* mListviewTempturePtr;
static ZKTextView* mTextview9Ptr;
static ZKTextView* mTextview2Ptr;
static ZKWindow* mWindow2Ptr;
static ZKTextView* mTextviewModePtr;
static ZKListView* mListViewModePtr;
static ZKTextView* mTextview8Ptr;
static ZKTextView* mTextview4Ptr;
static ZKWindow* mWindowmodePtr;
static ZKTextView* mTextview7Ptr;
static ZKSeekBar* mSeekbar1Ptr;
static ZKButton* mButton3Ptr;
static ZKButton* mButton2Ptr;
static ZKButton* mButtonPlayPtr;
static ZKTextView* mTextview5Ptr;
static ZKWindow* mWindowMusicPtr;
static ZKWindow* mWindow1Ptr;
static ZKListView* mListview1Ptr;
static mainActivity* mActivityPtr;

/*register activity*/
REGISTER_ACTIVITY(mainActivity);

typedef struct {
	int id; // 定时器ID ， 不能重复
	int time; // 定时器  时间间隔  单位 毫秒
}S_ACTIVITY_TIMEER;

#include "logic/mainLogic.cc"

/***********/
typedef struct {
    int id;
    const char *pApp;
} SAppInfo;

/**
 *点击跳转window
 */
static SAppInfo sAppInfoTab[] = {
//  { ID_MAIN_TEXT, "TextViewActivity" },
};

/***************/
typedef bool (*ButtonCallback)(ZKButton *pButton);
/**
 * button onclick表
 */
typedef struct {
    int id;
    ButtonCallback callback;
}S_ButtonCallback;

/*TAG:ButtonCallbackTab按键映射表*/
static S_ButtonCallback sButtonCallbackTab[] = {
    ID_MAIN_ButtonSave, onButtonClick_ButtonSave,
    ID_MAIN_Button10, onButtonClick_Button10,
    ID_MAIN_Button1, onButtonClick_Button1,
    ID_MAIN_Button9, onButtonClick_Button9,
    ID_MAIN_Button8, onButtonClick_Button8,
    ID_MAIN_Button7, onButtonClick_Button7,
    ID_MAIN_Button6, onButtonClick_Button6,
    ID_MAIN_Button5, onButtonClick_Button5,
    ID_MAIN_Button4, onButtonClick_Button4,
    ID_MAIN_Button3, onButtonClick_Button3,
    ID_MAIN_Button2, onButtonClick_Button2,
    ID_MAIN_ButtonPlay, onButtonClick_ButtonPlay,
};
/***************/


typedef void (*SeekBarCallback)(ZKSeekBar *pSeekBar, int progress);
typedef struct {
    int id;
    SeekBarCallback callback;
}S_ZKSeekBarCallback;
/*TAG:SeekBarCallbackTab*/
static S_ZKSeekBarCallback SZKSeekBarCallbackTab[] = {
    ID_MAIN_Seekbar1, onProgressChanged_Seekbar1,
};


typedef int (*ListViewGetItemCountCallback)(const ZKListView *pListView);
typedef void (*ListViewobtainListItemDataCallback)(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index);
typedef void (*ListViewonItemClickCallback)(ZKListView *pListView, int index, int id);
typedef struct {
    int id;
    ListViewGetItemCountCallback getListItemCountCallback;
    ListViewobtainListItemDataCallback obtainListItemDataCallback;
    ListViewonItemClickCallback onItemClickCallback;
}S_ListViewFunctionsCallback;
/*TAG:ListViewFunctionsCallback*/
static S_ListViewFunctionsCallback SListViewFunctionsCallbackTab[] = {
    ID_MAIN_ListviewMin, getListItemCount_ListviewMin, obtainListItemData_ListviewMin, onListItemClick_ListviewMin,
    ID_MAIN_ListviewHour, getListItemCount_ListviewHour, obtainListItemData_ListviewHour, onListItemClick_ListviewHour,
    ID_MAIN_ListviewDay, getListItemCount_ListviewDay, obtainListItemData_ListviewDay, onListItemClick_ListviewDay,
    ID_MAIN_Listviewmonth, getListItemCount_Listviewmonth, obtainListItemData_Listviewmonth, onListItemClick_Listviewmonth,
    ID_MAIN_ListviewYear, getListItemCount_ListviewYear, obtainListItemData_ListviewYear, onListItemClick_ListviewYear,
    ID_MAIN_Listview2, getListItemCount_Listview2, obtainListItemData_Listview2, onListItemClick_Listview2,
    ID_MAIN_ListviewTempture, getListItemCount_ListviewTempture, obtainListItemData_ListviewTempture, onListItemClick_ListviewTempture,
    ID_MAIN_ListViewMode, getListItemCount_ListViewMode, obtainListItemData_ListViewMode, onListItemClick_ListViewMode,
    ID_MAIN_Listview1, getListItemCount_Listview1, obtainListItemData_Listview1, onListItemClick_Listview1,
};


typedef void (*SlideWindowItemClickCallback)(ZKSlideWindow *pSlideWindow, int index);
typedef struct {
    int id;
    SlideWindowItemClickCallback onSlideItemClickCallback;
}S_SlideWindowItemClickCallback;
/*TAG:SlideWindowFunctionsCallbackTab*/
static S_SlideWindowItemClickCallback SSlideWindowItemClickCallbackTab[] = {
};


typedef void (*EditTextInputCallback)(const std::string &text);
typedef struct {
    int id;
    EditTextInputCallback onEditTextChangedCallback;
}S_EditTextInputCallback;
/*TAG:EditTextInputCallback*/
static S_EditTextInputCallback SEditTextInputCallbackTab[] = {
};

typedef void (*VideoViewCallback)(ZKVideoView *pVideoView, int msg);
typedef struct {
    int id; //VideoView ID
    bool loop; // 是否是轮播类型
    int defaultvolume;//轮播类型时,默认视频音量
    VideoViewCallback onVideoViewCallback;
}S_VideoViewCallback;
/*TAG:VideoViewCallback*/
static S_VideoViewCallback SVideoViewCallbackTab[] = {
};


mainActivity::mainActivity() {
	//todo add init code here
	mVideoLoopIndex = 0;
	mVideoLoopErrorCount = 0;
}

mainActivity::~mainActivity() {
  //todo add init file here
  // 退出应用时需要反注册
    EASYUICONTEXT->unregisterGlobalTouchListener(this);
    onUI_quit();
    unregisterProtocolDataUpdateListener(onProtocolDataUpdate);
}

const char* mainActivity::getAppName() const{
	return "main.ftu";
}

//TAG:onCreate
void mainActivity::onCreate() {
	Activity::onCreate();
    mTextview6Ptr = (ZKTextView*)findControlByID(ID_MAIN_Textview6);
    mTextview12Ptr = (ZKTextView*)findControlByID(ID_MAIN_Textview12);
    mButtonSavePtr = (ZKButton*)findControlByID(ID_MAIN_ButtonSave);
    mListviewMinPtr = (ZKListView*)findControlByID(ID_MAIN_ListviewMin);if(mListviewMinPtr!= NULL){mListviewMinPtr->setListAdapter(this);mListviewMinPtr->setItemClickListener(this);}
    mListviewHourPtr = (ZKListView*)findControlByID(ID_MAIN_ListviewHour);if(mListviewHourPtr!= NULL){mListviewHourPtr->setListAdapter(this);mListviewHourPtr->setItemClickListener(this);}
    mListviewDayPtr = (ZKListView*)findControlByID(ID_MAIN_ListviewDay);if(mListviewDayPtr!= NULL){mListviewDayPtr->setListAdapter(this);mListviewDayPtr->setItemClickListener(this);}
    mListviewmonthPtr = (ZKListView*)findControlByID(ID_MAIN_Listviewmonth);if(mListviewmonthPtr!= NULL){mListviewmonthPtr->setListAdapter(this);mListviewmonthPtr->setItemClickListener(this);}
    mListviewYearPtr = (ZKListView*)findControlByID(ID_MAIN_ListviewYear);if(mListviewYearPtr!= NULL){mListviewYearPtr->setListAdapter(this);mListviewYearPtr->setItemClickListener(this);}
    mWindow7Ptr = (ZKWindow*)findControlByID(ID_MAIN_Window7);
    mTextview18Ptr = (ZKTextView*)findControlByID(ID_MAIN_Textview18);
    mTextview17Ptr = (ZKTextView*)findControlByID(ID_MAIN_Textview17);
    mButton10Ptr = (ZKButton*)findControlByID(ID_MAIN_Button10);
    mButton1Ptr = (ZKButton*)findControlByID(ID_MAIN_Button1);
    mTextview11Ptr = (ZKTextView*)findControlByID(ID_MAIN_Textview11);
    mTextview3Ptr = (ZKTextView*)findControlByID(ID_MAIN_Textview3);
    mWindow4Ptr = (ZKWindow*)findControlByID(ID_MAIN_Window4);
    mListview2Ptr = (ZKListView*)findControlByID(ID_MAIN_Listview2);if(mListview2Ptr!= NULL){mListview2Ptr->setListAdapter(this);mListview2Ptr->setItemClickListener(this);}
    mTextview10Ptr = (ZKTextView*)findControlByID(ID_MAIN_Textview10);
    mTextview1Ptr = (ZKTextView*)findControlByID(ID_MAIN_Textview1);
    mWindow3Ptr = (ZKWindow*)findControlByID(ID_MAIN_Window3);
    mTextview16Ptr = (ZKTextView*)findControlByID(ID_MAIN_Textview16);
    mTextview15Ptr = (ZKTextView*)findControlByID(ID_MAIN_Textview15);
    mTextview14Ptr = (ZKTextView*)findControlByID(ID_MAIN_Textview14);
    mButton9Ptr = (ZKButton*)findControlByID(ID_MAIN_Button9);
    mButton8Ptr = (ZKButton*)findControlByID(ID_MAIN_Button8);
    mButton7Ptr = (ZKButton*)findControlByID(ID_MAIN_Button7);
    mButton6Ptr = (ZKButton*)findControlByID(ID_MAIN_Button6);
    mButton5Ptr = (ZKButton*)findControlByID(ID_MAIN_Button5);
    mButton4Ptr = (ZKButton*)findControlByID(ID_MAIN_Button4);
    mTextview13Ptr = (ZKTextView*)findControlByID(ID_MAIN_Textview13);
    mListviewTempturePtr = (ZKListView*)findControlByID(ID_MAIN_ListviewTempture);if(mListviewTempturePtr!= NULL){mListviewTempturePtr->setListAdapter(this);mListviewTempturePtr->setItemClickListener(this);}
    mTextview9Ptr = (ZKTextView*)findControlByID(ID_MAIN_Textview9);
    mTextview2Ptr = (ZKTextView*)findControlByID(ID_MAIN_Textview2);
    mWindow2Ptr = (ZKWindow*)findControlByID(ID_MAIN_Window2);
    mTextviewModePtr = (ZKTextView*)findControlByID(ID_MAIN_TextviewMode);
    mListViewModePtr = (ZKListView*)findControlByID(ID_MAIN_ListViewMode);if(mListViewModePtr!= NULL){mListViewModePtr->setListAdapter(this);mListViewModePtr->setItemClickListener(this);}
    mTextview8Ptr = (ZKTextView*)findControlByID(ID_MAIN_Textview8);
    mTextview4Ptr = (ZKTextView*)findControlByID(ID_MAIN_Textview4);
    mWindowmodePtr = (ZKWindow*)findControlByID(ID_MAIN_Windowmode);
    mTextview7Ptr = (ZKTextView*)findControlByID(ID_MAIN_Textview7);
    mSeekbar1Ptr = (ZKSeekBar*)findControlByID(ID_MAIN_Seekbar1);if(mSeekbar1Ptr!= NULL){mSeekbar1Ptr->setSeekBarChangeListener(this);}
    mButton3Ptr = (ZKButton*)findControlByID(ID_MAIN_Button3);
    mButton2Ptr = (ZKButton*)findControlByID(ID_MAIN_Button2);
    mButtonPlayPtr = (ZKButton*)findControlByID(ID_MAIN_ButtonPlay);
    mTextview5Ptr = (ZKTextView*)findControlByID(ID_MAIN_Textview5);
    mWindowMusicPtr = (ZKWindow*)findControlByID(ID_MAIN_WindowMusic);
    mWindow1Ptr = (ZKWindow*)findControlByID(ID_MAIN_Window1);
    mListview1Ptr = (ZKListView*)findControlByID(ID_MAIN_Listview1);if(mListview1Ptr!= NULL){mListview1Ptr->setListAdapter(this);mListview1Ptr->setItemClickListener(this);}
	mActivityPtr = this;
	onUI_init();
    registerProtocolDataUpdateListener(onProtocolDataUpdate); 
    rigesterActivityTimer();
}

void mainActivity::onClick(ZKBase *pBase) {
	//TODO: add widget onClik code 
    int buttonTablen = sizeof(sButtonCallbackTab) / sizeof(S_ButtonCallback);
    for (int i = 0; i < buttonTablen; ++i) {
        if (sButtonCallbackTab[i].id == pBase->getID()) {
            if (sButtonCallbackTab[i].callback((ZKButton*)pBase)) {
            	return;
            }
            break;
        }
    }


    int len = sizeof(sAppInfoTab) / sizeof(sAppInfoTab[0]);
    for (int i = 0; i < len; ++i) {
        if (sAppInfoTab[i].id == pBase->getID()) {
            EASYUICONTEXT->openActivity(sAppInfoTab[i].pApp);
            return;
        }
    }

	Activity::onClick(pBase);
}

void mainActivity::onResume() {
	Activity::onResume();
	EASYUICONTEXT->registerGlobalTouchListener(this);
	startVideoLoopPlayback();
	onUI_show();
}

void mainActivity::onPause() {
	Activity::onPause();
	EASYUICONTEXT->unregisterGlobalTouchListener(this);
	stopVideoLoopPlayback();
	onUI_hide();
}

void mainActivity::onIntent(const Intent *intentPtr) {
	Activity::onIntent(intentPtr);
	onUI_intent(intentPtr);
}

bool mainActivity::onTimer(int id) {
	return onUI_Timer(id);
}

void mainActivity::onProgressChanged(ZKSeekBar *pSeekBar, int progress){

    int seekBarTablen = sizeof(SZKSeekBarCallbackTab) / sizeof(S_ZKSeekBarCallback);
    for (int i = 0; i < seekBarTablen; ++i) {
        if (SZKSeekBarCallbackTab[i].id == pSeekBar->getID()) {
            SZKSeekBarCallbackTab[i].callback(pSeekBar, progress);
            break;
        }
    }
}

int mainActivity::getListItemCount(const ZKListView *pListView) const{
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            return SListViewFunctionsCallbackTab[i].getListItemCountCallback(pListView);
            break;
        }
    }
    return 0;
}

void mainActivity::obtainListItemData(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].obtainListItemDataCallback(pListView, pListItem, index);
            break;
        }
    }
}

void mainActivity::onItemClick(ZKListView *pListView, int index, int id){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].onItemClickCallback(pListView, index, id);
            break;
        }
    }
}

void mainActivity::onSlideItemClick(ZKSlideWindow *pSlideWindow, int index) {
    int tablen = sizeof(SSlideWindowItemClickCallbackTab) / sizeof(S_SlideWindowItemClickCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SSlideWindowItemClickCallbackTab[i].id == pSlideWindow->getID()) {
            SSlideWindowItemClickCallbackTab[i].onSlideItemClickCallback(pSlideWindow, index);
            break;
        }
    }
}

bool mainActivity::onTouchEvent(const MotionEvent &ev) {
    return onmainActivityTouchEvent(ev);
}

void mainActivity::onTextChanged(ZKTextView *pTextView, const std::string &text) {
    int tablen = sizeof(SEditTextInputCallbackTab) / sizeof(S_EditTextInputCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SEditTextInputCallbackTab[i].id == pTextView->getID()) {
            SEditTextInputCallbackTab[i].onEditTextChangedCallback(text);
            break;
        }
    }
}

void mainActivity::rigesterActivityTimer() {
    int tablen = sizeof(REGISTER_ACTIVITY_TIMER_TAB) / sizeof(S_ACTIVITY_TIMEER);
    for (int i = 0; i < tablen; ++i) {
        S_ACTIVITY_TIMEER temp = REGISTER_ACTIVITY_TIMER_TAB[i];
        registerTimer(temp.id, temp.time);
    }
}


void mainActivity::onVideoPlayerMessage(ZKVideoView *pVideoView, int msg) {
    int tablen = sizeof(SVideoViewCallbackTab) / sizeof(S_VideoViewCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SVideoViewCallbackTab[i].id == pVideoView->getID()) {
        	if (SVideoViewCallbackTab[i].loop) {
                //循环播放
        		videoLoopPlayback(pVideoView, msg, i);
        	} else if (SVideoViewCallbackTab[i].onVideoViewCallback != NULL){
        	    SVideoViewCallbackTab[i].onVideoViewCallback(pVideoView, msg);
        	}
            break;
        }
    }
}

void mainActivity::videoLoopPlayback(ZKVideoView *pVideoView, int msg, size_t callbackTabIndex) {

	switch (msg) {
	case ZKVideoView::E_MSGTYPE_VIDEO_PLAY_STARTED:
		LOGD("ZKVideoView::E_MSGTYPE_VIDEO_PLAY_STARTED\n");
    if (callbackTabIndex >= (sizeof(SVideoViewCallbackTab)/sizeof(S_VideoViewCallback))) {
      break;
    }
		pVideoView->setVolume(SVideoViewCallbackTab[callbackTabIndex].defaultvolume / 10.0);
		mVideoLoopErrorCount = 0;
		break;
	case ZKVideoView::E_MSGTYPE_VIDEO_PLAY_ERROR:
		/**错误处理 */
		++mVideoLoopErrorCount;
		if (mVideoLoopErrorCount > 100) {
			LOGD("video loop error counts > 100, quit loop playback !");
            break;
		} //不用break, 继续尝试播放下一个
	case ZKVideoView::E_MSGTYPE_VIDEO_PLAY_COMPLETED:
		LOGD("ZKVideoView::E_MSGTYPE_VIDEO_PLAY_COMPLETED\n");
        std::vector<std::string> videolist;
        std::string fileName(getAppName());
        if (fileName.size() < 4) {
             LOGD("getAppName size < 4, ignore!");
             break;
        }
        fileName = fileName.substr(0, fileName.length() - 4) + "_video_list.txt";
        fileName = "/mnt/extsd/" + fileName;
        if (!parseVideoFileList(fileName.c_str(), videolist)) {
            LOGD("parseVideoFileList failed !");
		    break;
        }
		if (pVideoView && !videolist.empty()) {
			mVideoLoopIndex = (mVideoLoopIndex + 1) % videolist.size();
			pVideoView->play(videolist[mVideoLoopIndex].c_str());
		}
		break;
	}
}

void mainActivity::startVideoLoopPlayback() {
    int tablen = sizeof(SVideoViewCallbackTab) / sizeof(S_VideoViewCallback);
    for (int i = 0; i < tablen; ++i) {
    	if (SVideoViewCallbackTab[i].loop) {
    		ZKVideoView* videoView = (ZKVideoView*)findControlByID(SVideoViewCallbackTab[i].id);
    		if (!videoView) {
    			return;
    		}
    		//循环播放
    		videoLoopPlayback(videoView, ZKVideoView::E_MSGTYPE_VIDEO_PLAY_COMPLETED, i);
    		return;
    	}
    }
}

void mainActivity::stopVideoLoopPlayback() {
    int tablen = sizeof(SVideoViewCallbackTab) / sizeof(S_VideoViewCallback);
    for (int i = 0; i < tablen; ++i) {
    	if (SVideoViewCallbackTab[i].loop) {
    		ZKVideoView* videoView = (ZKVideoView*)findControlByID(SVideoViewCallbackTab[i].id);
    		if (!videoView) {
    			return;
    		}
    		if (videoView->isPlaying()) {
    		    videoView->stop();
    		}
    		return;
    	}
    }
}

bool mainActivity::parseVideoFileList(const char *pFileListPath, std::vector<string>& mediaFileList) {
	mediaFileList.clear();
	if (NULL == pFileListPath || 0 == strlen(pFileListPath)) {
        LOGD("video file list is null!");
		return false;
	}

	ifstream is(pFileListPath, ios_base::in);
	if (!is.is_open()) {
		LOGD("cann't open file %s \n", pFileListPath);
		return false;
	}
	char tmp[1024] = {0};
	while (is.getline(tmp, sizeof(tmp))) {
		string str = tmp;
		removeCharFromString(str, '\"');
		removeCharFromString(str, '\r');
		removeCharFromString(str, '\n');
		if (str.size() > 1) {
     		mediaFileList.push_back(str.c_str());
		}
	}
	LOGD("(f:%s, l:%d) parse fileList[%s], get [%d]files\n", __FUNCTION__,
			__LINE__, pFileListPath, mediaFileList.size());
	for (size_t i = 0; i < mediaFileList.size(); i++) {
		LOGD("file[%d]:[%s]\n", i, mediaFileList[i].c_str());
	}
	is.close();

	return true;
}

int mainActivity::removeCharFromString(string& nString, char c) {
    string::size_type   pos;
    while(1) {
        pos = nString.find(c);
        if(pos != string::npos) {
            nString.erase(pos, 1);
        } else {
            break;
        }
    }
    return (int)nString.size();
}

void mainActivity::registerUserTimer(int id, int time) {
	registerTimer(id, time);
}

void mainActivity::unregisterUserTimer(int id) {
	unregisterTimer(id);
}

void mainActivity::resetUserTimer(int id, int time) {
	resetTimer(id, time);
}