/**
 * Tooflya Inc. Development
 * @file Screen.cpp
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

#ifndef CONST_SCREEN
#define CONST_SCREEN

#include "Screen.h"

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

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Screen::~Screen()
{
  this->removeAllChildrenWithCleanup(true);
}

Screen::Screen()
{
}

// ===========================================================
// Getters
// ===========================================================

// ===========================================================
// Setters
// ===========================================================

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

bool Screen::containsTouchLocation(CCTouch* touch)
{
  return true;
}

void Screen::onEnter()
{
  CCScene::onEnter();

  this->scheduleUpdate();
}

void Screen::onExit()
{
  CCScene::onExit();

  this->stopAllActions();
  this->unscheduleAllSelectors();

  this->release();
}

#endif