/**
 * Tooflya Inc. Development
 * @file Entity.h
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

#ifndef CONST_ENTITY_H
#define CONST_ENTITY_H

#include "Options.h"

#include "Touchable.h"

class Entity : public CCSprite, public Touchable
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

  int id;

  float mWidth;
  float mHeight;

  float mPaddingX;
  float mPaddingY;

  bool mWasTouched;
  bool mIsCascadeOpacity;

  const char* mTextureFileName;

  CCPoint mStartTouchPoint;

  CCArray* mManager;

  // ===========================================================
  // Constructors
  // ===========================================================

  virtual  void constructor(const char* pszFileName, CCNode* pParent);

  Entity(const char* pszFileName);
  Entity(const char* pszFileName, CCNode* pParent);

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

  // ===========================================================
  // Constructors
  // ===========================================================

  static Entity* create(const char* pszFileName);
  static Entity* create(const char* pszFileName, CCNode* pParent);

  ~Entity();

  // ===========================================================
  // Methods
  // ===========================================================

  void setId(int pId);

  float getWidth();
  float getHeight();

  float getWidthScaled();
  float getHeightScaled();

  float getX();
  float getY();
  float getCenterX();
  float getCenterY();
  float getCenterPosition();

  void setX(float pX);
  void setY(float pY);
  void setPosition(float pX, float pY);
  void setCenterPosition(float pCenterX, float pCenterY);

  virtual void create();
  virtual void destroy();

  virtual void onCreate();
  virtual void onDestroy();

  virtual Entity* deepCopy();

  void setManager(CCArray* pManager);

  // ===========================================================
  // Override Methods
  // ===========================================================

  void onEnter();
  void onExit();

  void update(float pDeltaTime);
  void draw();

  void setOpacity(GLubyte pOpaquee);

  bool containsTouchLocation(CCTouch* touch);
  void onTouch(CCTouch* touch, CCEvent* event);
};

#endif