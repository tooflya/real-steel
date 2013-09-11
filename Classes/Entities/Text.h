/**
 * Tooflya Inc. Development
 * @file Text.h
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

#ifndef CONST_TEXT_H
#define CONST_TEXT_H

#include "Utils.h"

class Text : public CCLabelTTF
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

  Text(const char* pString, float pSize, CCNode* pParent);

  // ===========================================================
  // Methods
  // ===========================================================

  // ===========================================================
  // Override Methods
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

  float mInitCenterX;
  float mInitCenterY;

  // ===========================================================
  // Constructors
  // ===========================================================

  static Text* create(const char* pString, float pSize, CCNode* pParent);

  ~Text();

  // ===========================================================
  // Methods
  // ===========================================================

  void setPosition(float pX, float pY);
  void setCenterPosition(float pCenterX, float pCenterY);

  float getWidth();
  float getHeight();

  float getCenterX();
  float getCenterY();

  void enableShadow();
  void disableShadow();

  // ===========================================================
  // Override Methods
  // ===========================================================
};

#endif