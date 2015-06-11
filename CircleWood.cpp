//
//  CircleWood.cpp
//  angaryBirds
//
//  Created by student on 15/5/27.
//
//

#include "CircleWood.h"
CircleWood* CircleWood::createCircleWood()
{
    CircleWood* cirl=new CircleWood();
    if(cirl)
    {
        cirl->autorelease();
        return cirl;
    }
    return nullptr;
}
void CircleWood::initCircleWood(Point _p)
{
    this->initWithFile("maingame/circlewood1.png");
    this->xueliang=180;
    this->score=1500;
    this->setPosition(_p);
    Rect vec=this->getBoundingBox();
    
    Vec2 vec1[]={Vec2(-vec.size.width/2/2,-vec.size.height/2),Vec2(-vec.size.width/2,-vec.size.height/2/2),Vec2(-vec.size.width/2,vec.size.height/2/2),Vec2(-vec.size.width/2/2,vec.size.height/2),Vec2(vec.size.width/2/2,vec.size.height/2),Vec2(vec.size.width/2,vec.size.height/2/2),Vec2(vec.size.width/2,-vec.size.height/2/2),Vec2(vec.size.width/2/2,-vec.size.height/2)};
    
    
    PhysicsBody* body=PhysicsBody::createPolygon(vec1, 8);
    body->setDynamic(true);
    this->setPhysicsBody(body);
}
void CircleWood::startAnimation()
{
    auto animation=Animation::create();
    animation->setDelayPerUnit(0.3);
    animation->addSpriteFrameWithFileName("maingame/circlewood1.png");
    animation->addSpriteFrameWithFileName("maingame/circlewood2.png");
    animation->addSpriteFrameWithFileName("maingame/circlewood3.png");
    animation->addSpriteFrameWithFileName("maingame/circlewood4.png");
    auto animate=Animate::create(animation);
    auto repeat=RepeatForever::create(animate);
    this->runAction(repeat);
}