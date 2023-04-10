const bash = require("../build/Release/bash");

console.log("[JS] ls: ", bash.runWithResult("ls"));
bash.run("mkdir test");
console.log("[JS] ls: ", bash.runWithResult("ls"));
bash.run("rm -rf test");
console.log("[JS] ls: ", bash.runWithResult("ls"));
