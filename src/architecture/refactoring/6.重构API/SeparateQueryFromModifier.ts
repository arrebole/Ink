// 重构：将查询函数与修改函数分离
function setOffAlarms() { }
let people: string[]

namespace BadSmell {
    function alertForMiscreant(people: string[]) {
        for (const p of people) {
            if (p == "Don") {
                setOffAlarms();
                return "Don";
            }
            if (p == "John") {
                setOffAlarms();
                return "John"
            }
        }
        return "";
    }
}
namespace GoodSmell {
    function alertForMiscreant(people: string[]) {
        if (findMiscreant(people) != "") setOffAlarms();
    }
    function findMiscreant(people: string[]): string {
        for (const p of people) {
            if (p == "Don") return "Don";
            if (p == "John") return "John"
        }
        return "";
    }

    const found = findMiscreant(people);
    alertForMiscreant(people)
}