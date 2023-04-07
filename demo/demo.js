const fibonacci = require("../build/Release/fibonacci");
console.log(fibonacci.wiki());
console.log("fibonacci.sequence()=", fibonacci.sequence());
console.log("fibonacci.sequence(1)=", fibonacci.sequence(1));
console.log("fibonacci.sequence(2)=", fibonacci.sequence(2));
console.log("fibonacci.sequence(1000)=", fibonacci.sequence(1000));
console.log("fibonacci.sequence(10000)=", fibonacci.sequence(10000));
