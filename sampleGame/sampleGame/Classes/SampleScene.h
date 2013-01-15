#ifndef __SAMPLE_SCENE_H__
#define __SAMPLE_SCENE_H__

#include "cocos2d.h"

class Sample : public cocos2d::CCLayer
{
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();

    // Create a virtual destructor in which we release retained objects.
    virtual ~Sample();

    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);

    void loadBackground(void);

    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(Sample);

private:
  cocos2d::CCTMXTiledMap*   tileMap;
  cocos2d::CCTMXLayer*      background;

};

#endif // __SAMPLE_SCENE_H__
