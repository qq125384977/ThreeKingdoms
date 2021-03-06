#include "HelloWorldScene.h"
#include "tools/GameCommon.h"
#include "tools/ButtonUtils.h"
#include "tools/GameUtils.h"
#include "AnimateManager.h"
#include "CreateCharacterScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto size = Director::getInstance()->getWinSize();
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    //this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    //this->addChild(sprite, 0);

	//ControlButton *button = standardButtonWithTitle("fengzhu");
    //button->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    //this->addChild(button);

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("common.plist");
	//auto my_sp = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("common_backBtn.png"));
    //my_sp->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	//this->addChild(my_sp);


	auto backBtn = INSTANCE(ButtonUtils)->createButton("common_setBtn.png",Size(75,81),"");
    backBtn->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	//this->addChild(backBtn);
	
	//INSTANCE(AnimateManager)->showScaleAnimate(backBtn);
    
	for (int i = 0;i< 10;i++)
	{
		//log("%d",INSTANCE(GameUtils)->getRandom(5));
	}

	scheduleUpdate();

	//auto eventNode = Node::create();
	auto eventNode = Sprite::create("CloseNormal.png");
	this->addChild(eventNode);
    eventNode->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	eventNode->setColor(Color3B::WHITE);
	//eventNode->setContentSize(Size(backBtn->getContentSize()));
	log("%f,%f",eventNode->getContentSize().width,eventNode->getContentSize().height);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [](Touch* touch,Event* event){
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);

		if (rect.containsPoint(locationInNode))
		{
			log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
			target->setOpacity(180);
			return true;
		}
		return false;
	};
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, eventNode);

	//auto containerForSprite1 = Node::create();
    //auto sprite1 = Sprite::create("CyanSquare.png");
    //sprite1->setPosition(origin+Vec2(size.width/2, size.height/2) + Vec2(-80, 80));
    //containerForSprite1->addChild(sprite1);
    //addChild(containerForSprite1, 10);
    
    //auto sprite2 = Sprite::create("MagentaSquare.png");
    //sprite2->setPosition(origin+Vec2(size.width/2, size.height/2));
    //addChild(sprite2, 20);
    
    //auto sprite3 = Sprite::create("YellowSquare.png");
    //sprite3->setPosition(Vec2(0, 0));
    //sprite2->addChild(sprite3, 1);
    
    //// Make sprite1 touchable
    //auto listener1 = EventListenerTouchOneByOne::create();
    //listener1->setSwallowTouches(true);
    
    //listener1->onTouchBegan = [](Touch* touch, Event* event){
    //    auto target = static_cast<Sprite*>(event->getCurrentTarget());
    //    
    //    Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
    //    Size s = target->getContentSize();
    //    Rect rect = Rect(0, 0, s.width, s.height);
    //    
    //    if (rect.containsPoint(locationInNode))
    //    {
    //        log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
    //        target->setOpacity(180);
    //        return true;
    //    }
    //    return false;
    //};
    
    //listener1->onTouchMoved = [](Touch* touch, Event* event){
    //    auto target = static_cast<Sprite*>(event->getCurrentTarget());
    //    target->setPosition(target->getPosition() + touch->getDelta());
    //};
    
    //listener1->onTouchEnded = [=](Touch* touch, Event* event){
    //    auto target = static_cast<Sprite*>(event->getCurrentTarget());
    //    log("sprite onTouchesEnded.. ");
    //    target->setOpacity(255);
    //    if (target == sprite2)
    //    {
    //        containerForSprite1->setLocalZOrder(100);
    //    }
    //    else if(target == sprite1)
    //    {
    //        containerForSprite1->setLocalZOrder(0);
    //    }
    //};
    
    //_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, sprite1);
    //_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), sprite2);
    //_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), sprite3);
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Director::getInstance()->end();
	Director::getInstance()->replaceScene(CreateCharacterScene::createScene());

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

ControlButton* HelloWorld::standardButtonWithTitle(const char* title)
{
	/** Creates and return a button with a default background and title color. */
    auto backgroundButton = cocos2d::extension::Scale9Sprite::create("button.png");
    auto backgroundHighlightedButton = cocos2d::extension::Scale9Sprite::create("buttonHighlighted.png");
    
    auto titleButton = Label::createWithTTF(title, "fonts/Marker Felt.ttf", 30);

    titleButton->setColor(Color3B(159, 168, 176));
    
    ControlButton *button = ControlButton::create(titleButton, backgroundButton);
    button->setBackgroundSpriteForState(backgroundHighlightedButton, Control::State::HIGH_LIGHTED);
    button->setTitleColorForState(Color3B::WHITE, Control::State::HIGH_LIGHTED);

    return button;
}

void HelloWorld::update(float dt)
{
	//log("update");
}
