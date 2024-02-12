#include "../inc/AsciiConverter.h"

AsciiConverter::AsciiConverter(/* args */)
{
}

AsciiConverter::~AsciiConverter()
{
}

std::vector<unsigned long long> AsciiConverter::convertFileToAscii(const std::string& filename)
{
  std::vector<unsigned long long> asciiCodes;

  // ファイルを開く
  std::ifstream inputFile(filename);

  // ファイルが正しく開けない場合はエラーを表示して終了
  if (!inputFile.is_open()) {
      std::cerr << "ファイルを開けませんでした: " << filename << std::endl;
      return asciiCodes;
  }

  // 1文字ずつ読み取り、アスキーコードに変換してベクターに保存
  char c;
  while (inputFile.get(c)) {
      asciiCodes.push_back(static_cast<unsigned long long>(c));
  }

  // ファイルを閉じる
  inputFile.close();

  return asciiCodes;
}

void AsciiConverter::convertAsciiToFile(const std::vector<unsigned long long>& asciiCodes, const std::string& outputFilename)
{
  // ファイルを開く
  std::ofstream outputFile(outputFilename);

  // ファイルが正しく開けない場合はエラーを表示して終了
  if (!outputFile.is_open()) {
      std::cerr << "ファイルを開けませんでした: " << outputFilename << std::endl;
      return;
  }

  // アスキーコードを元の英数字に変換してファイルに書き込む
  for (unsigned long long code : asciiCodes) {
      char character = static_cast<char>(code);
      outputFile.put(character);
  }

  // ファイルを閉じる
  outputFile.close();

  std::cout << "変換が完了し、ファイルに保存されました: " << outputFilename << std::endl;
}

void AsciiConverter::outputAsciiToFile(const std::vector<unsigned long long>& asciiCodes, const std::string& outputFilename) {
  // ファイルを開く
  std::ofstream outputFile(outputFilename);

  // ファイルが正しく開けない場合はエラーを表示して終了
  if (!outputFile.is_open()) {
      std::cerr << "ファイルを開けませんでした: " << outputFilename << std::endl;
      return;
  }

  // アスキーコードをファイルに書き込む
  for (unsigned long long code : asciiCodes) {
      outputFile << code << " ";
  }

  // ファイルを閉じる
  outputFile.close();

  std::cout << "出力が完了し、ファイルに保存されました: " << outputFilename << std::endl;
}
