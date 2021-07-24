# 信息摘要算法(MD家族)

我们熟知的 `md5` 是一种广泛的散列（哈希）函数，其作者是羅納德·林·李維斯特，该算法的目的是计算出文件的独一无二的指纹，该计算不可逆无法从结果计算回原内容，当源文件发生变化时，文件对应的 `md5` 计算的值也会发生变化。

`md5` 的结果是 128位（16字节）的二进制内容，由于二进制是人类难以理解的，所以我们平时看到的是其二进制内容转换为了十六进制的字符串，比如 `hello word` 的 `md5` 值转成十六进制字符串为 `13574ef0d58b50fab38ec841efe39df4`。

`md5` 是 `Message-Digest 5` 的缩写，说到了 `5` 那它也一定有其他的版本，没错它是由`md2`、`md4` 发展而来，而后 `sha` 家族的散列函数的灵感也是启于 `md`。如今 `cpu` 的算力的提升，人为的 `md5` 哈希碰撞成为可能（计算出另一个文件使得两个文件的 `md5` 值一样），作为1992年公开的 `md5` 不一定安全，所以追求安全时，可以考虑后继者 `sha`, 如今的区块链中广泛使用的哈希算法, 比特币中使用的是双重 `sha256` 算法。

## table of contents
+ [MD2](#MD2)
+ [MD4](#MD4)
+ [MD5](#MD5)

## MD2
> `MD2` 算法记录于 [rfc1319](https://datatracker.ietf.org/doc/html/rfc1319)

步骤:
+ 填充字节为16的倍数
+ 在填充后的内容中追加16位校验和
+ 计算最终结果

填充字节为16的倍数
```go
func appendMultiple16(buff []byte) []byte {
	return append(buff, make([]byte, 16-len(buff)%16)...)
}
```

在填充后的内容中追加16位校验和
```go
func checksum(buff []byte) []byte {
	return appendPadding(buff, 16-len(buff)%16, 0)
}

func appendChecksum(buff []byte, n int, data byte) []byte {
	for i := 0; i < n; i++ {
		buff = append(buff, data)
	}
	return buff
}



```

## MD4


## MD5