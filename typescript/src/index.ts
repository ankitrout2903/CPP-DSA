type Employee = {
    

let employee : {
    readonly id: number,
    name : string,
    retire : (date : Date) => void
} = {
    id : 1,
    name : "John",
    retire : (date : Date) => {
        console.log("Retiring on " + date);
    }
}