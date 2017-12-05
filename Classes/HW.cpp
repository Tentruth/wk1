#include "HW.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Runner.h"
#include "C3SButton.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace ui;
using namespace CocosDenshion;
bool Start = false;
int HP = 5;
float iScore = 0;
bool initstge = false;
int _Nojump = false;

Scene* HW::createScene() 
{
	auto scene = Scene::create();
	auto layer = HW::create();
	scene->addChild(layer);
	return scene;
}

HW::~HW()
{

	AnimationCache::destroyInstance();  // ���� AnimationCache ���o���귽
	SpriteFrameCache::getInstance()->removeUnusedSpriteFrames();
	Director::getInstance()->getTextureCache()->removeUnusedTextures();
}

bool HW::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	if (!Layer::init())
	{
		return false;
	}
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("scene101.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Runner.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("retrybtn.plist");
//-----------------------------------------------------------------------------------------------------------------------------------------------------
		auto rootNode = CSLoader::createNode("MainScene.csb");
		addChild(rootNode);
		auto text = (cocos2d::ui::Text *)rootNode->getChildByName("startgame");
		auto bkmusic = (cocostudio::ComAudio *)rootNode->getChildByName("BG")->getComponent("BG");
		bkmusic->playBackgroundMusic();
		Start = false;
//-----------------------------------------------------------------------------------------------------------------------------------------------------
	_listener1 = EventListenerTouchOneByOne::create();
	_listener1->onTouchBegan = CC_CALLBACK_2(HW::onTouchBegan, this);
	_listener1->onTouchMoved = CC_CALLBACK_2(HW::onTouchMoved, this);
	_listener1->onTouchEnded = CC_CALLBACK_2(HW::onTouchEnded, this);
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener1, this);
	return true;

}

bool HW::ChooseCharater()
{

	return false;
}


bool HW::stage1()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	if (!Layer::init())
	{
		return false;
	}
	//�D����
	auto rootNode = CSLoader::createNode("Scene.csb");
	addChild(rootNode);
	//�I������
	auto bkmusic = (cocostudio::ComAudio *)rootNode->getChildByName("BG")->getComponent("BG");
	bkmusic->playBackgroundMusic();
	//������J
	runner = RunnerNode::create();
	enemy = CEnemy::create();
	runner->SetNodeInfo("CircleNode.csb",this);
	runner->setPosition(visibleSize.width / 2.0f + 300, visibleSize.height / 2.0f);
	enemy->SetNodeInfo("enemyNode.csb");
	//�I���u���J
	auto _BGLN = CSLoader::createNode("BGLM.csb");
	_BGLN->setPosition(visibleSize.width / 2.0f, visibleSize.height / 2.0f);
	rootNode->addChild(_BGLN);
	//auto _BGLN1 = (cocos2d::Sprite *)_BGLN->getChildByName("s101line01_1");
	//auto BGLNcache = AnimationCache::getInstance();
	//BGLNcache->addAnimationsWithFile("BGLN.plist");
	//auto animation = BGLNcache->getAnimation("movingline");
	//auto _action4 = RepeatForever::create(Animate::create(animation));
	//_BGLN1->runAction(cocos2d::Sequence::create(_action4,NULL));
//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//���ƪ�l��
	iScore = 0;
	Score = (cocos2d::ui::TextBMFont *)rootNode->getChildByName("Stage1Score");
	Score->setString(StringUtils::format("%2.0f", iScore));
	//����v�l
	shadow = (Sprite *)rootNode->getChildByName("shadow");
	shadow->setVisible(true);
	Countdown = (cocos2d::ui::TextBMFont *)rootNode->getChildByName("Countdown");
	//���s
	replaybtn = C3SButton::create();
	replaybtn->setButtonInfo("replaybtnOFF.png","replaybtn.png","replaybtnPRESS.png", Point(-125.0f + (visibleSize.width + 1300) / 2.0f, (visibleSize.height + 600) / 2.0f));
	Quit = C3SButton::create();
	Quit->setButtonInfo("cuberbtn3.png","cuberbtn1.png","cuberbtn2.png",Point(-125.0f + (visibleSize.width + 900) / 2.0f, (visibleSize.height + 600) / 2.0f));
	this->addChild(replaybtn, 2);
	this->addChild(enemy);
	this->addChild(Quit, 2);
	//���]HP
	HP = 5;
	HW::CountHP();
	HW::doStep(0);
	//�ʵe���J
	runner->setAnimation("CircleRunner.plist");
	runner->go();
	enemy->setAnimation();
	SimpleAudioEngine::getInstance()->preloadEffect("thinking cloud.mp3");

