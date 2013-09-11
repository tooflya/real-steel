/**
 * Tooflya Inc. Development
 * @file TiledEntity.cpp
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

#ifndef CONST_TILEDENTITY
#define CONST_TILEDENTITY

#include "TiledEntity.h"

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

TiledEntity::~TiledEntity()
{
}

void TiledEntity::constructor(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount, CCNode* pParent) 
{
  Entity::constructor(pszFileName, pParent);

  this->mFrameWidth = this->mWidth / pHorizontalFramesCount;
  this->mFrameHeight = this->mHeight / pVerticalFramesCount;

  this->mFramesCount = pHorizontalFramesCount * pVerticalFramesCount;

  this->mHorizontalFramesCount = pHorizontalFramesCount;
  this->mVerticalFramesCount   = pVerticalFramesCount;

  /**
   *
   * We must remember all coordinates of each frame
   * for quick get x and y of it.
   *
   */

  this->mFramesCoordinatesX = new float[this->mFramesCount];
  this->mFramesCoordinatesY = new float[this->mFramesCount];

  int counter = 0;

  for(int i = 0; i < this->mVerticalFramesCount; i++)
  {
    for(int j = 0; j < this->mHorizontalFramesCount; j++, counter++)
    {
      this->mFramesCoordinatesX[counter] = j * (this->mWidth / this->mHorizontalFramesCount) + this->mPaddingX;
      this->mFramesCoordinatesY[counter] = i * (this->mHeight / this->mVerticalFramesCount) + this->mPaddingY;
    }
  }

  /**
   *
   * Setting zero frame
   *
   */

  this->setCurrentFrameIndex(0);
}

TiledEntity::TiledEntity(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount) :
Entity(pszFileName)
{
  this->constructor(pszFileName, pHorizontalFramesCount, pVerticalFramesCount, NULL);
}

TiledEntity::TiledEntity(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount, CCNode* pParent) :
Entity(pszFileName)
{
  this->constructor(pszFileName, pHorizontalFramesCount, pVerticalFramesCount, pParent);
}

TiledEntity* TiledEntity::create(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount)
{
  TiledEntity* entity = new TiledEntity(pszFileName, pHorizontalFramesCount, pVerticalFramesCount);
  entity->autorelease();

  return entity;
}

TiledEntity* TiledEntity::create(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount, CCNode* pParent)
{
  TiledEntity* entity = new TiledEntity(pszFileName, pHorizontalFramesCount, pVerticalFramesCount, pParent);
  entity->autorelease();

  return entity;
}

// ===========================================================
// Methods
// ===========================================================

int TiledEntity::getCurrentFrameIndex()
{
  return this->mCurrentFrameIndex;
}

void TiledEntity::setCurrentFrameIndex(int pIndex)
{
  if(pIndex < this->mFramesCount && pIndex >= 0)
  {
    this->setTextureRect(CCRectMake(this->mFramesCoordinatesX[pIndex], this->mFramesCoordinatesY[pIndex], this->mWidth / this->mHorizontalFramesCount, this->mHeight / this->mVerticalFramesCount));

    this->mCurrentFrameIndex = pIndex;
  }
  else
  {
    this->setCurrentFrameIndex(0);
  }
}

void TiledEntity::previousFrameIndex()
{
  int potencialNextFrame = this->getCurrentFrameIndex() - 1;

  this->setCurrentFrameIndex(potencialNextFrame > 0 ? potencialNextFrame : 0);
}

void TiledEntity::nextFrameIndex()
{
  int potencialNextFrame = this->getCurrentFrameIndex() + 1;

  this->setCurrentFrameIndex(potencialNextFrame > this->mFramesCount ? 0 : potencialNextFrame);
}

// ===========================================================
// Override Methods
// ===========================================================

void TiledEntity::create()
{
  Entity::create();
}

void TiledEntity::destroy()
{
  Entity::destroy();
}

TiledEntity* TiledEntity::deepCopy()
{
  return TiledEntity::create(this->mTextureFileName, this->mHorizontalFramesCount, this->mVerticalFramesCount);
}

#endif