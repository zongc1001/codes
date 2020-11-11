interface Person {
    firstName: string;
    lastName: string;
}

function greeter(person: Person) {
    console.log(person.firstName, person.lastName);
}

class Student  {
    fullName: string;
    constructor(public firstName, public lastName) {
        this.fullName = firstName + lastName;
    }
}

greeter(new Student("fdaf", "fafasdf"));


