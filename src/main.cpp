#include "../inc/Receiver.h"
#include "../inc/Messenger.h"
#include <iostream>

int main()
{
  // ユーザーから2つの素数のペアを受け取る
  unsigned long long p, q;
  std::cout << "素数pを入力:" << std::endl;
  std::cin >> p;

  std::cout << "素数qを入力:" << std::endl;
  std::cin >> q;
  // p = 23;
  // q = 31;

  // 受け取った2つの素数のペアを元にレシーバークラスのオブジェクトを生成
  Receiver* receiver = new Receiver( p, q );

  // レシーバーオブジェクトで公開鍵(n, k1)と暗号鍵を生成
  unsigned long long publicKey_n;
  unsigned long long publicKey_k1;
  receiver->keyGenerate( &publicKey_n, &publicKey_k1 );

  // 公開鍵(n, k1)を使うメッセンジャークラスのオブジェクトを生成
  Messenger* messenger = new Messenger( publicKey_n, publicKey_k1 );

  // メッセンジャーオブジェクトで暗号化
  unsigned long long plainChar = 110;  // 暗号化したい平文文字
  if( plainChar >= publicKey_n )
  {
    std::cout << "エラー：メッセージmが公開鍵n未満です！" << std::endl;
    return 0;
  }
  unsigned long long encryptedChar;
  encryptedChar = messenger->encryptChar( plainChar );

  // レシーバーオブジェクトで復号化
  unsigned long long decodedChar; // 複合した文字
  decodedChar = receiver->decodeChar( encryptedChar );

  // debug
  std::cout << "----- Demo -----" << std::endl;
  std::cout << "    plainChar = " << plainChar << std::endl;
  std::cout << "encryptedChar = " << encryptedChar << std::endl;
  std::cout << "  decodedChar = " << decodedChar << std::endl;

  delete receiver;
  delete messenger;

  return 0;
}
