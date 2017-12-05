#ifndef __RUNNER_H__
#define __RUNNER_H__

#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"

#define RUNNERCOLOR1 cocos2d::Color3B(209,73,63)
#define RUNNERCOLOR2 cocos2d::Color3B(200,209,63)
#define RUNNERCOLOR3 cocos2d::Color3B(75,155,77)
#define RUNNERCOLOR4 cocos2d::Color3B(82,131,151);

class Runner
{
private:
	cocos2d::Node   *_runnerRoot;
	cocos2d::Node   *_NormalFace;
	cocos2d::Node   *_HappyFace;
	cocos2d::Node   *_SadFace;
	cocos2d::Sprite *_body;
	cocos2d::Sprite *_shadow;
	cocos2d::Action *_action;
	cocos2d::Point _runnerPt;
	cocos2d::Sprite *_runner;
	cocos2d::Sequence *_mySequence;
	cocos2d::Action   *_myAction;
	// For Double Jump
	cocos2d::JumpBy   *_myJump;
	int _NoJumps;

public:
	Runner(const char *csbname, cocos2d::Layer &parent);
	~Runner();
	void setPosition(const cocos2d::Point &pos);
	void setPosition(const float x, const float y);
	void setColor(const cocos2d::Color3B& color);
	void setAnimation(const char *plistFile);
	void go();
	void jump();

};

#endif