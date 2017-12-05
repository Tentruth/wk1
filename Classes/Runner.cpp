#include "Runner.h"
#define CIRCLERUNNER "CircleNode.csb"
#define TRAINGLERUNNER "TraingleNode.csb"
#define CUBERRUNNER "CuberNode.csb"
#define KINGSTONERUNNER "KingstoneNode.csb"
USING_NS_CC;

//
// 建立角色之前，必須先確定已經讀入儲存角色所有動態圖片的 plist 檔
//

Runner::Runner(const char *csbname, cocos2d::Layer &parent)
{
	// 讀取角色
	_runnerRoot = CSLoader::createNode(csbname);
	//	_runnerRoot = (cocos2d::Node*)getNode->getChildByName("RunnerRoot");
	_runnerRoot->setPosition(25, 0); // 預設放在 (0,0) 
	_body = (cocos2d::Sprite *)_runnerRoot->getChildByName("Body");
	_body->setColor(Color3B(209, 73, 63));
	_NormalFace = (cocos2d::Node *)_runnerRoot->getChildByName("NormalFace");
	_HappyFace = (cocos2d::Node *)_runnerRoot->getChildByName("HappyFace");
	_SadFace = (cocos2d::Node *)_runnerRoot->getChildByName("SadFace");
	_HappyFace->setVisible(false);
	_SadFace->setVisible(false);
	parent.addChild(_runnerRoot);
	_NoJumps = 0;
	_myJump = JumpBy::create(0.65f, Point(0, 0), 150, 1);
	_myJump->retain();
	_runnerPt = _runnerRoot->getPosition();
}


Runner::~Runner()
{
	_action->release();
}


void Runner::setAnimation(const char *plistFile)
{
	// 此處假設儲存角色所有動態圖片的 plist 檔已經讀入
	auto cache = AnimationCache::getInstance();
	cache->addAnimationsWithFile(plistFile);
	auto animation = cache->getAnimation("running");
	_action = RepeatForever::create(Animate::create(animation));
	_action->retain();
}


void Runner::go()
{
	_body->runAction(_action);
}

void Runner::jump()
{
	//JumpBy * jumpby = JumpBy::create(1.25f, Point(-600, 0), 150, 3);
	//auto jumpbyBack = jumpby->reverse();
	//auto sequence = Sequence::create(jumpby, jumpbyBack, NULL);
	//_runnerRoot->runAction(Sequence::create(jumpby, jumpbyBack, NULL));
}


void Runner::setPosition(const Point &pos)
{
	_runnerRoot->setPosition(pos);
}

void Runner::setPosition(const float x, const float y)
{
	_runnerRoot->setPosition(x, y);
}

void Runner::setColor(const Color3B& color)
{
	_body->setColor(color);
}