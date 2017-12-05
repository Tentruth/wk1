#ifndef __CENEMY_H__
#define __CENEMY_H__

#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"

USING_NS_CC;

class CEnemy : public Node
{
public:
	CEnemy();
	static CEnemy* create();
	void SetNodeInfo(const char *csbname);
	void setPosition(const cocos2d::Point &pos);
	void setAnimation();
	void go();
	void attack();
	bool crash();
	cocos2d::Node   *_enemyRoot;
private:
	cocos2d::Size  _enemySize;
	cocos2d::Sprite *_body;
	cocos2d::Sprite *_shadow;
	cocos2d::Sprite *_flame;
	cocos2d::Point _enemyPt;
	cocostudio::timeline::ActionTimeline *_triAction;
};


#endif // !__CENEMY_H__