//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//��L
	_listener1 = EventListenerTouchOneByOne::create();
	_listener1->onTouchBegan = CC_CALLBACK_2(HW::onTouchBegan, this);
	_listener1->onTouchMoved = CC_CALLBACK_2(HW::onTouchMoved, this);
	_listener1->onTouchEnded = CC_CALLBACK_2(HW::onTouchEnded, this);
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener1, this);	//�[�J��Ыت��ƥ��ť��
	this->schedule(CC_SCHEDULE_SELECTOR(HW::doStep));
	return true;
}

bool HW::Gameover()
{
	SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	auto gameoverNode = CSLoader::createNode("Gameover.csb");
	addChild(gameoverNode);
	FScore = (cocos2d::ui::TextBMFont *)gameoverNode->getChildByName("iScore");
	FScore->setString(StringUtils::format("%2.0f", iScore));
	return true;
}

bool HW::Crash()
{
	HW::CountHP();
	return true;
}

void HW::replaystage()
{
		initstge = true;
		iScore = 0;
	Score->setString(StringUtils::format("%2.0f", iScore));
		HP = 5;
		HW::CountHP();
		HW::doStep(0);
		initstge = false;

}

bool HW::onTouchBegan(cocos2d::Touch*pTouch, cocos2d::Event*pEvent) 
{
	Point touchLoc = pTouch->getLocation();
	if (Start == false)
	{
		Start = true;
		HW::stage1();
	}
	else if (Start == true) 
	{
		if (replaybtn->touchesBegan(touchLoc)&& !initstge)
		{
			replaybtn->touchesBegan(touchLoc);
		}
		else if(Quit->touchesBegan(touchLoc) && !initstge)
		{
			Quit->touchesBegan(touchLoc);
		}	
		else if(!initstge){
			runner->jump();
			unsigned int eid = SimpleAudioEngine::getInstance()->playEffect("thinking cloud.mp3", false);  // ���񭵮���
			iScore = iScore + 10;
			Score->setString(StringUtils::format("%2.0f", iScore));
		}
	
	}
	
	return true;
}

void HW::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) 
{
	Point touchLoc = pTouch->getLocation();
	if (replaybtn->touchesMoved(touchLoc) && !initstge)
	{
		replaybtn->touchesMoved(touchLoc);
	}
	else if (Quit->touchesMoved(touchLoc)&&!initstge)
	{
		Quit->touchesMoved(touchLoc);
	}
}
void HW::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) 
{
	Point touchLoc = pTouch->getLocation();
	if (replaybtn->touchesEnded(touchLoc) && !initstge)
	{
		replaybtn->touchesEnded(touchLoc);
		HW::replaystage();
	}
	else if (Quit->touchesEnded(touchLoc)&&!initstge)
	{
		Quit->touchesEnded(touchLoc);
		HW::Gameover();
	}
}

void HW::doStep(float dt)
{
	//int t = 0;
	//while (t <= 15)
	//{
	//	if (dt <= 15) {
	//		switch (t)
	//		{
	//		case 0:
	//			Countdown->setString(StringUtils::format("3"));
	//			t++;
	//			break;
	//		case 5:
	//			Countdown->setString(StringUtils::format("2"));
	//			t++;
	//			break;
	//		case 10:
	//			Countdown->setString(StringUtils::format("1"));
	//			t++;
	//			break;
	//		case 15:
	//			Countdown->setString(StringUtils::format("START"));
	//			t++;
	//			break;
	//		default:
	//			t++;
	//		}
	//	}
	//	else if (t>15)
	//	{
	//		Countdown->setVisible(false);
	//	}
	//}
	}

void HW::CountHP()
{
	switch (HP)
	{
	case(5) :

		break;
	case(4) :

		break;
	case(3) :

		break;
	case(2) :

		break;
	case(1) :

		break;
	case(0) :
		HW::Gameover();
		break;
	}

}
