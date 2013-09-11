/**
 * Tooflya Inc. Development
 * @file ScreenManager.cpp
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

#ifndef CONST_SCREENMANAGER
#define CONST_SCREENMANAGER

#include "ScreenManager.h"

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

ScreenManager::~ScreenManager()
{
}

ScreenManager::ScreenManager()
{
}

ScreenManager* ScreenManager::create()
{
  ScreenManager* manager = new ScreenManager();
  manager->autorelease();
  manager->retain();

  return manager;
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
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

void ScreenManager::set(int pIndex)
{
  this->mCurrentScreenIndex = pIndex;

  CCDirector::sharedDirector()->replaceScene(this->mScreens[pIndex]);
}

// ===========================================================
// Virtual methods
// ===========================================================

#endif