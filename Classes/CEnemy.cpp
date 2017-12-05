#include "CEnemy.h"
#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace ui;


CEnemy::CEnemy()
{
	_body = nullptr;
	_flame = nullptr;
	_shadow = nullptr;
}

CEnemy *CEnemy::create()
{
	CEnemy *enobj = new (std::nothrow) CEnemy();
	if (enobj)
	{
		enobj->autorelease();
		return enobj;
	}
	CC_SAFE_DELETE(enobj);
	return nullptr;
}

void CEnemy::SetNodeInfo(const char * csbname)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	_enemyRoot = CSLoader::createNode(csbname);
	_enemyRoot->setPosition((visibleSize.width - 300) / 2.0f, visibleSize.height / 2.0f);
	_body = (Sprite *)_enemyRoot->getChildByName("body");
	_flame = (Sprite *)_enemyRoot->getChildByName("flame");
	_shadow = (Sprite *)_enemyRoot->getChildByName("shadow");
	_body->setColor(Color3B(170, 80, 90));
	_enemyRoot->setVisible(true);
}

void CEnemy::setPosition(const cocos2d::Point & pos)
{
	_enemyRoot->setPosition(pos);
}

void CEnemy::setAnimation()
{
	auto _action = (ActionTimeline *)CSLoader::createTimeline("Scene.csb");
	_action->gotoFrameAndPlay(0, 45, false);
	_triAction = _action;
	_action->retain();
}


void CEnemy::attack()
{
	_enemyRoot->runAction(_triAction->clone());
}

bool CEnemy::crash()
{
	return false;
}
