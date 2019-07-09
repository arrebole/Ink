// 重构：搬移语句到调用者

namespace BadSmell {
    class Photo {
        title: string
        location: string
        date: Date
    }
    class Person {
        photo: Photo
    }
    function renderPerson(person: Person) {
        let result = new Array<string>();
        result.concat(photoData(person.photo))
        return result.join("\n");
    }
    function photoData(aPhoto: Photo) {
        return [
            `<p>title: ${aPhoto.title}</p>`,
            `<p>location: ${aPhoto.location}</p>`,
            `<p>date: ${aPhoto.date.toDateString()}</p>`
        ]
    }
}

namespace GoodSmell {
    class Photo {
        title: string
        location: string
        date: Date
    }
    class Person {
        photo: Photo
    }
    function renderPerson(person: Person) {
        let result = new Array<string>();
        result.push(`<p>title: ${person.photo.title}</p>`)
        result.concat(photoData(person.photo))
        return result.join("\n");
    }
    function photoData(aPhoto: Photo) {
        return [
            `<p>location: ${aPhoto.location}</p>`,
            `<p>date: ${aPhoto.date.toDateString()}</p>`
        ]
    }
}