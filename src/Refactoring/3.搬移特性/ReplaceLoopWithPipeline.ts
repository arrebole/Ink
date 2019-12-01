// 重构：以管道取代循环

class People{
    age:number
    salary:number
}

const people = new Array<People>();

namespace BadSmell{
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

namespace GoodSmell{
    function totalSalary(){
        return people.reduce((total,p)=>total+=p.salary,0)
    }
    function youngest(){
        return Math.max(...people.map(p=>p.age))
    }

    let result = `youngestAge:${youngest()},totalSalary: ${totalSalary()}`;
}