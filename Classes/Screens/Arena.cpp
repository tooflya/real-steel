/**
 * Tooflya Inc. Development
 * @file Arena.cpp
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

#ifndef CONST_ARENA
#define CONST_ARENA

#include "Arena.h"

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

Arena::~Arena()
{
  CCLog("Arena screen was deleted.");
}

Arena::Arena()
{

}

Arena* Arena::create()
{
  Arena* screen = new Arena();
  screen->autorelease();
  screen->retain();

  return screen;
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

void Arena::update(float pDeltaTime)
{
  Screen::update(pDeltaTime);
}

void Arena::onEnter()
{
  Screen::onEnter();
}

void Arena::onExit()
{
  Screen::onExit();
}

#endif