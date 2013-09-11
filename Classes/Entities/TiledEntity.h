/**
 * Tooflya Inc. Development
 * @file TiledEntity.h
 * @category header file
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

#ifndef CONST_TILEDENTITY_H
#define CONST_TILEDENTITY_H

#include "Entity.h"

class TiledEntity : public Entity
{
  protected:
  // ===========================================================
  // Inner Classes
  // ===========================================================

  // ===========================================================
  // Constants
  // ===========================================================

  // ===========================================================
  // Fields
  // ===========================================================

  int mFramesCount;

  int mCurrentFrameIndex;

  int mHorizontalFramesCount;
  int mVerticalFramesCount;

  float mFrameWidth;
  float mFrameHeight;

  float* mFramesCoordinatesX;
  float* mFramesCoordinatesY;

  // ===========================================================
  // Constructors
  // ===========================================================

  TiledEntity(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount);
  TiledEntity(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount, CCNode* pParent);

  // ===========================================================
  // Methods
  // ===========================================================

  // ===========================================================
  // Override Methods
  // ===========================================================

  void constructor(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount, CCNode* pParent);

  private:
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

  public:
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

  static TiledEntity* create(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount);
  static TiledEntity* create(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount, CCNode* pParent);

  ~TiledEntity();

  // ===========================================================
  // Methods
  // ===========================================================

  int getCurrentFrameIndex();

  void nextFrameIndex();
  void previousFrameIndex();

  void setCurrentFrameIndex(int pIndex);

  // ===========================================================
  // Override Methods
  // ===========================================================

  void create();
  void destroy();

  TiledEntity* deepCopy();
};

#endif