#pragma once
#include <iostream>
#include <fstream>
#include <vector>

class AsciiConverter
{
  private:
    /* data */
  public:
    AsciiConverter(/* args */);
    ~AsciiConverter();

  /**
   * @brief 指定されたファイル名のファイルをASCIIコードに変換する
   * 
   * @param filename ファイル名
   * @return std::vector<unsigned long long> ASCIIコードに変換後の文字列
   */
    std::vector<unsigned long long> convertFileToAscii(const std::string& filename);

  /**
   * @brief 与えられたASCIIコード列を変換し、指定されたファイルに保存する
   * 
   * @param asciiCodes ASCIIコード列
   * @param outputFilename 保存するファイル名
   */
    void convertAsciiToFile(const std::vector<unsigned long long>& asciiCodes, const std::string& outputFilename);

    void outputAsciiToFile(const std::vector<unsigned long long>& asciiCodes, const std::string& outputFilename);

};
