/**
 * Tooflya Inc. Development
 * @file Loader.cpp
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

#ifndef CONST_LOADER
#define CONST_LOADER

#include "Loader.h"

#include "AppDelegate.h"
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

Loader::~Loader()
{
  CCLog("Loader screen was deleted.");
}

Loader::Loader()
{
  this->mVersionText = Text::create(Options::VERSION, 16, this);
  this->mLoadingText = Text::create("", 32, this);

  this->mVersionText->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(30), Utils::coord(20));
  this->mLoadingText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(100));

  this->mIsLoadingAnimationRunning = false;
}

Loader* Loader::create()
{
  Loader* screen = new Loader();
  screen->autorelease();
  screen->retain();

  return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Loader::onLoadingFinish()
{
  AppDelegate::sharedScreenManager()->generate();
}

// ===========================================================
// Virtual Methods
// ===========================================================

void Loader::update(float pDeltaTime)
{
  Screen::update(pDeltaTime);

  if(this->mIsLoadingAnimationRunning)
  {
    this->mLoadingText->setString(ccsf("%d%s", ++this->mPercentageLoaded, "%"));

    if(this->mPercentageLoaded >= 100)
    {
      this->mIsLoadingAnimationRunning = false;

      this->onLoadingFinish();
    }
  }
}

void Loader::onEnter()
{
  Screen::onEnter();

  this->mPercentageLoaded = 0;

  this->mIsLoadingAnimationRunning = true;
}

void Loader::onExit()
{
  Screen::onExit();
}

#endif