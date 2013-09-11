/**
 * Tooflya Inc. Development
 * @file Touchable.h
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

#ifndef CONST_TOUCHABLE_H
#define CONST_TOUCHABLE_H

#include "Options.h"

class Touchable : public CCTargetedTouchDelegate
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

  bool mWasTouched;
  bool mIsTouchable;

  // ===========================================================
  // Constructors
  // ===========================================================

  Touchable();

  // ===========================================================
  // Methods
  // ===========================================================

  // ===========================================================
  // Override Methods
  // ===========================================================

  virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
  virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
  virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);

  virtual bool containsTouchLocation(CCTouch* touch);

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

  // ===========================================================
  // Methods
  // ===========================================================

  void enable();
  void disable();

  virtual void onTouch(CCTouch* touch, CCEvent* event);

  // ===========================================================
  // Override Methods
  // ===========================================================
};

#endif