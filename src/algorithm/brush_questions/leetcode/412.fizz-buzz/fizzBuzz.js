
function fizzBuzz(n) {
    const result = new Array(n);
    for (let i = 3; i <= n; i *= 3) {
        result[i-1] = "Fizz";
    }
    for (let i = 5; i <= n; i *= 5) {
        if (result[i-1]) result[i-1] = "FizzBuzz";
        else result[i-1] = "Buzz";
    }
    for (let i = 1; i <= n; i++) {
        if (!result[i-1]) result[i-1] = i.toString();
    }
    return result;
};

module.exports.fizzBuzz = fizzBuzz