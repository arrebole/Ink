
// toHex 十进制转16进制
function toHex(num: number): string {
    const result = [];
    const hexTable = "0123456789abcdef";
    // 4 bit 对应一个16进制字符, 所以每次取4bit然后找到对应的hex字符
    while(num && result.length < 8) {
        result.unshift(hexTable[num & 0xf]);
        num = num >> 4;
    }
    return result.length > 0 ? result.join("") : "0";
};