/**
 * Tooflya Inc. Development
 * @file AnimatedEntity.cpp
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

#ifndef CONST_ANIMATEDENTITY
#define CONST_ANIMATEDENTITY

#include "AnimatedEntity.h"

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

AnimatedEntity::~AnimatedEntity()
{
}

void AnimatedEntity::constructor(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount, CCNode* pParent) 
{
  TiledEntity::constructor(pszFileName, pHorizontalFramesCount, pVerticalFramesCount, pParent);

  this->mAnimationTime = 0;
  this->mAnimationTimeElapsed = 0;

  this->mIsAnimationRunning = false;
}

AnimatedEntity::AnimatedEntity(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount) :
TiledEntity(pszFileName, pHorizontalFramesCount, pVerticalFramesCount)
{
  this->constructor(pszFileName, pHorizontalFramesCount, pVerticalFramesCount, NULL);
}

AnimatedEntity::AnimatedEntity(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount, CCNode* pParent) :
TiledEntity(pszFileName, pHorizontalFramesCount, pVerticalFramesCount, pParent)
{
  this->constructor(pszFileName, pHorizontalFramesCount, pVerticalFramesCount, pParent);
}

AnimatedEntity* AnimatedEntity::create(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount)
{
  AnimatedEntity* entity = new AnimatedEntity(pszFileName, pHorizontalFramesCount, pVerticalFramesCount);
  entity->autorelease();
  
  return entity;
}

AnimatedEntity* AnimatedEntity::create(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount, CCNode* pParent)
{
  AnimatedEntity* entity = new AnimatedEntity(pszFileName, pHorizontalFramesCount, pVerticalFramesCount, pParent);
  entity->autorelease();
  
  return entity;
}

// ===========================================================
// Methods
// ===========================================================

void AnimatedEntity::animate(float pAnimationTime)
{
  this->mAnimationTime = pAnimationTime;

  this->mIsAnimationRunning = true;
}

// ===========================================================
// Override Methods
// ===========================================================

void AnimatedEntity::update(float pDeltaTime)
{
  TiledEntity::update(pDeltaTime);

  if(this->mIsAnimationRunning)
  {
    this->mAnimationTimeElapsed += pDeltaTime;

    if(this->mAnimationTimeElapsed >= this->mAnimationTime)
    {
      this->mAnimationTimeElapsed = 0;

      this->nextFrameIndex();
    }
  }
}

AnimatedEntity* AnimatedEntity::deepCopy()
{
  return AnimatedEntity::create(this->mTextureFileName, this->mHorizontalFramesCount, this->mVerticalFramesCount);
}

#endif