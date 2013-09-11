/**
 * Tooflya Inc. Development
 * @file AnimatedEntity.h
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

#ifndef CONST_ANIMATEDENTITY_H
#define CONST_ANIMATEDENTITY_H

#include "TiledEntity.h"

class AnimatedEntity : public TiledEntity
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

  bool mIsAnimationRunning;

  float mAnimationTime;
  float mAnimationTimeElapsed;

  // ===========================================================
  // Constructors
  // ===========================================================

  AnimatedEntity(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount);
  AnimatedEntity(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount, CCNode* pParent);

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

  static AnimatedEntity* create(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount);
  static AnimatedEntity* create(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount, CCNode* pParent);

  ~AnimatedEntity();

  // ===========================================================
  // Methods
  // ===========================================================

  bool isAnimationRunning();

  void animate(float pAnimationTime);

  // ===========================================================
  // Override Methods
  // ===========================================================

  void update(float pDeltaTime);

  AnimatedEntity* deepCopy();
};

#endif