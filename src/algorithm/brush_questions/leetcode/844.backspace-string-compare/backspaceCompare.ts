

function interpreter(str: string): string {
    const result = [];
    for (const char of str) {
        if (char == '#') result.pop();
        else result.push(char);
    }
    return result.join('');
}

function backspaceCompare(S: string, T: string): boolean {
    return interpreter(S) == interpreter(T);
};
