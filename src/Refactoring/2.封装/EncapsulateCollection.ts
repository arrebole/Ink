// 重构：封装集合

namespace BadSmell {
    class Course {
        constructor(name: string) {
            this._name = name;
            this._isAdvanced = false;
        }
        private _name: string
        private _isAdvanced: boolean

        get name() { return this._name }
        get isAdvance() { return this._isAdvanced }
    }
    class Person {
        constructor(name: string) {
            this._name = name
            this._courses = []
        }
        private _name: string;
        private _courses: Array<Course>;

        get name() { return this._name };
        get courses() { return this._courses }
        set courses(aList: Course[]) { this._courses = aList }
    }

    const Bob = new Person("bob")
    Bob.courses = [new Course("cs") ]
}

namespace GoodSmell {
    class Course {
        constructor(name: string) {
            this._name = name;
            this._isAdvanced = false;
        }
        private _name: string
        private _isAdvanced: boolean

        get name() { return this._name }
        get isAdvance() { return this._isAdvanced }
    }
    class Person {
        constructor(name: string) {
            this._name = name
            this._courses = []
        }
        private _name: string;
        private _courses: Array<Course>;

        get name() { return this._name };
        get courses() { return this._courses.slice() }

        addCourse(aCourse:Course){
            this._courses.push(aCourse);
        }
        removeCourse(aCourse:Course){
            const index = this._courses.indexOf(aCourse);
            if(index == -1) throw new RangeError();
            else this._courses.splice(index, 1);
        }
    }

    const Bob = new Person("bob")
    Bob.addCourse( new Course("cs"))
}