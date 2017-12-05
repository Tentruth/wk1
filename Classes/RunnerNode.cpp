#include "RunnerNode.h"
#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"

#define JUMPHIGH 100

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace ui;

bool Jumped;

RunnerNode * RunnerNode::create()
{
	RunnerNode *rnobj = new (std::nothrow) RunnerNode();
	if (rnobj)
	{
		rnobj->autorelease();
		return rnobj;
	}
	CC_SAFE_DELETE(rnobj);
	return nullptr;
}

RunnerNode::RunnerNode()
{
	_body = nullptr;
	_HappyFace = nullptr;
	_SadFace = nullptr;
	_NormalFace = nullptr;
}


void RunnerNode::SetNodeInfo(const char * csbname,cocos2d::Layer *parnet)
{
	_runnerPre.origin.x = 25;
	_runnerPre.origin.y = 0;
	_runnerRoot = CSLoader::createNode(csbname);
	_body = (Sprite *)_runnerRoot->getChildByName("Body");
	_body->setColor(Color3B(209, 73, 63));
	_NormalFace = (Node *)_runnerRoot->getChildByName("NormalFace");
	_HappyFace = (Node *)_runnerRoot->getChildByName("HappyFace");
	_SadFace = (Node *)_runnerRoot->getChildByName("SadFace");
	_HappyFace->setVisible(false);
	_SadFace->setVisible(false);
	parnet->addChild(_runnerRoot);
	_runnerSize = _body->getContentSize();
}

void RunnerNode::setPosition(const cocos2d::Point & pos)
{
	_runnerRoot->setPosition(pos);
}

void RunnerNode::setPosition(const float x, const float y)
{
	_runnerRoot->setPosition(x, y);
}

void RunnerNode::setColor(const cocos2d::Color3B & color)
{
	_body->setColor(color);
}

void RunnerNode::setAnimation(const char * plistFile)
{
	auto cache = AnimationCache::getInstance();
	cache->addAnimationsWithFile(plistFile);
	auto animation = cache->getAnimation("running");
	_action = RepeatForever::create(Animate::create(animation));
	_action->retain();
}

void RunnerNode::go()
{
	_body->runAction(_action);
}

void RunnerNode::jump()
{
	JumpBy* jumpby = JumpBy::create(0.75f, Point(0, 0), JUMPHIGH, 1);
	auto *_runnerjump = _runnerRoot;
	//_runnerRoot->runAction(jumpby->clone());
	_runnerRoot->runAction(cocos2d::Sequence::create(jumpby, NULL));
}
bool RunnerNode::BacktoGround()
{
	/*_runnerPt = _runnerRoot->getPosition();
	_runnerJumped.origin.x = _runnerPt.x;
	_runnerJumped.origin.y = _runnerPt.y;
	_runnerJumped.size = _runnerSize;
	if (_runnerJumped.containsPoint(Point(25,0)))
	{
		return false;
	}
	else
	{*/
		return true;
	
}