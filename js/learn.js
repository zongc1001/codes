function greeter(person) {
    console.log(person.firstName, person.lastName);
}
var Student = /** @class */ (function () {
    function Student(firstName, lastName) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.fullName = firstName + lastName;
    }
    return Student;
}());
greeter(new Student("fdaf", "fafasdf"));
