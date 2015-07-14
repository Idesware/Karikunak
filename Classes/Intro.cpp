#include "Intro.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"
#include "menu.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* Intro::createScene()
{
    // 'scene' is an autorelease object
    auto scene_intro = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = Intro::create();

    // add layer as a child to scene
    scene_intro->addChild(layer);

    // return the scene
    return scene_intro;
}

// on "init" you need to initialize your instance
bool Intro::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
//cargo el escenario realizado en cocos2d studio    
    auto rootNode = CSLoader::createNode("intro.csb");
    addChild(rootNode);

//poner sonido a la escena
    //CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(
    //"culebra.mp3", false);
//poner un timer para que cuando se termine el intro cambie automaticamente al menu del juego
	this->schedule(schedule_selector(Intro::updatetimer), 8.0f);
    return true;
}

void Intro::updatetimer(float dt)
{
	auto scene_menu = menu::createScene();
    Director::getInstance()->replaceScene(scene_menu);	
}
