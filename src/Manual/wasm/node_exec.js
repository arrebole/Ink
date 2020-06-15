const fs = require('fs');
const bytes = new Uint8Array(fs.readFileSync('./add.wasm'));

WebAssembly.compile(bytes)
    .then(wasmModule => {
        const instance = new WebAssembly.Instance(wasmModule);
        const { add } = instance.exports;
        console.log(add(100, 201));
    })
    .catch(err => console.log(err));