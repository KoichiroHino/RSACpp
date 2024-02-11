# C++プロジェクト用の汎用的なMakefile

## 動作確認済み環境
- OS : Ubuntu 22.04.3
- g++ : version 11.4.0
- make : GNU Make 4.3

## 使い方
- 初期化
  
  Makefileが置かれているディレクトリにinc, obj, srcディレクトリが作られる
  
  gitのローカルリポジトリを初期化し、.gitignoreとMakefileを登録する

  ```make init```
- ビルド
  
  差分ビルド

  systemという実行ファイルがカレントディレクトリに作られる

  ```make```

- クリーン

  objディレクトリ内の.oファイルと.dファイルを全削除

  ```make clean```

- リビルド

  クリーンした後にビルドを実行

  ```make rebuild```

## 各ディレクトリの説明
- inc
  
  ヘッダファイルを置く

- obj

  ビルドすることで生成される.oファイルと.dファイルが置かれる

- src

  cppファイルを置く
