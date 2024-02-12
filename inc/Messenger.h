#pragma once
#include "../inc/Calculator.h"

/*
  RSA暗号における受信者のクラス
  公開鍵(n,k1)を用いて受け取った平文の暗号化を行う
*/

class Messenger
{
  private:
    unsigned long long _publicKey_n;
    unsigned long long _publicKey_k1;
    Calculator* _calculator;

  public:
    Messenger( unsigned long long n, unsigned long long k1 );
    ~Messenger();

    /**
   * @brief 受け取った1つのアスキーコード文字を暗号化する
   * 
   * @param clearChar 平文
   * @return unsigned long long 暗号化された文字
   */
    unsigned long long encryptChar( unsigned long long clearChar );
};
