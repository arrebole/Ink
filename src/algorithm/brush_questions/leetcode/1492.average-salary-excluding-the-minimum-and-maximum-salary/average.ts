
function sum(...n: number[]) {
    return n.reduce((v, r) => r + v, 0);
}

// average 去除最高和最低求平均值 T(n) = O(n)
function average(salary: number[]): number {
    const maxValue = Math.max(...salary);
    const miniValue = Math.min(...salary);
    return (sum(...salary) - maxValue - miniValue) / (salary.length - 2);
};