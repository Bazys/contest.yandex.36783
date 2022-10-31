function getCardCount(n, k, cards) {
  var sum = cards.reduce((partialSum, a) => partialSum + a, 0);
  var max = sum;
  for (var i = k - 1; i >= 0; i--) {
    sum -= cards[i];
    sum += cards[n - k + i];
    max = Math.max(max, sum);
  }
  return max;
}


const _readline = require('readline');

const _reader = _readline.createInterface({
  input: process.stdin
});

const _inputLines = [];
let _curLine = 0;

_reader.on('line', line => {
  _inputLines.push(line);
});

process.stdin.on('end', solve);


function solve() {
  const n = readInt();
  const k = readInt();
  const cards = readArray();
  const ans = getCardCount(n, k, cards);
  console.log(ans);
}

function readInt() {
  const n = Number(_inputLines[_curLine]);
  _curLine++;
  return n;
}

function readArray() {
  var arr = _inputLines[_curLine].trim(" ").split(" ").map(num => Number(num));
  _curLine++;
  return arr;
}
