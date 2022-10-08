#! /usr/bin/env node
// origin: https://codeforces.com/problemset/problem/1/A

const fs = require('fs');
const buffer = Buffer.alloc(255);

fs.read(process.stdin.fd, buffer, 0, buffer.length, 0, (err, bytesRead, buff) => {
    const [n, m, a] = buff.toString().split(' ').map(v => parseInt(v));
    const result = Math.ceil(n / a) * Math.ceil(m / a);
    fs.write(process.stdout.fd, result.toString(), (err) => {});
});