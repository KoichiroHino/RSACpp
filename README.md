<!-- Markdownでtex形式の数式を書くおまじない -->
<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.7/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
 MathJax.Hub.Config({
 tex2jax: {
 inlineMath: [['$', '$'] ],
 displayMath: [ ['$$','$$'], ["\\[","\\]"] ]
 }
 });
</script>

# C++でRSA暗号を実装してみた
## 動作確認済み環境
- OS : Ubuntu 22.04.3
- g++ : version 11.4.0
- make : GNU Make 4.3

## 使い方
1. message.txtを作成し、暗号化したい英数字列を保存
2. systemを実行
3. 2つの異なる素数のペア$p, q$を入力する
4. message.txtが暗号化されたencrypted.txtと、
  それを復号化したdecoded.txtが生成される
  (それぞれをアスキーコードに変換したものが*-ASCII.txtとして生成される)

## RSA暗号とは？
- 巨大な2つの素数同士の積からなる合成数の因数分解の困難性に基づいた暗号アルゴリズム
- 具体的な処理の流れは以下の通り
1. 受信者が公開鍵$n,k_1$と秘密鍵$k_2$を生成する($k_2$は誰にも公開しない)
2. 受信者が公開鍵$n,k_1$を送信者に送信する
3. 送信者は受け取った公開鍵$n,k_1$を使い、平文$m$を暗号$C$に暗号化する
4. 送信者は受信者に暗号$C$を送信する
5. 受信者は公開鍵$n$と秘密鍵$k_2$を使って、暗号$C$を平文$m$を複合する

## 1. 受信者の公開鍵$(n,k_1)$と暗号鍵($k_2$)の生成アルゴリズム
1. 大きな素数$p,\ q$を生成し、$n=pq$とする
2. $(p-1)(q-1)$と互いに素な整数$k_{1} (< (p-1)(q-1))$を選ぶ
3. $k_1 k_2 \equiv 1 \mod (p-1)(q-1)$となる$k_2$を取ってくる
4. $n$と$k_1$を公開鍵、$k_2$を秘密鍵とする

実際は、2.以降の流れは
- $(p-1)$と$(q-1)$の最小公倍数$L = lcm(p-1, q-1)$を計算
- 最小公倍数$L$と互いに素かつ、1よりも大きく$L$よりも小さい整数を公開鍵$k_1$とする
つまり、$gcd(k_1, L) = 1, 1 < k_1 < L$が成立する
- $v$を任意の整数として、$k_1 k_2 - Lv = 1$が成り立つような$k_2$を秘密鍵とする
※$lcm$は最小公倍数を求める関数で、$gcd$は最大公約数を求める関数

## 3. 送信者の暗号化アルゴリズム
- 送りたい平文を$m \in \mathbb{N}$とする
  ただし、$m < n$とする
- 公開鍵$n,k_1$を用いて、暗号文$C$を
  $C = m^{k_1} \pmod n$
  と暗号文$C$を計算する

## 5. 受信者の復号化アルゴリズム
- 暗号文$C$と秘密鍵$k_2$を用いて、
  $m' = C^{k_2} \pmod n$
  として$m'$を求めると、$m = m'$となる（つまり平文$m$と一致する）

## 参考
https://cham.space/rsa/#i-27
https://qiita.com/YutaKase6/items/cd9e26d723809dc85928
https://manabitimes.jp/math/1146
