#include "SampleScene.h"
#include "SimpleAudioEngine.h"
#include "Constants.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* Sample::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Sample *layer = Sample::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

Sample::~Sample() {
    // Remove the tile map, which should cause it to be freed at the end of the
    // current frame.
    if (this->tileMap) {
        this->removeChild(this->tileMap);
    }
}

///////////////////////////////////////////////////////////////////////////////
void Sample::loadBackground(void) {
    this->tileMap = NULL;
    this->background = NULL;

    // Load the tile map.    
    this->tileMap = cocos2d::CCTMXTiledMap::create("sample_dungeon.tmx");

    if (this->tileMap) {
        this->background = this->tileMap->layerNamed("Background");
        if (this->background) {
            this->addChild(this->tileMap);
        }
    }
}

// on "init" you need to initialize your instance
bool Sample::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(Sample::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // Load the background tiles.
    this->loadBackground();

    // add a label shows "Hello World"
    // create and initialize a label
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Thonburi", 34);

    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    // Scale ourselves to fit the current screen.
    this->setScaleX(size.width / WIDTH_F);
    this->setScaleY(size.height / HEIGHT_F);

    // position the label on the center of the screen
    pLabel->setPosition( ccp(size.width / 2, size.height - 20) );

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "Sample" splash screen"
    CCSprite* pSprite = CCSprite::create("dg_classm32.png", CCRectMake(0, 0, 32, 32));

    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width/2, size.height/2) );

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    return true;
}

void Sample::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
