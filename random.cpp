#include "random.h"

int generateRandomX()
{
  int randomNumber = rand();
  float random = (randomNumber % 630);
  int myRandom = random;
  return myRandom;
}

int generateRandomSpaceship()
{
  srand (time(NULL));
  int y = rand() % 9;
  srand (1);
  return y;
}

int generateAnotherRandomSpaceship()
{
    srand (time(NULL));
    int y = rand() % 9;
    srand (1);
    return y;
}

int generateRandomBlackHoleX()
{
  int randomNumber = rand();
  float random = (randomNumber % 620);
  int myRandom = random;
  return myRandom;
}

int generateRandomBlackHoleY()
{
  int randomNumber = rand();
  float random = (randomNumber % 250);
  int myRandom = random;
  return myRandom;
}
