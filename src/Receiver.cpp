#include "../inc/Receiver.h"
#include <iostream>
#include <fstream>

Receiver::Receiver( unsigned long long p, unsigned long long q )
{
  // 素数のペアのセット
  _p = p;
  _q = q;

  _calculator = new Calculator();
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
  unsigned long long m = (_p-1) * (_q-1);
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
      break;
    }
    
    fuga++;
  }
  _secretKey = fuga;

  // 返り値
  *n  = _publicKey_n;
  *k1 = _publicKey_k1;

}

unsigned long long Receiver::decodeChar( unsigned long long encryptedChar )
{
  return _calculator->powmod( encryptedChar, _secretKey, _publicKey_n );
}

void Receiver::outputKeys()
{
  std::ofstream outputFile( "Keys.txt" );

  // ファイルが正しく開かれているかを確認
  if (outputFile.is_open()) {
    // データをファイルに書き込む
    outputFile << "(p, q) = (" << _p << ", " << _q << ")" << std::endl;
    outputFile << "公開鍵n = " << _publicKey_n << std::endl;
    outputFile << "公開鍵k1 = " << _publicKey_k1 << std::endl;
    outputFile << "秘密鍵k2 = " << _secretKey << std::endl;

    // ファイルを閉じる
    outputFile.close();
  } else {
    std::cerr << "ファイルを開けませんでした。" << std::endl;
  }

}
