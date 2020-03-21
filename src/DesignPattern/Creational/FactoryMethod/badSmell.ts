#! /usr/bin/env deno

namespace BadSmell {
    // 直接使用new来创建对象, 会带来紧耦合的关系。
    // 😈Exploit：当要改用其他行星类时，就会出现问题。

    class Earth {
        public rotation() {
            // ...     
        }
    };

    function sample() {
        const earth = new Earth();
    }
}