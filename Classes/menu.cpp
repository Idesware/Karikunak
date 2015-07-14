#include "menu.h"
#include "nivel1.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace ui;

Scene* menu::createScene()
{
    // 'scene' is an autorelease object
    auto scene_menu = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = menu::create();

    // add layer as a child to scene
    scene_menu->addChild(layer);

    // return the scene
    return scene_menu;
}

// on "init" you need to initialize your instance
bool menu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
   
//Cargar la ecena creada en cocos2d estudio
	Node *rootNode = CSLoader::createNode("menu.csb");
    addChild(rootNode);

//poner musica en el menu
    //CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(
    //"menu.mp3", true);

//obtener el boton creado en cocos2d studio para utilizarlo
	auto children = utils::findChildren(*rootNode, "//btn_empezar");
	auto btn = (Button*)children.front();

//poner una accion al boton cuando es precionado	
		btn->addClickEventListener([](Ref *) 
		{
           auto scene_nivel1 = nivel1::createScene();   
		   Director::getInstance()->pushScene(scene_nivel1);   
       });
   

	return true;

}
