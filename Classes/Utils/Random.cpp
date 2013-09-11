/**
 * Tooflya Inc. Development
 * @file Random.cpp
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

#ifndef CONST_RANDOM
#define CONST_RANDOM

#include "Random.h"

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

int Random::random(int min, int max)
{
  #if (CC_TARGET_PLATFORM == CC_TARGET_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_TARGET_PLATFORM_IOS)

  return min + arc4random() / (RAND_MAX / (max + 1 - min));

  #else

  return min + rand() / (RAND_MAX / (max + 1 - min));

  #endif
}

float Random::randomf(float min, float max)
{
  #if (CC_TARGET_PLATFORM == CC_TARGET_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_TARGET_PLATFORM_IOS)

  return min + (float) arc4random() / ((float) RAND_MAX / (max - min));

  #else

  return min + (float) rand() / ((float) RAND_MAX / (max - min));

  #endif
}

bool Random::probably(int pProbably)
{
  return Random::random(0, 100) < pProbably;
}

// ===========================================================
// Override Methods
// ===========================================================

#endif