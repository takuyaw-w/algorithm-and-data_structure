interface data {
  id: number;
  data: string;
}

function linerSearch(array: data[], targetNumber: number): boolean {
  for (let i = 0; i < array.length; i++) {
    if (targetNumber === array[i].id) {
      console.log("hit", array[i])
      return true;
    }
  }
  return false;
}

const ary: data[] = [
  {
    id: 9,
    data: "data9"
  },
  {
    id: 8,
    data: "data8"
  },
  {
    id: 101,
    data: "data101"
  },
  {
    id: 68,
    data: "data68"
  },
  {
    id: 47,
    data: "data47"
  },
  {
    id: 31,
    data: "data31"
  },
  {
    id: 91,
    data: "data91"
  },
];
const target = 101;
const isCheck: boolean = linerSearch(ary, target);
console.log(isCheck)
