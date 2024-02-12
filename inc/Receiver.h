#pragma once
#include "../inc/Calculator.h"

/*
  RSA暗号における受信者のクラス
  公開鍵(n,k1)と暗号鍵(k2)の生成と、受け取った暗号文の復号を行う
*/

class Receiver
{
  private:
    unsigned long long _p;  // 素数(コンストラクタで設定される)
    unsigned long long _q;  // 素数(コンストラクタで設定される)
    unsigned long long _publicKey_n; // p*qで表される公開鍵
    unsigned long long _publicKey_k1; // keyGenerate()で計算される公開鍵
    unsigned long long _secretKey; // 秘密鍵
    Calculator* _calculator;

  public:
    /**
     * @brief Construct a new Receiver object
     * 
     * @param p [unsigned long long]素数その1
     * @param q [unsigned long long]素数その2
     */
    Receiver( unsigned long long p, unsigned long long q );
    ~Receiver();

    /**
     * @brief 公開鍵(n,k1)と暗号鍵(k2)の生成を行う
     * 
     * @param n 返り値として公開鍵nをポインタ渡しで返す
     * @param k1 返り値として公開鍵k1をポインタ渡しで返す
     */
    void keyGenerate( unsigned long long* n, unsigned long long* k1 );

    /**
     * @brief 暗号化された1つの文字の複合を行う
     * 
     * @param encryptedChar [unsigned long long]暗号化されたアスキーコード文字
     * @return 復号化されたアスキーコード文字
     */
    unsigned long long decodeChar( unsigned long long encryptedChar );

    void outputKeys( void );
};
