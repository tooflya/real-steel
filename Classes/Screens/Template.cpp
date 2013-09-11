/**
 * Tooflya Inc. Development
 * @file Template.cpp
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

#ifndef CONST_TEMPLATE
#define CONST_TEMPLATE

#include "Template.h"

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

Template::~Template()
{

}

Template::Template()
{

}

Template* Template::create()
{
  Template* screen = new Template();
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

void Template::update(float pDeltaTime)
{
  Screen::update(pDeltaTime);
}

void Template::onEnter()
{
  Screen::onEnter();
}

void Template::onExit()
{
  Screen::onExit();
}

#endif