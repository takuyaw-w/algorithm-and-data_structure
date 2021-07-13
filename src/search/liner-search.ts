function linerSearch(array: number[], targetNumber: number): boolean {
  for (let i = 0; array.length; i++) {
    if (targetNumber === array[i]) {
      console.log("hit", array[i])
      return true;
    }
  }
  return false;
}

const ary = [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25];
const target = 10;
const isCheck: boolean = linerSearch(ary, target);
console.log(isCheck)
