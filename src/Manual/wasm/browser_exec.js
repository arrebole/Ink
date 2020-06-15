fetch('./add.wasm')
    .then(response => response.arrayBuffer())
    .then(bytes => WebAssembly.compile(bytes))
    .then(wasmModule => {
        const instance = new WebAssembly.Instance(wasmModule);
        const { add } = instance.exports;
        console.log(add(100, 201));
    })
    .catch(err => console.log(err));