#include "C3SButton.h"

USING_NS_CC;

C3SButton * C3SButton::create()
{
	C3SButton *btnobj = new (std::nothrow) C3SButton();
	if (btnobj)
	{
		btnobj->autorelease();
		return btnobj;
	}
	CC_SAFE_DELETE(btnobj);
	return nullptr;
}

C3SButton::C3SButton() 
{
	_SwitchOffPic = nullptr;
	_SwitchTDPic = nullptr;
	_SwitchOnPic = nullptr;
}



void C3SButton::setButtonInfo(const char * offImg, const char * onImg, const char * tdImg, const cocos2d::Point locPt)
{

	_SwitchOffPic = (Sprite *)Sprite::createWithSpriteFrameName(offImg);
	_SwitchTDPic = (Sprite *)Sprite::createWithSpriteFrameName(tdImg);
	_SwitchOnPic = (Sprite *)Sprite::createWithSpriteFrameName(onImg);

	_BtnLoc = locPt;
	_SwitchOffPic->setPosition(_BtnLoc); // 設定位置
	_SwitchTDPic->setPosition(_BtnLoc); // 設定位置
	_SwitchOnPic->setPosition(_BtnLoc); // 設定位置
	_SwitchOffPic->setVisible(true);
	_SwitchTDPic->setVisible(false);
	_SwitchOnPic->setVisible(false);
	_SwitchTDPic->setScale(1.25f);
	
	this->addChild(_SwitchOffPic, 1);
	this->addChild(_SwitchTDPic, 1);
	this->addChild(_SwitchOnPic, 1);

	// 取得大小
	_BtnSize = _SwitchOffPic->getContentSize();
	// 設定判斷區域
	_BtnRect.size = _BtnSize;
	_BtnRect.origin.x = _BtnLoc.x - _BtnSize.width*0.5f;
	_BtnRect.origin.y = _BtnLoc.y - _BtnSize.height*0.5f;
	_bTouched = false;
	_fScale = 1.0f;
	_bVisible = true;
	_bSwitchOn = false;
	
}


bool C3SButton::touchesBegan(cocos2d::Point inPos)
{
	if (_BtnRect.containsPoint(inPos))
	{
		_bTouched = true;
		_SwitchOnPic->setVisible(false);
		_SwitchTDPic->setVisible(true);
		_SwitchOffPic->setVisible(false);
		return(true); // 有按在上面
	}
	return(false);
}

bool C3SButton::touchesMoved(cocos2d::Point inPos)
{
	if (_bTouched) { // 只有被按住的時候才處理
		if (!_BtnRect.containsPoint(inPos)) { // 手指頭位置離開按鈕
			_bTouched = false;		
				_SwitchOnPic->setVisible(true);
				_SwitchOffPic->setVisible(false);
				_SwitchTDPic->setVisible(false);
			return(false);
		}
		else
		{
			_SwitchOnPic->setVisible(false);
			_SwitchOffPic->setVisible(false);
			_SwitchTDPic->setVisible(true);
			return(true);
		}
			
	}
	return(false); // 事後再移到按鈕上將被忽略
}
//_bTouched = true;
//_SwitchOnPic->setVisible(false);
//_SwitchTDPic->setVisible(true);
//_SwitchOffPic->setVisible(false);
//return(true); // 有按在上面
bool C3SButton::touchesEnded(cocos2d::Point inPos)
{
	if (_bTouched) {
			_SwitchOnPic->setVisible(true);
			_SwitchTDPic->setVisible(false);
			_SwitchOffPic->setVisible(false);
		}
		_bTouched = false;

		if (_BtnRect.containsPoint(inPos)) return(true);  // 手指頭位置按鈕時，還在該按鈕上
	
	return false;
}

void C3SButton::setScale(float scale)
{
	_fScale = scale;
	_SwitchOnPic->setScale(_fScale);
	_SwitchTDPic->setScale(_fScale*1.25f);
	_SwitchOffPic->setScale(_fScale);
}

bool C3SButton::getStatus()
{
	return(_bSwitchOn);
}
