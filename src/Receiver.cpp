#include "../inc/Receiver.h"
#include <iostream>

Receiver::Receiver( unsigned long long p, unsigned long long q )
{
  // 素数のペアのセット
  _p = p;
  _q = q;

  _calculator = new Calculator();

  // debug
  std::cout << "Receiver Constractor" << std::endl;
  std::cout << "_p = " << _p << std::endl;
  std::cout << "_q = " << _q << std::endl;
}

Receiver::~Receiver()
{
  delete _calculator;
}

void Receiver::keyGenerate( unsigned long long* n, unsigned long long* k1 )
{
  // 公開鍵nの生成
  _publicKey_n = _p * _q;

  // 公開鍵k1の生成
  // unsigned long long m = _calculator->lcm( _p-1, _q-1 );
  unsigned long long m = (_p-1) * (_q-1);
  std::cout << "m = " << m << std::endl;  //debug
  // mと互いに素かつ、1 < hoge < mを満たす整数を探す
  unsigned long long hoge = 2;
  while( true )
  {
    if( _calculator->gcd( hoge, m ) == 1 )
      break;

    hoge++;
  }
  _publicKey_k1 = hoge;
  std::cout << "k1 = " << _publicKey_k1 << std::endl;

  // 秘密鍵k2の生成
  // k1*k2 mod m = 1 を満たすようなk2を探す
  unsigned long long fuga = 1;
  while( true ){
    if( (_publicKey_k1 * fuga) % m == 1 ){
      std::cout << fuga << std::endl;
      std::cout << (_publicKey_k1 * fuga) << std::endl;
      std::cout << (_publicKey_k1 * fuga) % m << std::endl;
      break;
    }
    
    fuga++;
  }
  _secretKey = fuga;

  // 返り値
  *n  = _publicKey_n;
  *k1 = _publicKey_k1;

  // debug
  std::cout << "----- Key Generate -----" << std::endl;
  std::cout << "_publicKey_n  = " << _publicKey_n << std::endl;
  std::cout << "_publicKey_k1 = " << _publicKey_k1 << std::endl;
  std::cout << "_secretKey    = " << _secretKey << std::endl;
}

unsigned long long Receiver::decodeChar( unsigned long long encryptedChar )
{
  return _calculator->powmod( encryptedChar, _secretKey, _publicKey_n );
}
