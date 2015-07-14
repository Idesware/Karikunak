#include "nivel1.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace ui;

Scene* nivel1::createScene()
{
    // 'scene' is an autorelease object
    auto scene_nivel1 = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = nivel1::create();

    // add layer as a child to scene
    scene_nivel1->addChild(layer);

    // return the scene
    return scene_nivel1;
}

// on "init" you need to initialize your instance
bool nivel1::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
   
	//Cargar la ecena creada en cocos2d estudio
	Node *rootNode = CSLoader::createNode("intro.csb");
    addChild(rootNode);




	return true;

}

