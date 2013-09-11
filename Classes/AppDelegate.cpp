/**
 * Tooflya Inc. Development
 * @file AppDelegate.cpp
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

#ifndef CONST_APPDELEGATE
#define CONST_APPDELEGATE

#include "AppDelegate.h"

#include "Loader.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

ScreenManager* AppDelegate::mSharedScreenManager = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

// ===========================================================
// Methods
// ===========================================================

ScreenManager* AppDelegate::sharedScreenManager()
{
  return mSharedScreenManager;
}

// ===========================================================
// Override Methods
// ===========================================================

bool AppDelegate::applicationDidFinishLaunching()
{
  CCDirector* director = CCDirector::sharedDirector();
  CCEGLView* EGLView = CCEGLView::sharedOpenGLView();
  CCSize  screenSize = EGLView->getFrameSize();

  director->setOpenGLView(EGLView);
  director->setContentScaleFactor(designResolutionSize.height / screenSize.height);

  vector <string> searchPath;

  searchPath.push_back(resources800x600.directory);

  CCFileUtils::sharedFileUtils()->setSearchPaths(searchPath);

  mSharedScreenManager = ScreenManager::create();

  Options::SCREEN_WIDTH = designResolutionSize.width;
  Options::SCREEN_HEIGHT = designResolutionSize.height;

  Options::SCREEN_CENTER_X = designResolutionSize.width / 2;
  Options::SCREEN_CENTER_Y = designResolutionSize.height / 2;

  Options::CAMERA_WIDTH = screenSize.width;
  Options::CAMERA_HEIGHT = screenSize.height;

  Options::CAMERA_CENTER_X = screenSize.width / 2;
  Options::CAMERA_CENTER_Y = screenSize.height / 2;

  director->setAlphaBlending(false);
  director->setDepthTest(false);

  director->setDisplayStats(true);

  director->setProjection(kCCDirectorProjection2D);

  director->setAnimationInterval(1.0f / 60.0f);

  director->runWithScene(Loader::create());

  return true;
}

void AppDelegate::applicationDidEnterBackground()
{
  CCDirector::sharedDirector()->stopAnimation();
  CCDirector::sharedDirector()->pause();

  SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

void AppDelegate::applicationWillEnterForeground()
{
  CCDirector::sharedDirector()->stopAnimation();
  CCDirector::sharedDirector()->resume();
  CCDirector::sharedDirector()->startAnimation();

  SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}

#endif