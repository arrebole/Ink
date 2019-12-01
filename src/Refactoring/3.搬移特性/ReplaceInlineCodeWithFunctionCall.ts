// 重构: 以函数调用取代内联代码

namespace BadSmell {
    function isAppliesToMass(states: string[]) {
        let appliesToMass = false;
        for (const s of states) {
            if (s == "MA") appliesToMass = true;
        }
        return appliesToMass;
    }

}

namespace GoodSmell {
    function isAppliesToMass(states: string[]) {
        return states.includes("MA");
    }
}