/**
 * Tooflya Inc. Development
 * @file Entity.cpp
 * @category cpp file
 *
 * @author Igor Mats from Tooflya Inc.
 * @copyright (c) 2013 by Igor Mats
 *
 * @license http://opensource.org/licenses/gpl-license.php GNU Public License v2
 * @all rights granted under this License are granted for the term of
 * copyright on the Program, and are irrevocable provided the stated
 * conditions are met. This License explicitly affirms your unlimited
 * permission to run the unmodified Program. The output from running a
 * covered work is covered by this License only if the output, given its
 * content, constitutes a covered work. This License acknowledges your
 * rights of fair use or other equivalent, as provided by copyright law.
 *
 * @version
 *
 */

#ifndef CONST_ENTITY
#define CONST_ENTITY

#include "Entity.h"

#include "EntityManager.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Entity::~Entity()
{
}

void Entity::constructor(const char* pszFileName, CCNode* pParent)
{
  this->mTextureFileName = pszFileName;

  CCSpriteFrame *pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(this->mTextureFileName);

  if(pFrame == NULL)
  {
    this->initWithFile(this->mTextureFileName);
  }
  else
  {
    this->initWithSpriteFrame(pFrame);
  }
  
  if(pParent)
  {
    pParent->addChild(this);
  }

  this->mWidth =  (pFrame == NULL ? this->getTextureRect().size.width : pFrame->getRect().size.width);
  this->mHeight = (pFrame == NULL ? this->getTextureRect().size.height : pFrame->getRect().size.height);

  this->mPaddingX = (pFrame == NULL ? 0 : pFrame->getRect().origin.x);
  this->mPaddingY = (pFrame == NULL ? 0 : pFrame->getRect().origin.y);

  this->mWasTouched = false;

  this->setAnchorPoint(ccp(0.5f, 0.5f));

  this->mIsCascadeOpacity = false;

  this->id = -1;

  this->destroy();
}

Entity::Entity(const char* pszFileName)
{
  this->constructor(pszFileName, NULL);
}

Entity::Entity(const char* pszFileName, CCNode* pParent)
{
  this->constructor(pszFileName, pParent);
}

Entity* Entity::create(const char* pszFileName)
{
  Entity* entity = new Entity(pszFileName);
  entity->autorelease();
  
  return entity;
}

Entity* Entity::create(const char* pszFileName, CCNode* pParent)
{
  Entity* entity = new Entity(pszFileName, pParent);
  entity->autorelease();
  
  return entity;
}

// ===========================================================
// Methods
// ===========================================================

void Entity::setId(int pId)
{
  this->id = pId;
}

float Entity::getWidth()
{
  return this->getContentSize().width;
}

float Entity::getHeight()
{
  return this->getContentSize().height;
}

float Entity::getWidthScaled()
{
  return this->getWidth() * this->getScaleX();
}

float Entity::getHeightScaled()
{
  return this->getContentSize().height * this->getScaleY();
}

float Entity::getX()
{
  return this->getPosition().x - this->getWidth() / 2;
}

float Entity::getY()
{
  return this->getPosition().y + this->getHeight() / 2;
}

float Entity::getCenterX()
{
  return this->getPosition().x;
}

float Entity::getCenterY()
{
  return this->getPosition().y;
}

float Entity::getCenterPosition()
{
  return 0; // TODO: Write this method
}

void Entity::setX(float pX)
{
  // TODO: Write this method
}

void Entity::setY(float pY)
{
  // TODO: Write this method
}

void Entity::setPosition(float pX, float pY)
{
  CCSprite::setPosition(ccp(pX - this->getWidth() / 2, pY + this->getHeight() / 2));
}

void Entity::setCenterPosition(float pX, float pY)
{
  CCSprite::setPosition(ccp(pX, pY));
}

void Entity::create()
{
  this->setVisible(true);
  this->onCreate();
}

void Entity::destroy()
{
  if(this->id >= 0)
  {
    static_cast<EntityManager<Entity*>*>(this->mManager)->destroy(this->id);
  }

  this->setVisible(false);
  this->onDestroy();
}

Entity* Entity::deepCopy()
{
  return Entity::create(this->mTextureFileName);
}

void Entity::setManager(CCArray* pManager)
{
  this->mManager = pManager;
}

void Entity::onTouch(CCTouch* touch, CCEvent* event)
{
  this->destroy();
}

void Entity::onCreate()
{
}

void Entity::onDestroy()
{
}

// ===========================================================
// Override Methods
// ===========================================================

void Entity::update(float pDeltaTime)
{
  CCSprite::update(pDeltaTime);
}

void Entity::draw()
{
  CCSprite::draw();
}

void Entity::onEnter()
{
  CCSprite::onEnter();

  this->scheduleUpdate();
}

void Entity::onExit()
{
  CCSprite::onExit();

  this->unscheduleAllSelectors();

  if(this->mIsTouchable)
  {
    this->disable();
  }
}

bool Entity::containsTouchLocation(CCTouch* touch)
{
  return CCRectMake(-this->mWidth/ 2, -this->mHeight / 2, this->mWidth, this->mHeight).containsPoint(this->convertTouchToNodeSpaceAR(touch)) && this->isVisible();
}

void Entity::setOpacity(GLubyte pOpaquee)
{
  CCSprite::setOpacity(pOpaquee);

  if(this->mIsCascadeOpacity)
  {
    for(unsigned int i = 0; i < this->getChildrenCount(); i++)
    {
      Entity* child = static_cast<Entity*>(this->getChildren()->objectAtIndex(i));

      child->setOpacity(pOpaquee);
    }
  }
}

#endif