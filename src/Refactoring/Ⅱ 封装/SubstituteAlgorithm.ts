// 重构：替换算法

namespace BadSmell {
    function foundPerson(people: string[]) {
        for (let i = 0; i < people.length; i++) {
            if (people[i] == "Don") {
                return "Don"
            }
            if (people[i] == "John") {
                return "John"
            }
            if (people[i] == "Kent") {
                return "Kent"
            }
        }
        return "";
    }
}


namespace GoodSmell {
    function foundPerson(people: string[]) {
        const candidates = ["Don","John","Kent"];
        return people.find(p =>candidates.includes(p)) || "";
    }
}