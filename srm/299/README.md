# SRM #299

## Div2

### Easy
読解困難すぎた・・・。

スケール => 目盛りの幅かな？
* b1 : 最初のスケールの融点
* f1 : 最初のスケールの沸点
* t : 最初のスケールの任意の温度
* b2 : 他のスケールの融点
* f2 : 他のスケールの沸点
* t' : 他のスケールにおけるtの温度

(f1 - b1) : (t - b1) = (f2 - b2) : (t' - b2)

t' = (t - b1) * (f2 - b2) / (f1 - b1) + b2

### Medium
別に以下のように考えても良いというだけで、Examplesを見れば一目瞭然。

.の行と列を除くとxだけの長方形となる。最小の数は対角線上にxを置けば良い。最大の数は長方形に詰め込めば良い。

### Hard
読解困難。

粒子はn個あるとすると、
`` interacts[i][j] = i番目とj番目の粒子が衝突した時の挙動 (0 <= i < n, 0 <= j < n)``
* 挙動について
  * + := i番目の粒子が消滅
  * - := j番目の粒子が消滅
  * 0 := 何も起きない

やはり英語もうちょっと鍛えないといけないなぁ・・・。
## Div1
