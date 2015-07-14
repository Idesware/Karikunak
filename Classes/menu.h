#ifndef __MENU_H__
#define __MENU_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class menu : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
		// implement the "static create()" method manually
    CREATE_FUNC(menu);
};

#endif // 