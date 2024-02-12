#include "../inc/Calculator.h"

Calculator::Calculator(/* args */)
{
}

Calculator::~Calculator()
{
}

unsigned long long Calculator::powmod( unsigned long long b, unsigned long long e, unsigned long long m )
{
  unsigned long long result = 1; // 結果
  
  // 0 乗の場合、結果は 1
  if( e == 0 ) return result;
  
  // 指数が 0 になるまで法を取りながら積を計算
  while( e > 0 ) {
    // 奇数の場合: 最下位ビットが 1 = 求める解の因数として利用される
    if( e & 1 ) {
        e--; // 偶数にする
        result = result * b % m; // 解の更新
    }
    // 偶数の場合: 最下位ビットが 0 = 求める解の因数として利用されない
    else {
        e >>= 1; // 右に 1 ビットシフト
        b = b * b % m; // 部分計算
    }
  }
  
  return result;
}

unsigned long long Calculator::gcd( unsigned long long a, unsigned long long b )
{
  // gcd(a,b) = gcd(b,a mod b) の法則を利用
  while( b > 0 ) {
    unsigned long long t = a % b;
    a = b;
    b = t;
  }
  return a;
}

unsigned long long Calculator::lcm( unsigned long long a, unsigned long long b )
{
  // a * b = gcd(a,b) * lcm(a,b) の法則を利用
  return ( a * b ) / gcd( a, b );
}
