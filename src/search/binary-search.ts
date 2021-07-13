interface data {
  id: number;
  data: string;
}

const datas: data[] = [
  {
    id: 1,
    data: "data1",
  },
  {
    id: 2,
    data: "data2",
  },
  {
    id: 3,
    data: "data3",
  },
  {
    id: 4,
    data: "data4",
  },
  {
    id: 5,
    data: "data5",
  },
  {
    id: 6,
    data: "data6",
  },
  {
    id: 7,
    data: "data7",
  },
  {
    id: 8,
    data: "data8",
  },
  {
    id: 9,
    data: "data9",
  },
  {
    id: 10,
    data: "data10",
  },
  {
    id: 11,
    data: "data11",
  },
  {
    id: 12,
    data: "data12",
  },
  {
    id: 13,
    data: "data13",
  },
];

function binarySearch(array: data[], targetNumber: number): boolean {
  let min = 0;
  let max = array.length;
  let middle;

  while (min <= max) {
    middle = Math.floor((min + max) / 2);
    console.log(array[middle])
    if (array[middle].id === targetNumber) {
      console.log("hit!", array[middle]);
      return true;
    } else if (array[middle].id < targetNumber) {
      min = middle + 1;
    } else if (array[middle].id > targetNumber) {
      max = middle - 1;
    }
  }
  return false;
}

const targetNum = 6;
const isCheck: boolean = binarySearch(datas, targetNum);
console.log(isCheck);
