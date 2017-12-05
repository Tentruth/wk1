#ifndef __RUNNERNODE_H__
#define __RUNNERNODE_H__

#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"


USING_NS_CC;

class RunnerNode : public Node
{
public:
	RunnerNode();
	static RunnerNode* create();
	void SetNodeInfo(const char *csbname,cocos2d::Layer *parnet);
	void setPosition(const cocos2d::Point &pos);
	void setPosition(const float x, const float y);
	void setColor(const cocos2d::Color3B& color);
	void setAnimation(const char *plistFile);
	void go();
	bool BacktoGround();
	void jump();
	cocos2d::Node   *_runnerRoot;
	cocos2d::Node   *_NormalFace;
	cocos2d::Node   *_HappyFace;
	cocos2d::Node   *_SadFace;
	cocos2d::Sprite *_body;

private:

	cocos2d::Size   _runnerSize;
	cocos2d::Sprite *_shadow;
	cocos2d::Action *_action;
	cocos2d::Point _runnerPt;
	cocos2d::Sequence *_mySequence;
	cocos2d::Action   *_myAction;
	cocos2d::Rect _runnerPre;
	cocos2d::Rect _runnerJumped;


};

#endif // !__RUNNERNODE_H__

