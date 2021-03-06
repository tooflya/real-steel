/**
 * Tooflya Inc. Development
 * @file Loader.h
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

#ifndef CONST_LOADER_H
#define CONST_LOADER_H

#include "Screen.h"

class Loader : public Screen
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

  int mPercentageLoaded;

  bool mIsLoadingAnimationRunning;

  Text* mVersionText;
  Text* mLoadingText;

  // ===========================================================
  // Constructors
  // ===========================================================

  Loader();

  // ===========================================================
  // Methods
  // ===========================================================

  void onLoadingFinish();

  // ===========================================================
  // Virtual Methods
  // ===========================================================

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
  // Virtual Methods
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

  static Loader* create();

  ~Loader();

  // ===========================================================
  // Methods
  // ===========================================================

  // ===========================================================
  // Virtual Methods
  // ===========================================================

  void update(float pDeltaTime);

  void onEnter();
  void onExit();
};

#endif