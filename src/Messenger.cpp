#include "../inc/Messenger.h"
#include <iostream>
#include <cmath>

Messenger::Messenger( unsigned long long n, unsigned long long k1 )
{
  _publicKey_n = n;
  _publicKey_k1 = k1;

  _calculator = new Calculator();
}

Messenger::~Messenger()
{
  delete _calculator;
}

unsigned long long Messenger::encryptChar( unsigned long long clearChar )
{
  return _calculator->powmod( clearChar, _publicKey_k1, _publicKey_n );
}
