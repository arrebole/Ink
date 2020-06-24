// 重构:拆分循环

class People{
    age:number
    salary:number
}

const people = new Array<People>();

namespace BadSmell{
    let youngest = people[0]?people[0].age: Infinity;
    let totalSalary = 0;
    for(const p of people){
        if(p.age < youngest) youngest = p.age;
        totalSalary += p.salary;
    }
    let result = `youngestAge:${youngest},totalSalary: ${totalSalary}`;
}

namespace GoodSmell{
    function totalSalary(){
        let result = 0;
        for(const p of people){
            result += p.salary;
        }
        return result;
    }
    function youngest(){
        let result = people[0]?people[0].age: Infinity;
        for(const p of people){
            if(p.age < result) result = p.age;
        }
        return result;
    }

    let result = `youngestAge:${youngest()},totalSalary: ${totalSalary()}`;
}