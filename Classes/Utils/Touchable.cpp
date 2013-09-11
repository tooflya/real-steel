/**
 * Tooflya Inc. Development
 * @file Touchable.cpp
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

#ifndef CONST_TOUCHABLE
#define CONST_TOUCHABLE

#include "Touchable.h"

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

Touchable::Touchable()
{
  this->mIsTouchable = false;
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

// ===========================================================
// Getters
// ===========================================================

// ===========================================================
// Setters
// ===========================================================

// ===========================================================
// Methods
// ===========================================================

void Touchable::enable()
{
  CCDirector* pDirector = CCDirector::sharedDirector();
  pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);

  this->mIsTouchable = true;
}

void Touchable::disable()
{
  CCDirector* pDirector = CCDirector::sharedDirector();
  pDirector->getTouchDispatcher()->removeDelegate(this);

  this->mIsTouchable = false;
}

void Touchable::onTouch(CCTouch* touch, CCEvent* event)
{
}

// ===========================================================
// Override Methods
// ===========================================================

bool Touchable::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
  if(!this->mIsTouchable)
  {
    return false;
  }

  if(this->containsTouchLocation(touch))
  {
    this->mWasTouched = true;

    return true;
  }

  return false;
}

void Touchable::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
  if(!this->containsTouchLocation(touch))
  {
    this->mWasTouched = false;
  }
}

void Touchable::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
  if(this->mWasTouched)
  {
    this->onTouch(touch, event);
  }

  this->mWasTouched = false;
}

bool Touchable::containsTouchLocation(CCTouch* touch)
{
  return false;
}

#endif