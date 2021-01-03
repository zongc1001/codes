function func(disabled) {
  return disabled !== undefined && disabled;
}

console.log(func(true));
console.log(func(false));
console.log(func());
