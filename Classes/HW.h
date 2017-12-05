#ifndef _HW_H_
#define _HW_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"
#include "SimpleAudioEngine.h"
#include "cocostudio/CocoStudio.h"
#include "C3SButton.h"
#include "Runner.h"
#include "CEnemy.h"
#include "CScoring.h"
#include "RunnerNode.h"

USING_NS_CC;

class HW : public cocos2d::Layer 
{
private:
	cocos2d::Sprite *_runner;
	int _NoJumps;
	cocos2d::CallFunc *_mycallback;
	cocos2d::Point _runnerPt;
	C3SButton *replaybtn;
	C3SButton *Quit;
	C3SButton *circle;
	C3SButton *traingle;
	C3SButton *cuber;
	C3SButton *kingstone;
	CScoring *coScoing;
	RunnerNode *runner;
	CEnemy *enemy;
	cocos2d::Sprite *shadow;
	cocos2d::ui::TextBMFont *Score;
	cocos2d::ui::TextBMFont *FScore;
	cocos2d::ui::TextBMFont *Countdown;
public:
	~HW(); 
	static cocos2d::Scene* createScene();
	virtual bool init();
	bool ChooseCharater();
	bool stage1();
	bool Crash();
	bool Gameover();
	
	cocos2d::EventListenerTouchOneByOne *_listener1;
	bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰開始事件
	void onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰移動事件
	void onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
	void doStep(float dt);
	void CountHP();
	void replaystage();
	void BGLMoving();
	CREATE_FUNC(HW);

};
#endif // __HW_H__