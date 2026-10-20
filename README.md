*This project has been created as part of the 42 curriculum by riwamoto.*

# Libft

## Description

libftは、C標準ライブラリ（libc）の関数の一部を再実装し、文字列操作・出力・リンクリストのための関数を追加した静的ライブラリである。

ライブラリは`libft.a`としてビルドされ、すべての関数名には`ft_`が付いており、宣言は`libft.h`にまとめられる。

**目的**

* 標準関数の実装による構造の理解
* 今後の課題で使用できる自分用のライブラリの作成

**概要**

* **Part 1.** `ft_`をつけたlibc関数の再実装
* **Part 2.** libcにない、または形の異なる関数の実装
* **Part 3.** 構造体を用いた連結リストの実装

## Instructions

### コンパイル

リポジトリのルートで下記コマンドを実行

```bash
make		# (make all) libft.a を作成
make clean	# オブジェクトファイルを削除
make fclean 	# オブジェクトファイルと libft.a を削除
make re		# fclean して再ビルド
```

すべてのソースは `cc` と `-Wall -Wextra -Werror` でコンパイルされ、 `libft.a` が作成される

### 使い方

ソースファイルでヘッダをインクルード

```c
#include "libft.h"
```

コンパイル時にライブラリをリンク

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o a.out
```

| 要素 | 種類 | 意味 |
| --- | --- | --- |
| `cc` | コンパイラ | Cコンパイラの呼び出し |
| `-Wall` | 警告オプション | 未使用の変数の警告などを有効化 |
| `-Wextra` | 警告オプション | `-Wall`に含まれない追加の警告を有効化 |
| `-Werror` | 警告オプション | 警告をエラーとして処理 |
| `main.c` | ソースファイル | コンパイルするためのファイル |
| `-L` | リンクオプション | ライブラリを探す場所にカレントディレクトリを追加 |
| `-lft` | リンクオプション | `libft.a`をリンク |
| `-o a.out` | 出力オプション | 実行ファイル名を`a.out`にする |

## Library details

### Part 1 - libc関数

libc の関数を、manページと同じプロトタイプ・挙動で再実装したもの

| 分類 | 関数 |
| --- | --- |
| 文字判定 | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| 文字変換 | `ft_toupper`, `ft_tolower` |
| メモリ操作 | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp` |
| 文字列操作 | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr` |
| 数値変換 | `ft_atoi` |
| メモリ確保 | `ft_calloc`, `ft_strdup` |

> [!IMPORTANT]
> 文字判定の関数は条件に当てはまれば `1` 、当てはまらなければ `0` を返す

### Part 2 - 追加関数

libc にない、または libc とは異なる形の関数

| 関数 | 説明 |
| --- | --- |
| `ft_substr` | `s` の `start` 番目から最大 `len` 文字の部分文字列を新しく確保して返す |
| `ft_strjoin` | `s1` と `s2` を連結した新しい文字列を返す |
| `ft_strtrim` | `s1` の先頭と末尾から `set` に含まれる文字を取り除いたコピーを返す |
| `ft_split` | `s` を区切り文字 `c` で分割し、NULL 終端の文字列配列を返す |
| `ft_itoa` | 整数を文字列に変換して返す |
| `ft_strmapi` | 各文字とその添字に `f` を適用した結果から新しい文字列を作る |
| `ft_striteri` | 各文字の添字とアドレスを `f` に渡し、元の文字列をその場で変更できるようにする |
| `ft_putchar_fd` | 文字を指定したファイルディスクリプタに出力する |
| `ft_putstr_fd` | 文字列を指定したファイルディスクリプタに出力する |
| `ft_putendl_fd` | 文字列と改行を指定したファイルディスクリプタに出力する |
| `ft_putnbr_fd` | 整数を指定したファイルディスクリプタに出力する |

### Part 3 - 連結リスト

リスト関数は、 `libft.h` で宣言した次の構造体を使う

```c
typedef struct s_list
{
	void		*context;
	struct s_list	*next;
}	t_list;
```

| 関数 | 説明 |
| --- | --- |
| `ft_lstnew` | 指定した context を持ち、 `next` が NULL の新しいノードを作る |
| `ft_lstadd_front` | リストの先頭にノードを追加 |
| `ft_lstadd_back` | リストの末尾にノードを追加 |
| `ft_lstsize` | リストのノード数を返す |
| `ft_lstlast` | リストの最後のノードを返す |
| `ft_lstdelone` | ノードの context を `del` で解放し、ノード自体も解放 |
| `ft_lstclear` | 指定した以降のノードをすべて解放し、リストのポインタを NULL にする |
| `ft_lstiter` | すべてのノードの content に `f` を適用する |
| `ft_lstmap` | 各ノードの contentに `f` を適用した新しいリストを作る。失敗時は `del` で始末 |

## Resources

### 参考資料

- [ascii コード表](https://www3.nit.ac.jp/~tamura/ex2/ascii.html): ascii コード・表示可能文字の確認
- [calloc](https://mogachan.net/clangcalloc/): callocの構造・仕様の学習
- [man ページ](https://manpages.ubuntu.com/): libc 関数の使用の確認
- [Markdown](https://qiita.com/ourinhu269/items/af1e2b4d7fb71a78aef3): Markdownの書き方の理解
- [memcmp](https://mogachan.net/clangcmp/#google_vignette): memcmpの構造・仕様の学習
- [memcpyとmemmove](https://mogachan.net/clangmemcpy/): memcpyとmemmoveの構造・仕様の学習
- [void *](https://qiita.com/mizcii/items/38aa405122542771a23f): void *の仕様の学習
- [連結リスト](https://www.ns.kogakuin.ac.jp/~cu40887/prog4/chapter5.html): 単方向リストの構造の学習

### AI の使用について

- `unsigned char` の詳細について質問した。
- `void *` の詳細について質問した。
- 連結リストの構造について資料のみでは理解できなかったため、理解のためのヒントをもらった。
- 課題pdfの翻訳に使用した
- 関数ポインタについての理解のため、構造や使用例などについて質問した。
