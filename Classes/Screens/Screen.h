/**
 * Tooflya Inc. Development
 * @file Screen.h
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

#ifndef CONST_SCREEN_H
#define CONST_SCREEN_H

#include "Options.h"

#include "Touchable.h"
#include "Entity.h"
#include "TiledEntity.h"
#include "AnimatedEntity.h"
#include "Text.h"

class Screen : public CCScene, public Touchable
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

  // ===========================================================
  // Constructors
  // ===========================================================

  Screen();

  // ===========================================================
  // Methods
  // ===========================================================

  // ===========================================================
  // Override Methods
  // ===========================================================

  bool containsTouchLocation(CCTouch* touch);

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

  ~Screen();

  // ===========================================================
  // Methods
  // ===========================================================

  // ===========================================================
  // Override Methods
  // ===========================================================

  void onEnter();
  void onExit();
};

#endif