#ifndef __CSCORING_H__
#define __CSCORING_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;

class CScoring
{
public:
	CScoring();
	~CScoring();
	void CountScore(int nscore);
	void ShowScore();
	void Scorecompare();
	int Score1st;
	int Score2nd;
	int Score3rd;
private:
	cocos2d::ui::TextBMFont *_ScoreValue1st;
	cocos2d::ui::TextBMFont *_ScoreValue2nd;
	cocos2d::ui::TextBMFont *_ScoreValue3rd;
	cocos2d::ui::TextBMFont *_ScoreValue4th;
	cocos2d::ui::TextBMFont *_ScoreValue5th;
	cocos2d::ui::TextBMFont *_ScoreValuePlayer;
};

#endif // !__CSCORING_H__

