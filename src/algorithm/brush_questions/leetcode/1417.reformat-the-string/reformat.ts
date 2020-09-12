
function extract(source: string, flag: "number" | "string"): string[] {
    if (flag === "number") return source.match(/[a-z]/g) || [] as string[];
    return source.match(/[0-9]/g) || [] as string[];
}

function merge(a: string[], b: string[]) {
    const long = a.length >= b.length ? a : b;
    const short = a.length >= b.length ? b : a;

    const result = [];
    for (let i = 0; i < short.length; i++) {
        result.push(long[i], short[i]);
    }

    if (long.length > short.length) {
        result.push(long[long.length - 1]);
    }
    return result.join('');
}

function reformat(s: string): string {
    const numb = extract(s, "number");
    const str = extract(s, "string");

    if (Math.abs(numb.length - str.length) > 1) {
        return "";
    }
    return merge(numb, str);
};