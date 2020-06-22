fetch('./source/greet.wasm')
    .then(response => response.arrayBuffer())
    .then(bytes => WebAssembly.compile(bytes))
    .then(wasmModule => {
        const instance = new WebAssembly.Instance(wasmModule);
        console.log(instance.exports.add(100, 201));
    })
    .catch(err => console.log(err));