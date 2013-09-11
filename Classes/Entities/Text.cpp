/**
 * Tooflya Inc. Development
 * @file Text.cpp
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

#ifndef CONST_TEXT
#define CONST_TEXT

#include "Text.h"

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

Text::~Text()
{

}

Text::Text(const char* pString, float pSize, CCNode* pParent)
{
  this->initWithString(pString, Options::FONT, Utils::coord(pSize), CCSize(0, 0), kCCTextAlignmentLeft, kCCVerticalTextAlignmentTop);
  this->enableShadow();

  pParent->addChild(this);
}

Text* Text::create(const char* pString, float pSize, CCNode* pParent)
{
  Text* text = new Text(pString, pSize, pParent);
  text->autorelease();

  return text;
}

// ===========================================================
// Methods
// ===========================================================

void Text::setCenterPosition(float pCenterX, float pCenterY)
{
  this->mInitCenterX = pCenterX;
  this->mInitCenterY = pCenterY;

  CCLabelTTF::setPosition(ccp(pCenterX, pCenterY));
}

void Text::setPosition(float pX, float pY)
{
  this->mInitCenterX = pX + this->getWidth() / 2;
  this->mInitCenterY = pY - this->getHeight() / 2;

  CCLabelTTF::setPosition(ccp(pX - this->getWidth() / 2, pY + this->getHeight() / 2));
}

float Text::getWidth()
{
  return this->getContentSize().width;
}

float Text::getHeight()
{
  return this->getContentSize().height;
}

float Text::getCenterX()
{
  return this->getPosition().x;
}

float Text::getCenterY()
{
  return this->getPosition().y;
}

void Text::enableShadow()
{
  #if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

  CCLabelTTF::enableShadow(CCSize(Utils::coord(2), -Utils::coord(2)), 255.0, 0.0, true);

  #endif
}

void Text::disableShadow()
{
  #if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

  CCLabelTTF::disableShadow();

  #endif
}

// ===========================================================
// Override Methods
// ===========================================================

#endif