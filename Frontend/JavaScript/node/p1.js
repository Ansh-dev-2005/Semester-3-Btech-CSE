const prompt = require("prompt-sync")();
var a = 0;
var b = 1;
var c = 0;
var n = parseInt(prompt("Enter the number of terms in the Fibonacci series:"));

console.log(a);
console.log(b);

for (var i = 0; i < n; i++) {
  c = a + b;
  console.log(c);
  a = b;
  b = c;
}
