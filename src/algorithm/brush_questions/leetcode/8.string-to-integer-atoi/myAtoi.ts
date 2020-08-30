
function myAtoi(str: string): number {
    const numStr = str.trim().match(/^[-+]?[0-9]+/);
    if (numStr == null) return 0;

    const result = Number.parseInt(numStr[0]);
    if (result > 2**31-1) return 2**31-1;
    if (result < -(2**31)) return -(2**31);
    return result;
};