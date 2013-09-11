/**
 * Tooflya Inc. Development
 * @file EntityManager.h
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

#ifndef CONST_ENTITYMANAGER_H
#define CONST_ENTITYMANAGER_H

#include "Options.h"

template <class T> class EntityManager : public CCArray
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

  int mLastElementNumber;
  int mCapacity;

  CCNode* mParent;

  // ===========================================================
  // Constructors
  // ===========================================================

  void constructor(int pCreateCount, int pMaxCount, T pEntity, CCNode* pParent, int pZOrder)
  {
    this->initWithCapacity(pMaxCount);

    this->mParent = pParent;
    this->mLastElementNumber = -1;
    this->mCapacity = pCreateCount; // TODO: increase to pMaxCount

    for(int i = 0; i < pCreateCount; i++)
    {
    T currentEntity;

    if(i == 0)
    {
      currentEntity = pEntity;
    }
    else
    {
      currentEntity = pEntity->deepCopy();
    }

    currentEntity->autorelease();

    currentEntity->setManager(this);
    currentEntity->setId(i);

    this->mParent->addChild(currentEntity, pZOrder);

    this->addObject(currentEntity);
    }
  }

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

  EntityManager<T>(int pCreateCount, T pEntity, CCNode* pParent)
  {
    this->constructor(pCreateCount, pCreateCount, pEntity, pParent, 0);
  }

  EntityManager<T>(int pCreateCount, T pEntity, CCNode* pParent, int pZOrder)
  {
    this->constructor(pCreateCount, pCreateCount, pEntity, pParent, pZOrder);
  }

  EntityManager<T>(int pCreateCount, int pMaxCount, T pEntity, CCNode* pParent)
  {
    this->constructor(pCreateCount, pMaxCount, pEntity, pParent, 0);
  }

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

  ~EntityManager<T>()
  {
  }

  static EntityManager<T>* create(int pCreateCount, T pEntity, CCNode* pParent)
  {
    EntityManager* manager = new EntityManager(pCreateCount, pEntity, pParent);
    manager->autorelease();
    manager->retain();

    return manager;
  }

  static EntityManager<T>* create(int pCreateCount, T pEntity, CCNode* pParent, int pZOrder)
  {
    EntityManager* manager = new EntityManager(pCreateCount, pEntity, pParent, pZOrder);
    manager->autorelease();
    manager->retain();

    return manager;
  }

  static EntityManager<T>* create(int pCreateCount, int pMaxCount, T pEntity, CCNode* pParent)
  {
    EntityManager* manager = new EntityManager(pCreateCount, pMaxCount, pEntity, pParent);
    manager->autorelease();
    manager->retain();

    return manager;
  }

  // ===========================================================
  // Methods
  // ===========================================================

  int getCount()
  {
    return this->mLastElementNumber + 1;
  }

  int getCapacity()
  {
    return this->mCapacity;
  }

  void create()
  {
    if (++this->mLastElementNumber < this->mCapacity)
    {
      T object = this->get(this->mLastElementNumber);

      object->create();

      return;
    }
    return; // TODO: Remove this.
    // Create a new object if manager hasn't free object.

    T object = this->get(0)->deepCopy();

    object->setManager(this);
    object->setId(this->mCapacity);

    this->mParent->addChild(object);

    this->addObject(object);

    this->mCapacity++;

    object->create();
  }

  void destroy(int pIndex)
  {
    if(this->mLastElementNumber >= 0)
    {
    this->exchangeObjectAtIndex(pIndex, this->mLastElementNumber);

    this->get(pIndex)->setId(pIndex);
    this->get(this->mLastElementNumber)->setId(this->mLastElementNumber);

    this->mLastElementNumber--;
    }
  }

  void clear()
  {
    for(int i = 0; i < this->getCapacity(); i++)
    {
    this->get(i)->destroy();
    }
  }

  T get(int pIndex)
  {
    return static_cast<T>(this->objectAtIndex(pIndex));
  }

  T last()
  {
    return this->get(this->mLastElementNumber);
  }

  // ===========================================================
  // Override Methods
  // ===========================================================
};

#endif