# Myprintf
C言語のprintf関数を再現したものです。

対応している書式は %d, %x, %f, &s, %c のみです。

_itoa_sや_gcvt_s関数は一部のMicrosoft環境(Visual Studioなど) でのみ使用可能です。

他の環境では未定義になるためエラーが発生します。
