#pragma once

class Calculator
{
  private:

  public:
    Calculator(/* args */);
    ~Calculator();

    /**
     * @brief 剰余項の計算を行う( b^e mod m )
     * 
     * @param b べき乗される数
     * @param e bを何乗するか
     * @param m mod の法
     * @return unsigned long long b^e mod m
     */
    unsigned long long powmod( unsigned long long b, unsigned long long e, unsigned long long m );

    /**
     * @brief 最大公約数の計算を行う( gcd(a,b) )
     * 
     * @param a 
     * @param b 
     * @return unsigned long long aとbの最大公約数
     */
    unsigned long long gcd( unsigned long long a, unsigned long long b );

    /**
     * @brief 最小公倍数の計算を行う( lcm(a,b) )
     * 
     * @param a 
     * @param b 
     * @return unsigned long long aとbの最小公倍数
     */
    unsigned long long lcm( unsigned long long a, unsigned long long b );
};
