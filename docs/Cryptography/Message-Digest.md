<h1 style="text-align: center;">Message-Digest</h1>


## Table Of Contents

**标准算法表述与实现**

+ [MD2](#MD2)
+ [MD4](#MD4)
+ [MD5](#MD5)



## MD2 

> RFC 1319

首先假设我们有一个b字节消息作为输入，并且我们希望找到其消息摘要。这里b是任意的   非负整数b可以为零，也可以任意大。
$$
M = m_0 m_1 ... m_{b-1}
$$



### Step 1.  填充字节

填充消息长度，使其字节长度为16的整数倍， 填充的内容在表中查询。至少一个字节，最大为16
$$
M = m_0 m_1 ..m_{b-1} .. m_{N-1} ， N/16 = 0
$$

```c
static unsigned char *PADDING[] = {
  (unsigned char *)"",
  (unsigned char *)"\001",
  (unsigned char *)"\002\002",
  (unsigned char *)"\003\003\003",
  (unsigned char *)"\004\004\004\004",
  (unsigned char *)"\005\005\005\005\005",
  (unsigned char *)"\006\006\006\006\006\006",
  (unsigned char *)"\007\007\007\007\007\007\007",
  (unsigned char *)"\010\010\010\010\010\010\010\010",
  (unsigned char *)"\011\011\011\011\011\011\011\011\011",
  (unsigned char *)"\012\012\012\012\012\012\012\012\012\012",
  (unsigned char *)"\013\013\013\013\013\013\013\013\013\013\013",
  (unsigned char *)"\014\014\014\014\014\014\014\014\014\014\014\014",
  (unsigned char *)
    "\015\015\015\015\015\015\015\015\015\015\015\015\015",
  (unsigned char *)
    "\016\016\016\016\016\016\016\016\016\016\016\016\016\016",
  (unsigned char *)
    "\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017",
  (unsigned char *)
    "\020\020\020\020\020\020\020\020\020\020\020\020\020\020\020\020"
}
```



### Step 2. 填充信息校验和

需要依赖PI的位数表 PI_SUBST, 进行XOR操作

```javascript
const checksum = new ArrayBuffer(16); // 存放16字节校验和

let L = 0, pi = createPiTable(); //pi的位数数组
for(let i = 0; i <= data.byteLength / 16 - 1; i++){
    for(let j = 0; j <= 15; j++){
        checksum[j] = pi[data[i*16+j] ^ L];
        L = checksum[j]; 
    }
}
```



### Step 3. 计算摘要信息

```javascript
const buffer = new Uint8Array(48);
const PI = createPiTable()
for(let i = 0; i <= this.data.byteLength/16 - 1; i++){

    for(let j = 0; j <= 15; j++){
        buffer[16+j] = this.data[i*16+j];
        buffer[32+j] = buffer[16+j] ^ buffer[j];
    }

    let t = 0;
    for(let j = 0; j <= 17; j++){
        for(let k = 0; k <= 47; k++){
            buffer[k] = buffer[k] ^ PI[t];
            t = buffer[k];
        }
        t = (t+j) % 256
    }
}
return buffer.slice(0, 16) //最终截取前16位
```



### 实现

```javascript
/**
 * 
 * @param {Uint8Array} data 
 */
function md2(data) {
    const messageDigest = new MD2(data)
    // 1. Append Padding Bytes
    // 2. Append Checksum
    // 3. process
    return messageDigest.appendPaddingBytes().appendChecksum().processMessage();
}



class MD2 {

    /**
     * @param {Uint8Array} data
     */
    constructor(data){
        this.data = data
    }

    /**
     * Step 1 Append Padding Bytes 如果字节长度不是16的倍数则扩容
     * @param {Uint8Array} data
     * @returns {MD2}
     */
    appendPaddingBytes() {
        if (this.data.byteLength % 16 == 0 && this.data.byteLength != 0) {
            return this.data;
        }

        // 计算扩容后的的容量
        const cap = 16 * (parseInt(this.data.byteLength / 16) + 1);

        // 计算填充数据和长度
        const fillstart = this.data.byteLength 
        const fillData = cap - this.data.byteLength;

        // 拷贝数据
        this.data = memcpy(this.data, new Uint8Array(cap));

        // 填充数据
        for(let i = fillstart; i < fillstart + fillData; i++){
            this.data[i] = fillData;
        }
        return this
    }

    /**
     * Step 2 appendChecksum 填充校验和
     * @param {Uint8Array} data
     * @returns {MD2}
     */
    appendChecksum() {
        const checksum = new Uint8Array(16); // 存放16字节校验和

        let L = 0, pi = createPiTable(); //pi的位数数组
        for (let i = 0; i <= this.data.byteLength / 16 - 1; i++) {
            for (let j = 0; j <= 15; j++) {
                checksum[j] = pi[this.data[i * 16 + j] ^ L];
                L = checksum[j];
            }
        }

        const result = memcpy(this.data, new Uint8Array(this.data.byteLength + 16))
        memcpy(checksum, result, this.data.byteLength);

        return this
    }

    
    /**
     * Step 3. 计算信息摘要
     * @param {Uint8Array} data
     * @returns {Uint8Array}
     */
    processMessage() {
        const buffer = new Uint8Array(48);
        const PI = createPiTable()
        for(let i = 0; i <= this.data.byteLength/16 - 1; i++){

            for(let j = 0; j <= 15; j++){
                buffer[16+j] = this.data[i*16+j];
                buffer[32+j] = buffer[16+j] ^ buffer[j];
            }

            let t = 0;
            for(let j = 0; j <= 17; j++){
                for(let k = 0; k <= 47; k++){
                    buffer[k] = buffer[k] ^ PI[t];
                    t = buffer[k];
                }
                t = (t+j) % 256
            }
        }
        return buffer.slice(0, 16)
    }
}

/**
 * @param {Uint8Array} src
 * @param {Uint8Array} dest
 * @returns {Uint8Array}
 */
function memcpy(src, dest, offset = 0) {
    for (let i = offset; i < src.byteLength; i++) {
        dest[i] = src[i];
    }
    return dest;
}

// 创建一个 uint8 256-pi表
function createPiTable() {
    return Uint8Array.from([
        41, 46, 67, 201, 162, 216, 124, 1, 61, 54, 84, 161, 236, 240, 6,
        19, 98, 167, 5, 243, 192, 199, 115, 140, 152, 147, 43, 217, 188,
        76, 130, 202, 30, 155, 87, 60, 253, 212, 224, 22, 103, 66, 111, 24,
        138, 23, 229, 18, 190, 78, 196, 214, 218, 158, 222, 73, 160, 251,
        245, 142, 187, 47, 238, 122, 169, 104, 121, 145, 21, 178, 7, 63,
        148, 194, 16, 137, 11, 34, 95, 33, 128, 127, 93, 154, 90, 144, 50,
        39, 53, 62, 204, 231, 191, 247, 151, 3, 255, 25, 48, 179, 72, 165,
        181, 209, 215, 94, 146, 42, 172, 86, 170, 198, 79, 184, 56, 210,
        150, 164, 125, 182, 118, 252, 107, 226, 156, 116, 4, 241, 69, 157,
        112, 89, 100, 113, 135, 32, 134, 91, 207, 101, 230, 45, 168, 2, 27,
        96, 37, 173, 174, 176, 185, 246, 28, 70, 97, 105, 52, 64, 126, 15,
        85, 71, 163, 35, 221, 81, 175, 58, 195, 92, 249, 206, 186, 197,
        234, 38, 44, 83, 13, 110, 133, 40, 132, 9, 211, 223, 205, 244, 65,
        129, 77, 82, 106, 220, 55, 200, 108, 193, 171, 250, 36, 225, 123,
        8, 12, 189, 177, 74, 120, 136, 149, 139, 227, 99, 232, 109, 233,
        203, 213, 254, 59, 0, 29, 57, 242, 239, 183, 14, 102, 88, 208, 228,
        166, 119, 114, 248, 235, 117, 75, 10, 49, 68, 80, 180, 143, 237,
        31, 26, 219, 153, 141, 51, 159, 17, 131, 20
    ])
}
```

