#include "../inc/Receiver.h"
#include "../inc/Messenger.h"
#include "../inc/AsciiConverter.h"
#include <iostream>

int main()
{
  // ユーザーから2つの素数のペアを受け取る
  unsigned long long p, q;
  std::cout << "素数pを入力:" << std::endl;
  std::cin >> p;
  std::cout << "素数qを入力:" << std::endl;
  std::cin >> q;

  // 受け取った2つの素数のペアを元にレシーバークラスのオブジェクトを生成
  Receiver* receiver = new Receiver( p, q );

  // レシーバーオブジェクトで公開鍵(n, k1)と暗号鍵を生成
  unsigned long long publicKey_n;
  unsigned long long publicKey_k1;
  receiver->keyGenerate( &publicKey_n, &publicKey_k1 );

  // 公開鍵(n, k1)を使うメッセンジャークラスのオブジェクトを生成
  Messenger* messenger = new Messenger( publicKey_n, publicKey_k1 );

  // AsciiConverter クラスをインスタンス化
  AsciiConverter asciiConverter;
  
  // message.txtから読み込みアスキーコード列に変換後、converted.txt に出力
  std::vector<unsigned long long> asciiCodes = asciiConverter.convertFileToAscii("message.txt");
  asciiConverter.outputAsciiToFile( asciiCodes, "message(ASCII).txt" );

  // メッセンジャーオブジェクトでアスキーコード列を暗号化
  std::vector<unsigned long long> encryptedCodes;  // 暗号化されたアスキー文字列
  for ( unsigned long long plainCode : asciiCodes ) {
    if( plainCode >= publicKey_n ) {
      std::cout << "エラー：メッセージmが公開鍵n未満です！" << std::endl;
      return 0;
    }
    unsigned long long encryptedChar = messenger->encryptChar( plainCode );
    encryptedCodes.push_back( encryptedChar );
  }
  // 暗号化されたアスキー文字列をテキストファイルに出力
  asciiConverter.convertAsciiToFile( encryptedCodes, "encrypted.txt" );
  asciiConverter.outputAsciiToFile( encryptedCodes, "encrypted(ASCII).txt" );

  // レシーバーオブジェクトで復号化
  std::vector<unsigned long long> decodedCodes;  // 複合化されたアスキー文字列
  for ( unsigned long long encryptedCode : encryptedCodes ){
    unsigned long long decodeChar = receiver->decodeChar( encryptedCode );
    decodedCodes.push_back( decodeChar );
  }
  asciiConverter.convertAsciiToFile( decodedCodes, "decoded.txt");
  asciiConverter.outputAsciiToFile( decodedCodes, "decoded(ASCII).txt" );

  delete receiver;
  delete messenger;

  return 0;
}
